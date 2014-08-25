#ifndef ANDROID_PACKET_CAPTURE_SERVICE_H
#define ANDROID_PACKET_CAPTURE_SERVICE_H

#include <binder/Binder.h>

namespace android {

	class IPacketCapture;
	class PacketCaptureService:public BBinder

	{

	public:

		PacketCaptureService();
		~PacketCaptureService();
		static void instantiate();

	private:
		IPacketCapture *cpstub;
	protected:

    status_t    onTransact( uint32_t code,
                                    const Parcel& data,
                                    Parcel* reply,
                                    uint32_t flags = 0);

	};

}; // namespace android

#endif // ANDROID_PACKET_CAPTURE_SERVICE_H