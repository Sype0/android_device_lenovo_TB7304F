LOCAL_PATH := $(call my-dir)

ifeq ($(TARGET_DEVICE),TB7304F)
include $(call all-makefiles-under,$(LOCAL_PATH))
endif
