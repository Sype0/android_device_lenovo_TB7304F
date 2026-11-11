# AOKP Oreo
AOKP Oreo (Android 8.1) for the Lenovo Tab 7 Essential TB-7304F, built from the `oreo` branch of the AOKP manifest with the device tree of the [`oreo-roms`](https://github.com/Sype0/android_device_lenovo_TB7304F/tree/oreo-roms) branch ([build run](https://github.com/Sype0/android_device_lenovo_TB7304F/actions/runs/43082877540)).

**Not tested on the device yet.** It uses the same device tree, stock 4.4.22 kernel and libhwbinder patches as LineageOS 15.1 build 6, so the same issues are to be expected: the camera does not work, the Bluetooth HAL uses the default address of the chip, SELinux is permissive.

LineageOS has backported security fixes to its 15.1 apps that need framework APIs this ROM does not have. Those apps are held at an older LineageOS commit or have the change reverted, see `manifests/aokp.xml` and `patches-aokp/` on the `oreo-roms` branch.

**Installing**
Flash the zip from TWRP and format data when coming from stock or from another ROM or Android version. The `boot.img` inside the zip already carries the MediaTek headers the bootloader needs; the separate `boot.img` is the same image. If it does not boot, the logs are kept in `/cache/bootlog`.
