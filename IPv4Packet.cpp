/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IPv4Packet.cpp
 * Author: saaskov
 * 
 * Created on November 30, 2016, 1:43 PM
 */

#include "IPv4Packet.h"
#include <arpa/inet.h>


uint16_t hashAdd8(uint16_t hashVal, uint8_t* pValue)
{
    hashVal = hashVal ^ ( (hashVal << 3) | *pValue);
    return hashVal;
}

uint16_t hashAdd16(uint16_t hashVal, uint16_t* pValue)
{
    hashVal = hashVal ^ ( (hashVal << 3) | (*pValue >> 8));
    hashVal = hashVal ^ ( (hashVal << 3) | (*pValue & 0x0f));
    return hashVal;
}

uint16_t hashAdd32(uint16_t hashVal, uint32_t* pValue)
{   
    uint8_t* p = (uint8_t*) pValue;
    hashVal = hashVal ^ ( (hashVal << 3) | (*pValue++) );
    hashVal = hashVal ^ ( (hashVal << 3) | (*pValue++) );
    hashVal = hashVal ^ ( (hashVal << 3) | (*pValue++) );
    hashVal = hashVal ^ ( (hashVal << 3) | (*pValue++) );
    return hashVal;
}


IPv4Packet::IPv4Packet(const u_char* packet, uint32_t len) : 
    PacketObject(packet, len),m_type(PACKET_TYPES::IPV4)
{
   // std::cout <<  "IPv4. " << std::hex << ntohs(m_eth->ether_type)  << std::dec << std::endl;
    m_header = (IPv4Header*)((u_char *)m_packet.get() + sizeof(ether_header));
}
IPv4Packet::~IPv4Packet() {
}

std::string IPv4Packet::toString() const
{    
    //IPv4Header* pkt = (IPv4Header*) m_packet.get();
    printf("Ethertype: 0x%x\n", ntohs(m_eth->ether_type));
    printf("**** 0X%x\n", m_header->ver_IHL);
    std::cout << "Pkt:" << std::hex << (int)m_header->ver_IHL << std::endl;
    return std::string("IPv4Packet");
}