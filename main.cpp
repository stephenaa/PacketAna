/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: stephenaaskov
 *
 * Created on 27. november 2016, 21:49
 */

#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/if_ether.h>
#include <netinet/tcp.h>
#include <netinet/ip.h>
#include <string.h>

#include <cstdlib>
#include "PacketAnalyzer.h"

using namespace std;


void callback(u_char *useless,const struct pcap_pkthdr* pkthdr,const u_char*
        packet)
{
  static int count = 1;

  printf("\nPacket number [%d], length of this packet is: %d\n", count++, pkthdr->len);
  PacketAnalyzer::getInstance()->getObject(pkthdr, packet);
}


/*
 * 
 */
int main(int argc, char** argv) {
    pcap_t *pcap;
    const unsigned char *packet;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct pcap_pkthdr header;
        
    pcap = pcap_open_offline("/Users/stephenaaskov/capture1.pcap", errbuf);
    if (pcap == NULL)
    {
        fprintf(stderr, "error reading pcap file: %s\n", errbuf);
        exit(1);
    }

    pcap_loop(pcap, 10, callback, NULL);
   
    return 0;
}

