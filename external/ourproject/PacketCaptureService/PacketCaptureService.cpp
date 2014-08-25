#define LOG_TAG "PacketCaptureService"
#include <utils/Log.h>

#include "PacketCaptureService.h"
#include "PacketCaptureStub.h"
#include <binder/IServiceManager.h>
#include <binder/Parcel.h>
#include "Utils/MyEnum.h"
#include <stdlib.h>


namespace android {

	void PacketCaptureService::instantiate() {
		defaultServiceManager()->addService(
			String16("packet.capture"), new PacketCaptureService());
	}

	PacketCaptureService::PacketCaptureService()
	{
		cpstub = new PacketCaptureStub();
		LOGV("PacketCaptureService created");
	}

	PacketCaptureService::~PacketCaptureService()
	{
		delete cpstub;
		LOGV("PacketCaptureService destroyed");
	}

	status_t PacketCaptureService::onTransact(
		uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags)
	{
		packetdata *p = NULL;
		const char *ip = NULL;
		const char*port = NULL;

		switch (captureTypes(code)) {
			case GETDATAPACKETTOIP:
				ip = data.readCString();
				p = cpstub->getDataPacketToIP(ip);
			break;

			case GETDAtAPACKETFROMIP: 
				ip = data.readCString();
				p = cpstub->getDataPacketFromIP(ip);
			break;

			case GETDAtAPACKETWITHPORTNUMBER:
				port = data.readCString();
				p = cpstub->getDataPacketWithPortNumber(port);
			break;

			case GETDAtAPACKETWITHTCPPROTOCOL:
				p = cpstub->getDataPacketWithTCPProtocol();
			break;

			case GETDAtAPACKETWITHUDPPROTOCOL:
				p = cpstub->getDataPacketWithUDPProtocol();
			break;

			default:
			return UNKNOWN_TRANSACTION;
		}
		status_t status;
		status = reply->writeInt32(p->length);

		if (status != NO_ERROR){
			printf("write length of data fail,the errno=%d\n",errno);
			exit(errno);
		}

		status = reply->write(p->data, p->length);
		if (status != NO_ERROR){
			printf("write data fail,the errno=%d\n",errno);
			exit(errno);
		}

		return NO_ERROR;
	}
}; // namespace android