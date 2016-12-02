/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IPv4Packet.h
 * Author: saaskov
 *
 * Created on November 30, 2016, 1:43 PM
 */

#ifndef IPV4PACKET_H
#define IPV4PACKET_H

#include <iostream>
#include "PacketObject.h"
#include "PacketAnalyzer.h"


class IPv4Packet : public PacketObject {
    
public:
    IPv4Packet(const u_char* packet, uint32_t len);
    virtual ~IPv4Packet();
    PACKET_TYPES getType() const { return m_type; }
    virtual std::string toString() const { return std::string("IPv4Packet"); }
private:
    PACKET_TYPES m_type;

};

#endif /* IPV4PACKET_H */

