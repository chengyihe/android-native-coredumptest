LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := CoredumpTest.cpp
LOCAL_STATIC_LIBRARIES += \
	libcutils \
	libutils \
	liblog

LOCAL_MODULE := coredumptest
LOCAL_MODULE_TAGS := optional

include $(BUILD_EXECUTABLE)
