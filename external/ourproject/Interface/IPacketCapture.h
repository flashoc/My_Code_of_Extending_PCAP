#ifndef ANDROID_IPACKET_CAPTURE_H
#define ANDROID_IPACKET_CAPTURE_H

#include "Utils/pcapwrap.h"

namespace android {

	class IPacketCapture
	{

	public:

		IPacketCapture(){};

		virtual packetdata *getDataPacketToIP (const char *ip) = 0;

		virtual packetdata *getDataPacketFromIP (const char *ip) = 0;

		virtual packetdata *getDataPacketWithPortNumber(const char *port)= 0;

		virtual packetdata *getDataPacketWithTCPProtocol()= 0;

		virtual packetdata *getDataPacketWithUDPProtocol()= 0;

		virtual ~IPacketCapture(){};

	private:

	};

};// namespace android

#endif // ANDROID_IPACKET_CAPTURE_H
