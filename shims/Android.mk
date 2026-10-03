LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_SRC_FILES := mtk_ui.cpp
LOCAL_SHARED_LIBRARIES := libui
LOCAL_MODULE := libmtk_symbols
LOCAL_MODULE_TAGS := optional
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SRC_FILES := mtk_ifc.c
LOCAL_MODULE := libmtk_ifc
LOCAL_MODULE_TAGS := optional
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SRC_FILES := mtk_gui.cpp
LOCAL_SHARED_LIBRARIES := libgui libui libutils
LOCAL_MODULE := libmtk_gui
LOCAL_MODULE_TAGS := optional
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SRC_FILES := mtk_icu.cpp
LOCAL_SHARED_LIBRARIES := libicuuc
LOCAL_MODULE := libmtk_icu
LOCAL_MODULE_TAGS := optional
include $(BUILD_SHARED_LIBRARY)
