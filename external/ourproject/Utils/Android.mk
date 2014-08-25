LOCAL_PATH:=$(call my-dir)
include $(CLEAR_VARS)
LOCAL_SRC_FILES:=\
	proto.c\
	pcapwrap.c

LOCAL_C_INCLUDES += \
	external/libpcap\
	external/ourproject

LOCAL_SHARED_LIBRARIES:=libpcap
LOCAL_MODULE_TAGS:=optional
LOCAL_MODULE:=libpcapwrap
LOCAL_PRELINK_MODULE:=false
include $(BUILD_SHARED_LIBRARY)