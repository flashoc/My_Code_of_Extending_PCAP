package android.app;

interface IPacketCaptureService {
    byte[] getPacketToIP( in String ip );
    byte[] getPacketFromIP( in String ip );
    byte[] getPacketWithPortNumber( in String port );
    byte[] getPacketWithTCPProtocol( );
    byte[] getPacketWithUDPProtocol( );
}