/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PacketAnalyzer.h
 * Author: stephenaaskov
 *
 * Created on 27. november 2016, 22:04
 */

#ifndef PACKETANALYZER_H
#define PACKETANALYZER_H

#include <sys/types.h>

#include "PacketAnalyzer.h"
#include "PacketObject.h"

enum class PACKET_TYPES : unsigned int {
    IPV4 = 0x0800,
    ARP = 0x0806,            
    IPV6 = 0x86dd,
};



class PacketAnalyzer {
public:
    PacketAnalyzer(const PacketAnalyzer& orig) = delete;
    static PacketAnalyzer* getInstance();
    PacketObject* getObject(const struct pcap_pkthdr* pkthdr, const u_char* packet);
    
private:
    static PacketAnalyzer* m_instance;
    PacketAnalyzer();
    virtual ~PacketAnalyzer();
};

#endif /* PACKETANALYZER_H */

