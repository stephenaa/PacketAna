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

#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/if_ether.h>
#include <netinet/tcp.h>
#include <netinet/ip.h> 
#include <wordexp.h>
#include <string.h>
#include <pcap.h>

#include "PacketAnalyzer.h"

using namespace std;


/**
 * Callback passed to libpcap. Simply forward packet to the packet analyzer.
 * @param useless
 * @param pkthdr
 * @param packet
 */
void callback(u_char *useless,const struct pcap_pkthdr* pkthdr,const u_char*
        packet)
{
  PacketAnalyzer::getInstance()->getObject(pkthdr, packet);  
}


void usage()
{
    std::cout << "PacketAnayzer" << std::endl;    
}


/*
 * 
 */
int main(int argc, char** argv) {
    pcap_t *pcap = NULL;
    const unsigned char *packet;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct pcap_pkthdr header;

    
    argv[1] = strdup ("~/capture.pcap");
    argc = 2;
    
    if (argc < 1)
    {
        usage();
    }
    
    wordexp_t exp_result;
    wordexp(argv[1], &exp_result, 0);
    std::cout << "Reading: " << exp_result.we_wordv[0] << std::endl;
    pcap = pcap_open_offline(exp_result.we_wordv[0], errbuf);
    wordfree(&exp_result);
        
    if (pcap == NULL)
    {
        cerr << "error reading pcap file:" << errbuf << std::endl;
        exit(1);
    }
    else 
    {
        pcap_loop(pcap, 10, callback, NULL);
    }
    
    return 0;
}

