#ifndef ANDROID_PACKET_CAPTURE_PROXY_H
#define ANDROID_PACKET_CAPTURE_PROXY_H

#include "Interface/IPacketCapture.h"
#include <binder/IBinder.h>
#include <utils/Errors.h>

namespace android {

	class PacketCaptureProxy:public IPacketCapture
	{
		public:

		PacketCaptureProxy();

		~PacketCaptureProxy();

		packetdata *getDataPacketToIP (const char *ip) ;

		packetdata *getDataPacketFromIP (const char *ip) ;

		packetdata *getDataPacketWithPortNumber(const char *port);

		packetdata *getDataPacketWithTCPProtocol();

		packetdata *getDataPacketWithUDPProtocol();

	private:
		packetdata *p;
		sp<IBinder> binder;
		status_t status;
		void initState();
	};

}; // namespace android

#endif // ANDROID_PACKET_CAPTURE_PROXY_H