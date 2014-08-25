LOCAL_PATH:=$(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES:=PacketCaptureProxy.cpp
LOCAL_SHARED_LIBRARIES:=libutils libbinder libpcapwrap

LOCAL_C_INCLUDES += \
	external/libpcap\
	external/ourproject
			
LOCAL_MODULE_TAGS:=optional
LOCAL_MODULE:=libcaptureproxy
LOCAL_PRELINK_MODULE:=false
include $(BUILD_SHARED_LIBRARY)
