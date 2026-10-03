LOCAL_PATH := $(call my-dir)

ifeq ($(TARGET_DEVICE),TB7304F)

# There is no kernel source to install headers from; the modules that ask for
# them build against the headers of bionic
.PHONY: INSTALLED_KERNEL_HEADERS
INSTALLED_KERNEL_HEADERS:

include $(call all-makefiles-under,$(LOCAL_PATH))
endif
