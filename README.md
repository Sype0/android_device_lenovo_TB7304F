# LineageOS 14.1 device tree for Lenovo Tab 7 Essential (TB-7304F)

Work in progress, not booting yet.

MediaTek MT8167, 600x1024, Wi-Fi only. Uses the stock 4.4.22 kernel as a
prebuilt because there is no kernel source for this board, and the stock
Android 7.0 blobs (`TB-7304F_S000060_171019_ROW`) in `proprietary/`.

- `libmtk_symbols` is injected into the blobs that still call symbols that
  changed between Android 7.0 and 7.1.
- All stock daemons run in a single permissive SELinux domain and the kernel
  command line sets SELinux to permissive.
- The logs of every boot are kept in `/cache/bootlog`.
- The bootloader needs MediaTek headers on the kernel and ramdisk, which
  `tools/mtk_header.py` adds to the `boot.img` the build produces. The GitHub
  Actions workflow does that and puts the result into the flashable zip.

Install the zip from TWRP and format data when coming from stock.
