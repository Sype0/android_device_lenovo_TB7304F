DEVICE_PATH := device/lenovo/TB7304F

# Architecture
TARGET_ARCH := arm64
TARGET_ARCH_VARIANT := armv8-a
TARGET_CPU_ABI := arm64-v8a
TARGET_CPU_ABI2 :=
TARGET_CPU_VARIANT := cortex-a53

TARGET_2ND_ARCH := arm
TARGET_2ND_ARCH_VARIANT := armv7-a-neon
TARGET_2ND_CPU_ABI := armeabi-v7a
TARGET_2ND_CPU_ABI2 := armeabi
TARGET_2ND_CPU_VARIANT := cortex-a53

TARGET_USES_64_BIT_BINDER := true

# Bootloader
TARGET_NO_BOOTLOADER := true
TARGET_BOOTLOADER_BOARD_NAME := mt8167

# Platform
TARGET_BOARD_PLATFORM := mt8167
BOARD_HAS_MTK_HARDWARE := true
BOARD_USES_MTK_HARDWARE := true

# Kernel (stock 4.4.22, TB-7304F_S100017_200102_ROW): there is no kernel
# source for this board
TARGET_PREBUILT_KERNEL := $(DEVICE_PATH)/prebuilt/kernel
BOARD_KERNEL_BASE := 0x40078000
BOARD_KERNEL_CMDLINE := bootopt=64S3,32N2,64N2 androidboot.selinux=permissive
BOARD_KERNEL_PAGESIZE := 2048
# Stock loads the ramdisk at 0x44000000, but 0x44400000-0x44500000 is reserved
# for ram_console/pstore, so a ramdisk above 4 MiB has to go after that region.
BOARD_RAMDISK_OFFSET := 0x04488000
BOARD_KERNEL_TAGS_OFFSET := 0x0df88000
BOARD_MKBOOTIMG_ARGS += --ramdisk_offset $(BOARD_RAMDISK_OFFSET)
BOARD_MKBOOTIMG_ARGS += --tags_offset $(BOARD_KERNEL_TAGS_OFFSET)

# Partitions (from the stock scatter file)
BOARD_FLASH_BLOCK_SIZE := 131072
BOARD_BOOTIMAGE_PARTITION_SIZE := 16777216
# The LineageOS recovery does not fit the 16 MiB partition next to the 7.5 MiB
# kernel; it is never flashed (TWRP is used), so only let the build pass.
BOARD_RECOVERYIMAGE_PARTITION_SIZE := 33554432
BOARD_SYSTEMIMAGE_PARTITION_SIZE := 3548381184
BOARD_CACHEIMAGE_PARTITION_SIZE := 452984832
BOARD_USERDATAIMAGE_PARTITION_SIZE := 3323625472
BOARD_CACHEIMAGE_FILE_SYSTEM_TYPE := ext4
TARGET_USERIMAGES_USE_EXT4 := true

# Display
USE_OPENGL_RENDERER := true
NUM_FRAMEBUFFER_SURFACE_BUFFERS := 3
TARGET_RUNNING_WITHOUT_SYNC_FRAMEWORK := true
TARGET_FORCE_HWC_FOR_VIRTUAL_DISPLAYS := true

# Audio: the stock HAL is loaded into audioserver, as it was on 7.x
USE_XML_AUDIO_POLICY_CONF := 1
USE_LEGACY_LOCAL_AUDIO_HAL := true

# Bluetooth
BOARD_HAVE_BLUETOOTH := true
BOARD_BLUETOOTH_DOES_NOT_USE_RFKILL := true
BOARD_BLUETOOTH_BDROID_BUILDCFG_INCLUDE_DIR := $(DEVICE_PATH)/bluetooth

# Camera
TARGET_HAS_LEGACY_CAMERA_HAL1 := true

# Wi-Fi
BOARD_WLAN_DEVICE := MediaTek
WIFI_DRIVER_STATE_CTRL_PARAM := "/dev/wmtWifi"
WIFI_DRIVER_STATE_ON := 1
WIFI_DRIVER_STATE_OFF := 0
WPA_SUPPLICANT_VERSION := VER_0_8_X
BOARD_WPA_SUPPLICANT_DRIVER := NL80211
BOARD_WPA_SUPPLICANT_PRIVATE_LIB := lib_driver_cmd_mt66xx
BOARD_HOSTAPD_DRIVER := NL80211
BOARD_HOSTAPD_PRIVATE_LIB := lib_driver_cmd_mt66xx
WIFI_DRIVER_FW_PATH_PARAM := "/dev/wmtWifi"
WIFI_DRIVER_FW_PATH_STA := STA
WIFI_DRIVER_FW_PATH_AP := AP
WIFI_DRIVER_FW_PATH_P2P := P2P

# The stock blobs were built against Android 7.0, the shims carry the symbols
# that changed since
TARGET_LD_SHIM_LIBS := \
    /system/vendor/lib/libui_ext.so|libmtk_symbols.so \
    /system/vendor/lib64/libui_ext.so|libmtk_symbols.so \
    /system/vendor/lib/libcam.client.so|libmtk_symbols.so \
    /system/vendor/lib64/libcam.client.so|libmtk_symbols.so \
    /system/vendor/lib/libcam_utils.so|libmtk_symbols.so \
    /system/vendor/lib64/libcam_utils.so|libmtk_symbols.so \
    /system/vendor/lib/libmtk_mmutils.so|libmtk_symbols.so \
    /system/vendor/lib64/libmtk_mmutils.so|libmtk_symbols.so \
    /system/vendor/lib/libMtkOmxVenc.so|libmtk_symbols.so \
    /system/vendor/lib/libgui_ext.so|libmtk_gui.so \
    /system/vendor/lib/libaal.so|libmtk_gui.so \
    /system/vendor/lib/libcam.utils.sensorlistener.so|libsensor.so \
    /system/vendor/lib/libdrmmtkutil.so|libmtk_icu.so \
    /system/vendor/lib64/libgui_ext.so|libmtk_gui.so \
    /system/vendor/lib64/libaal.so|libmtk_gui.so \
    /system/vendor/lib64/libcam.utils.sensorlistener.so|libsensor.so \
    /system/vendor/lib64/libdrmmtkutil.so|libmtk_icu.so \
    /system/vendor/bin/thermalindicator|libmtk_gui.so \
    /system/vendor/bin/thermal|libmtk_ifc.so

# HIDL
DEVICE_MANIFEST_FILE := $(DEVICE_PATH)/manifest.xml

# SELinux
BOARD_SEPOLICY_DIRS += $(DEVICE_PATH)/sepolicy

# Properties
TARGET_SYSTEM_PROP += $(DEVICE_PATH)/system.prop

# Recovery
TARGET_RECOVERY_FSTAB := $(DEVICE_PATH)/rootdir/fstab.mt8167

# No kernel source: modules that depend on the kernel headers only need the
# directory to exist
ifeq ($(TARGET_DEVICE),TB7304F)
$(shell mkdir -p $(OUT_DIR)/target/product/TB7304F/obj/KERNEL_OBJ/usr)
endif

TARGET_OTA_ASSERT_DEVICE := TB7304F,TB-7304F
