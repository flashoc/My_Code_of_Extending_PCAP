LOCAL_PATH:=$(call my-dir)

include $(CLEAR_VARS)
LOCAL_SRC_FILES:=main_packetcaptureserver.cpp

LOCAL_C_INCLUDES += \
	external/libpcap\
	external/ourproject

LOCAL_SHARED_LIBRARIES:=libutils libbinder libcaptureservice
LOCAL_MODULE_TAGS:=optional
LOCAL_MODULE:=packetcaptureserver
include $(BUILD_EXECUTABLE)

#include $(CLEAR_VARS)
#LOCAL_SRC_FILES:=client.cpp

#LOCAL_C_INCLUDES += \
#	external/libpcap\
#	external/ourproject

#LOCAL_SHARED_LIBRARIES:=libcaptureproxy libpcapwrap
#LOCAL_MODULE_TAGS:=optional
#LOCAL_MODULE:=client
#include $(BUILD_EXECUTABLE)
