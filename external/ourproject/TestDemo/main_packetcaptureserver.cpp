#define LOG_TAG "PacketCaptureServer"
#include <utils/Log.h>
#include "PacketCaptureService/PacketCaptureService.h"
#include <binder/ProcessState.h>
#include <binder/IPCThreadState.h>
#include <binder/IServiceManager.h>

using namespace android;

int main(int arg, char** argv)
{
	sp<ProcessState> proc(ProcessState::self());
	sp<IServiceManager> sm = defaultServiceManager();
	LOGE("ServiceManager: %p", sm.get());
	PacketCaptureService::instantiate();
	ProcessState::self()->startThreadPool();
	IPCThreadState::self()->joinThreadPool();
	return 0;
}