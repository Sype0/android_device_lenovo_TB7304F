# Inherit from those products. Most specific first.
$(call inherit-product, $(SRC_TARGET_DIR)/product/core_64_bit.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/full_base.mk)

# Inherit from TB7304F device
$(call inherit-product, device/lenovo/TB7304F/device.mk)

# Inherit some common LineageOS stuff.
$(call inherit-product, vendor/cm/config/common_full_tablet_wifionly.mk)

PRODUCT_DEVICE := TB7304F
PRODUCT_NAME := lineage_TB7304F
PRODUCT_BRAND := Lenovo
PRODUCT_MODEL := Lenovo TB-7304F
PRODUCT_MANUFACTURER := LENOVO
