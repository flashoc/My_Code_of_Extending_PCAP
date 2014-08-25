package com.android.server;

import android.os.RemoteException;
import android.util.Log;
import android.content.Context;
import android.app.IPacketCaptureService;

public class PacketCaptureService extends IPacketCaptureService.Stub {

	// static {
 //        System.loadLibrary("packetcap");
 //    }

	private final Context mContext;
	private static final String TAG = "PacketCaptureService";

	public PacketCaptureService(Context context) {
        mContext = context;
    }
	
	@Override
	public byte[] getPacketToIP(String ip) throws RemoteException {
		// TODO Auto-generated method stub
		return getDataPacketToIP(ip);
	}

	@Override
	public byte[] getPacketFromIP(String ip) throws RemoteException {
		// TODO Auto-generated method stub
		return getDataPacketFromIP(ip);
	}

	@Override
	public byte[] getPacketWithPortNumber(String port) throws RemoteException {
		// TODO Auto-generated method stub
		return getDataPacketWithPortNumber(port);
	}

	@Override
	public byte[] getPacketWithTCPProtocol() throws RemoteException {
		// TODO Auto-generated method stub
		Log.e(TAG, "stub.getPacketWithTCPProtocol()");
		return getDataPacketWithTCPProtocol();
	}

	@Override
	public byte[] getPacketWithUDPProtocol() throws RemoteException {
		// TODO Auto-generated method stub
		return getDataPacketWithUDPProtocol();
	}

	private native final byte[] getDataPacketToIP(String ip);
    
	private native final byte[] getDataPacketFromIP(String ip);

	private native final byte[] getDataPacketWithPortNumber(String port);

	private native final byte[] getDataPacketWithTCPProtocol();

	private native final byte[] getDataPacketWithUDPProtocol();

}
