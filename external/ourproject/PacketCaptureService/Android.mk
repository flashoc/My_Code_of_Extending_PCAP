LOCAL_PATH:=$(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES:= PacketCaptureService.cpp\
	PacketCaptureStub.cpp

LOCAL_C_INCLUDES += \
	external/libpcap\
	external/ourproject

LOCAL_SHARED_LIBRARIES := libutils libbinder libpcapwrap

LOCAL_MODULE_TAGS:=optional
LOCAL_MODULE:= libcaptureservice
LOCAL_PRELINK_MODULE:=false

include $(BUILD_SHARED_LIBRARY)
