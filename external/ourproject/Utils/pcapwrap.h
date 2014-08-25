#ifndef pcap_wrap_h
#define pcap_wrap_h

#include <pcap.h>
#define HL_LEN sizeof(struct packetstruct)

#ifdef __cplusplus
extern "C" {
#endif
	typedef struct packetstruct packetdata;
	struct packetstruct
	{
		size_t length;
		const u_char *data;
	};

	extern packetdata *capture(pcap_handler getPacket,char *str,int num);
	extern void getPacket(u_char *arg,const struct pcap_pkthdr *pkthdr,const u_char *packet);//抓包回调函数
	extern void protoAnalyse(const u_char *packet,const struct pcap_pkthdr *pkthdr);
	extern void showdata(const struct pcap_pkthdr *pkthdr,const u_char *packet);

#ifdef __cplusplus
}
#endif

#endif // pcap_wrap_h
