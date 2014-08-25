#define LOG_TAG "PacketCapture-JNI"
#include <utils/Log.h>

#include "jni.h"
#include "JNIHelp.h"
#include "PacketCaptureProxy/PacketCaptureProxy.h"

namespace android {

	jbyteArray Java_com_example_packetcapture_PacketCap_getDataPacketToIP
	(JNIEnv *env, jobject obj, jstring ipStr){
		const char *str = env->GetStringUTFChars(ipStr, NULL);
		LOGE("the instruction is  %s", str);
		IPacketCapture *proxy = new PacketCaptureProxy();

		packetdata *p = NULL;
		p = proxy->getDataPacketToIP(str);

		jbyteArray byteArray = NULL;
		byteArray = env->NewByteArray(p->length);
		if (byteArray)
            env->SetByteArrayRegion(byteArray, 0, p->length, (jbyte *)p->data);

		return byteArray;
	}

	jbyteArray Java_com_example_packetcapture_PacketCap_getDataPacketFromIP
	(JNIEnv *env, jobject obj, jstring ipStr){
		IPacketCapture *proxy = new PacketCaptureProxy();
		const char *str = env->GetStringUTFChars(ipStr, NULL);
		LOGE("the instruction is  %s", str);

		packetdata *p = NULL;
		p = proxy->getDataPacketFromIP(str);

		jbyteArray byteArray = NULL;
		byteArray = env->NewByteArray(p->length);
		if (byteArray)
            env->SetByteArrayRegion(byteArray, 0, p->length, (jbyte *)p->data);

		return byteArray;
	}

	jbyteArray Java_com_example_packetcapture_PacketCap_getDataPacketWithPortNumber
	(JNIEnv *env, jobject obj, jstring portStr){
		IPacketCapture *proxy = new PacketCaptureProxy();
		const char *str = env->GetStringUTFChars(portStr, NULL);
		LOGE("the instruction is  %s", str);

		packetdata *p = NULL;
		p = proxy->getDataPacketWithPortNumber(str);

		jbyteArray byteArray = NULL;
		byteArray = env->NewByteArray(p->length);
		if (byteArray)
            env->SetByteArrayRegion(byteArray, 0, p->length, (jbyte *)p->data);

		return byteArray;
	}

	jbyteArray Java_com_example_packetcapture_PacketCap_getDataPacketWithTCPProtocol
	(JNIEnv *env, jobject obj){
		IPacketCapture *proxy = new PacketCaptureProxy();
		
		LOGE("the instruction is tcp");

		packetdata *p = NULL;
		p = proxy->getDataPacketWithTCPProtocol();

		jbyteArray byteArray = NULL;
		byteArray = env->NewByteArray(p->length);
		if (byteArray)
            env->SetByteArrayRegion(byteArray, 0, p->length, (jbyte *)p->data);

		return byteArray;
	}

	jbyteArray Java_com_example_packetcapture_PacketCap_getDataPacketWithUDPProtocol
	(JNIEnv *env, jobject obj){
		IPacketCapture *proxy = new PacketCaptureProxy();
		
		LOGE("the instruction is udp");

		packetdata *p = NULL;
		p = proxy->getDataPacketWithUDPProtocol();

		jbyteArray byteArray = NULL;
		byteArray = env->NewByteArray(p->length);
		if (byteArray)
            env->SetByteArrayRegion(byteArray, 0, p->length, (jbyte *)p->data);

		return byteArray;
	}

	static JNINativeMethod sMethods[] = {
     /* name, signature, funcPtr */
		{"getDataPacketToIP", "(Ljava/lang/String;)[B", (void*)Java_com_example_packetcapture_PacketCap_getDataPacketToIP},
		{"getDataPacketFromIP", "(Ljava/lang/String;)[B", (void*)Java_com_example_packetcapture_PacketCap_getDataPacketFromIP},
		{"getDataPacketWithPortNumber", "(Ljava/lang/String;)[B", (void*)Java_com_example_packetcapture_PacketCap_getDataPacketWithPortNumber},
		{"getDataPacketWithTCPProtocol", "()[B", (void*)Java_com_example_packetcapture_PacketCap_getDataPacketWithTCPProtocol},
		{"getDataPacketWithUDPProtocol", "()[B", (void*)Java_com_example_packetcapture_PacketCap_getDataPacketWithUDPProtocol},
	};

	int register_com_example_packetcapture_PacketCap(JNIEnv* env)
	{
		jclass clazz = env->FindClass("com/android/server/PacketCaptureService");

		if (clazz == NULL)
		{
			LOGE("Can't find com/android/server/PacketCaptureService");
			return -1;
		}

		return jniRegisterNativeMethods(env, "com/android/server/PacketCaptureService",
			sMethods, NELEM(sMethods));
	}

	// extern "C" jint JNI_OnLoad(JavaVM* vm, void* reserved)
	// {
	// 	LOGE("JNI_OnLoad");
	// 	JNIEnv* env = NULL;
	// 	jint result = -1;

	// 	if (vm->GetEnv((void**) &env, JNI_VERSION_1_4) != JNI_OK) {
	// 		LOGE("GetEnv failed!");
	// 		return result;
	// 	}
	// 	LOG_ASSERT(env, "Could not retrieve the env!");

	// 	register_com_example_packetcapture_PacketCap(env);
	// 	return JNI_VERSION_1_4;
	// }

} /* namespace android */
