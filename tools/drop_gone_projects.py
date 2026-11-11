#!/usr/bin/env python3
"""Leave out the projects of an old manifest whose repositories are gone.

Reads the log of a failed `repo sync`, finds the projects it could not fetch,
checks with `git ls-remote` that their repositories really do not exist any
more (and the failure was not just the network), and writes a local manifest
that removes them. Run from the top of the source tree.

    drop_gone_projects.py <sync log> <manifest URL>
"""
import os
import re
import subprocess
import sys
import urllib.parse
import xml.etree.ElementTree as ET

log, manifest_url = sys.argv[1], sys.argv[2]
out = ".repo/local_manifests/gone.xml"

full = subprocess.run(["repo", "manifest"], stdout=subprocess.PIPE, universal_newlines=True, check=True).stdout
root = ET.fromstring(full)
remotes = {r.get("name"): r.get("fetch") for r in root.iter("remote")}
default = root.find("default")
default_remote = default.get("remote") if default is not None else None

failed = set()
for line in open(log, errors="replace"):
    for m in re.finditer(r"Cannot fetch (\S+)|error: (\S+?): ", line):
        failed.add((m.group(1) or m.group(2)).rstrip(":"))

gone = set()
if os.path.exists(out):
    gone = set(re.findall(r'name="([^"]+)"', open(out).read()))

for p in root.iter("project"):
    name, path = p.get("name"), p.get("path") or p.get("name")
    if name not in failed and path not in failed:
        continue
    # A relative fetch URL is relative to the manifest repository
    fetch = urllib.parse.urljoin(manifest_url.rstrip("/"), remotes[p.get("remote") or default_remote])
    url = f"{fetch.rstrip('/')}/{name}"
    r = subprocess.run(["git", "ls-remote", url], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL,
                       env=dict(os.environ, GIT_TERMINAL_PROMPT="0"))
    if r.returncode != 0:
        print(f"Leaving out {name} ({path}), {url} is gone")
        gone.add(name)
    else:
        print(f"{name} exists, the failure was something else")

os.makedirs(os.path.dirname(out), exist_ok=True)
with open(out, "w") as f:
    f.write("<manifest>\n")
    for name in sorted(gone):
        f.write(f'  <remove-project name="{name}" />\n')
    f.write("</manifest>\n")
