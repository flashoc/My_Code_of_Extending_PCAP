#ifndef ANDROID_PACKET_CAPTURE_STUB_H
#define ANDROID_PACKET_CAPTURE_STUB_H

#include "Interface/IPacketCapture.h"

namespace android {

	class PacketCaptureStub: public IPacketCapture
	{
		public:

		PacketCaptureStub();

		~PacketCaptureStub();

		packetdata *getDataPacketToIP (const char *ip) ;

		packetdata *getDataPacketFromIP (const char *ip) ;

		packetdata *getDataPacketWithPortNumber(const char *port);

		packetdata *getDataPacketWithTCPProtocol();

		packetdata *getDataPacketWithUDPProtocol();

	private:
		packetdata *p;

	};

}; // namespace android

#endif // ANDROID_PACKET_CAPTURE_STUB_H