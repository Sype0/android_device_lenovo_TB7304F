# LineageOS 15.1 device tree for Lenovo Tab 7 Essential (TB-7304F)

Work in progress, not tested on the device yet. The `cm-14.1` branch boots
and works.

MediaTek MT8167, 600x1024, Wi-Fi only. Uses the stock 4.4.22 kernel as a
prebuilt because there is no kernel source for this board, and the stock
Android 7.0 blobs (`TB-7304F_S000060_171019_ROW`) in `proprietary/`.

- The stock kernel has neither the hwbinder device nor scatter-gather binder
  transactions, both of which HIDL depends on. `patches/` makes libhwbinder
  do without them: the buffers travel in the transaction data and are fixed
  up by the receiver, and hwservicemanager is a service of servicemanager.
  `/dev/hwbinder` and `/dev/vndbinder` are links to `/dev/binder`.
- The libraries in `shims/` are injected into the blobs that still call
  symbols that changed since Android 7.0.
- The audio HAL is loaded into audioserver and the codecs are reached over
  binder, as on 7.x.
- All stock daemons run in a single permissive SELinux domain and the kernel
  command line sets SELinux to permissive.
- The logs of every boot are kept in `/cache/bootlog`.
- The bootloader needs MediaTek headers on the kernel and ramdisk, which
  `tools/mtk_header.py` adds to the `boot.img` the build produces. The GitHub
  Actions workflow does that and puts the result into the flashable zip.

Install the zip from TWRP and format data when coming from stock.
