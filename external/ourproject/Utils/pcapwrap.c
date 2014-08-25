#include "pcapwrap.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>

typedef struct IpHeader//IP头
{
	u_char ver_headLength;
	u_char tos;
	u_short totallen;
	u_short identification;
	u_short flags_offset;
	u_char ttl;
	u_char proto;
	u_short headChecksum;
	struct in_addr sourAddr;
	struct in_addr destAddr;
}IpHeader;

packetdata *p = NULL;
extern char * Proto[];

// char** getDataPacketFromIPAndPort (char *ip, char *port, int num)
// {
// 	char str[100]="src host ";
// 	char *and=" and src port ";
// 	strcat(str,ip);
// 	strcat(str and);
// 	strcat(str,port);
// 	return capture(getPacket,str,num);
// }

// char** getDataPacketFromIPToIP (char *srcip, char *dstip,int num)
// {
// 	char str[100]="src host ";
// 	char *and=" and dst host ";
// 	strcat(str,srcip);
// 	strcat(str,and);
// 	strcat(str,dstip);
// 	return capture(getPacket,str,num);
// }

packetdata *capture(pcap_handler getPacket,char * str,int num)
{
	p = (packetdata *)malloc(HL_LEN);
	int id=0;
	char errBuf[PCAP_ERRBUF_SIZE],*devStr;
	struct bpf_program filter;
	const u_char *packet;
	struct pcap_pkthdr header;

	devStr=pcap_lookupdev(errBuf);
	if (devStr == NULL) {
		fprintf(stderr, "Couldn't find default device: %s\n", errBuf);
		exit(1);
	}
	printf("Device: %s is found\n", devStr);	
	pcap_t *device = pcap_open_live(devStr,65536,1,0,errBuf);
	if (device == NULL) {
		fprintf(stderr, "Couldn't open device %s: %s\n", devStr, errBuf);
		exit(1);
	}
	if (pcap_compile(device, &filter, str, 1, 0) == -1)
	{
		fprintf(stderr, "Couldn't parse filter %s: %s\n", str, pcap_geterr(device));
		exit(1);
	}

	if(pcap_setfilter(device,  &filter) == -1)
	{
		fprintf(stderr, "Couldn't install filter %s: %s\n", str, pcap_geterr(device));
		exit(1);
	}
	// pcap_loop(device,num,getPacket,(u_char *)&id);
	packet = pcap_next(device, &header);
	p->length = header.caplen;
	p->data = packet;
	pcap_close(device);

	//only for test
	getPacket((u_char *)&id, &header, packet);

	return p;
}

void getPacket(u_char *arg,const struct pcap_pkthdr *pkthdr,const u_char *packet)//抓包回调函数
{
	int *id=(int *)arg;
	printf("Id: %d\n",++(*id));
	printf("Packet length: %d\n",pkthdr->len);
	printf("Recieved time: %s",ctime((const time_t *)&pkthdr->ts.tv_sec));
	// p->length = pkthdr->caplen;
	// p->data = packet;
	protoAnalyse(packet,pkthdr);
}

void protoAnalyse(const u_char *packet,const struct pcap_pkthdr *pkthdr)
{
	const u_char *data=packet;
	u_short eth_proto=ntohs(*((short *)(data+12)));//以太头中的协议号
	int i;
	if(eth_proto==0x0800)//IPv4
	{
		short proto=(int)(*(data+23));//IP头中的协议号
		IpHeader *ipheader=(IpHeader *)(data+14);
		printf("The source IP address is %s\n",inet_ntoa(ipheader->sourAddr));//source IP address
		printf("The destination IP address is %s\n",inet_ntoa(ipheader->destAddr));//destination IP address
		printf("The protocal is %s\n",Proto[proto]);
		showdata(pkthdr,packet);
	}
	else if(eth_proto==0x86dd)//IPv6
	{
		printf("The protocal is IPv6\n");
		showdata(pkthdr,packet);
	}
	else if(eth_proto==0x806)//ARP
	{
		printf("The protocal is ARP\n");
		showdata(pkthdr,packet);
	}
	else{
		showdata(pkthdr,packet);
	}
	//printf("\n\n");
}

void showdata(const struct pcap_pkthdr *pkthdr,const u_char *packet)//输出原始数据的函数
{
	bpf_u_int32 i;
	printf("The original data:\n");
	for(i=0;i<pkthdr->len;i++)
	{
		printf("%02X",packet[i]);
		if((i+1)%20==0)
		{
			printf("\n");
		}
	}
	printf("\n");
}
