#define LOG_TAG "PacketCaptureStub"
#include <utils/Log.h>
#include <PacketCaptureStub.h>
#define CAPTURENUM 1

namespace android {

	PacketCaptureStub::PacketCaptureStub()
	{
		LOGV("PacketCaptureStub created");
	}

	PacketCaptureStub::~PacketCaptureStub()
	{
		LOGV("PacketCaptureStub destroyed");
	}

	packetdata * PacketCaptureStub::getDataPacketToIP(const char *ip){
		
		char str[25]="dst host ";
		strcat(str,ip);
		p = capture(getPacket,str,CAPTURENUM);
		return p;
	}

	packetdata * PacketCaptureStub::getDataPacketFromIP(const char *ip){
		char str[25]="src host ";
		strcat(str,ip);
		p = capture(getPacket,str,CAPTURENUM);
		return p;
	}

	packetdata * PacketCaptureStub::getDataPacketWithPortNumber(const char *port){
		char str[11]="port ";
		strcat(str,port);
		p = capture(getPacket,str,CAPTURENUM);
		return p;
	}

	packetdata * PacketCaptureStub::getDataPacketWithTCPProtocol(){
		char str[]="tcp";
		p = capture(getPacket,str,CAPTURENUM);
		return p;
	}

	packetdata * PacketCaptureStub::getDataPacketWithUDPProtocol(){
		char str[]="udp";
		p = capture(getPacket,str,CAPTURENUM);
		return p;
	}

};// namespace android