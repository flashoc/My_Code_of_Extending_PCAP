#define LOG_TAG "PacketCaptureProxy"
#include <utils/Log.h>
#include "PacketCaptureProxy.h"
#include <binder/IServiceManager.h>
#include "Utils/MyEnum.h"
#include <binder/Parcel.h>
#include <stdlib.h>

namespace android {

	PacketCaptureProxy::PacketCaptureProxy()
	{
		initState();
		p = new packetdata;
		LOGV("PacketCaptureProxy created");
	}

	PacketCaptureProxy::~PacketCaptureProxy()
	{
		delete p;
		LOGV("PacketCaptureProxy destroyed");
	}

	packetdata * PacketCaptureProxy::getDataPacketToIP(const char *ip){
		
		Parcel data, reply;
		data.writeCString(ip);
		
		binder->transact(GETDATAPACKETTOIP, data, &reply, 0);
		size_t len = reply.readInt32();
		
		void *tmpdata = malloc(len);
		status = reply.read(tmpdata, len);

		if (status != NO_ERROR){
			printf("read data fail,the errno=%d\n",errno);
			exit(1);
		}

		p->length = len;
		p->data = (const u_char*)tmpdata;
		return p;
	}

	packetdata * PacketCaptureProxy::getDataPacketFromIP(const char *ip){
		Parcel data, reply;
		data.writeCString(ip);
		
		binder->transact(GETDAtAPACKETFROMIP, data, &reply, 0);
		size_t len = reply.readInt32();
		
		void *tmpdata = malloc(len);
		status = reply.read(tmpdata, len);

		if (status != NO_ERROR){
			printf("read data fail,the errno=%d\n",errno);
			exit(1);
		}

		p->length = len;
		p->data = (const u_char*)tmpdata;
		return p;
	}

	packetdata * PacketCaptureProxy::getDataPacketWithPortNumber(const char *port){
		Parcel data, reply;
		data.writeCString(port);
		
		binder->transact(GETDAtAPACKETWITHPORTNUMBER, data, &reply, 0);
		size_t len = reply.readInt32();
		
		void *tmpdata = malloc(len);
		status = reply.read(tmpdata, len);

		if (status != NO_ERROR){
			printf("read data fail,the errno=%d\n",errno);
			exit(1);
		}

		p->length = len;
		p->data = (const u_char*)tmpdata;
		return p;
	}

	packetdata * PacketCaptureProxy::getDataPacketWithTCPProtocol(){
		Parcel data, reply;
		
		binder->transact(GETDAtAPACKETWITHTCPPROTOCOL, data, &reply, 0);
		size_t len = reply.readInt32();

		void *tmpdata = malloc(len);
		status = reply.read(tmpdata, len);

		if (status != NO_ERROR){
			printf("read data fail,the errno=%d\n",errno);
			exit(1);
		}

		p->length = len;
		p->data = (const u_char*)tmpdata;
		return p;
	}

	packetdata * PacketCaptureProxy::getDataPacketWithUDPProtocol(){
		Parcel data, reply;
		
		binder->transact(GETDAtAPACKETWITHUDPPROTOCOL, data, &reply, 0);
		size_t len = reply.readInt32();
		
		void *tmpdata = malloc(len);
		status = reply.read(tmpdata, len);

		if (status != NO_ERROR){
			printf("read data fail,the errno=%d\n",errno);
			exit(1);
		}
		
		p->length = len;
		p->data = (const u_char*)tmpdata;
		return p;
	}

	void PacketCaptureProxy::initState(){
		sp<IServiceManager> sm = defaultServiceManager();
		do {
        	binder = sm->getService(String16("packet.capture"));
        	if (binder != NULL)
        		break;
        	LOGW("packet capture service not published, waiting...");
        	usleep(500000); 
        } while(true);
	}

};// namespace android