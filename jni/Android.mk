LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := rwProcMemTest

LOCAL_SRC_FILES := main.cpp

LOCAL_CPP_INCLUDES += $(LOCAL_PATH)/include \

include $(BUILD_EXECUTABLE)




