/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PacketAnalyzer.cpp
 * Author: stephenaaskov
 * 
 * Created on 27. november 2016, 22:04
 */
#include <string>
#include <netinet/if_ether.h>
#include <pcap.h>
#include "PacketAnalyzer.h"
#include <iostream>


static std::string getPacketTypeName(PACKET_TYPES type)
{
    switch (type) {
        case PACKET_TYPES::IPV4:
            return "IPv4";
            break;
        case PACKET_TYPES::ARP:
            return "ARP";
            break;
        case PACKET_TYPES::IPV6:
            return "IPv6";
            break;
    }
    return "N/A";
}

PacketAnalyzer* PacketAnalyzer::m_instance = nullptr;

PacketAnalyzer::PacketAnalyzer() {
}

PacketAnalyzer::~PacketAnalyzer() {
}

PacketAnalyzer* PacketAnalyzer::getInstance()
{
    if (!m_instance) {
        m_instance = new PacketAnalyzer();
    }
    
    return m_instance;
}

/**
 *  Factory method to return a packetobject representing the packet.
 */
PacketObject* PacketAnalyzer::getObject(const struct pcap_pkthdr* pkthdr, const u_char* packet)
{
 std::cout <<  "getObject" << std::endl;
 if (pkthdr->caplen > sizeof(ether_header) ) {
    ether_header* eth = (ether_header*)packet;
    std::cout << "Ethernet frame of type ox" << std::hex << ntohs(eth->ether_type) << std::dec; 
    switch ((PACKET_TYPES)ntohs(eth->ether_type)) {
        case PACKET_TYPES::IPV6:
            std::cout << "IPv6 packet" << std::endl;
            break;
        case PACKET_TYPES::IPV4:
            std::cout << "IPv4 packet" << std::endl;
            break;
        case PACKET_TYPES::ARP:
            std::cout << "ARP packet" << std::endl;
            break;


    }
 }
 return nullptr;
}
