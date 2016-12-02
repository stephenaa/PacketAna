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

IPv4Packet::IPv4Packet(const u_char* packet, uint32_t len) : 
    PacketObject(packet, len),m_type(PACKET_TYPES::IPV4)
{
    std::cout <<  "IPv4. " << std::hex << ntohs(m_eth->ether_type)  << std::dec << std::endl;
}

IPv4Packet::~IPv4Packet() {
}

