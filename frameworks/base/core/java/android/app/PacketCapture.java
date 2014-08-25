package android.app;

import android.os.RemoteException;

public class PacketCapture
{
	public static final String TAG = "PacketCapture";

	private final IPacketCaptureService mService;

    /**
     * package private on purpose
     */
    PacketCapture(IPacketCaptureService service) {
    	mService = service;
    }
    
    public byte[] getPacketDataToIP( String ip ) throws RemoteException {
    	return mService.getPacketToIP(ip);
    	
    }

    public  byte[] getPacketDataFromIP( String ip ) throws RemoteException {
    	
    	return mService.getPacketFromIP(ip);
    	
    }

    public byte[] getPacketDataWithPortNumber( String port ) throws RemoteException {
    	
    	return mService.getPacketWithPortNumber(port);
    	
    }
    
    public byte[] getPacketDataWithTCPProtocol() throws RemoteException {
    	
    	return mService.getPacketWithTCPProtocol();
    	
    }

    public byte[] getPacketDataWithUDPProtocol() throws RemoteException {
    	
    	return mService.getPacketWithUDPProtocol();
    	
    }
}
