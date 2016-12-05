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


typedef struct {
    uint8_t ver_IHL;
    uint8_t DSCP_ECN;
    uint16_t length;
    uint16_t identification;
    uint16_t flagsAndOffset;
    uint8_t TTL;
    uint8_t protocol;
    uint16_t headerChecksum;
    uint32_t source;
    uint32_t destination;
} __attribute__((packed)) IPv4Header;


class IPv4Packet : public PacketObject {
    
public:
    IPv4Packet(const u_char* packet, uint32_t len);
    virtual ~IPv4Packet();
    PACKET_TYPES getType() const { return m_type; }
    virtual std::string toString() const; // const { return std::string("IPv4Packet"); }
private:
    PACKET_TYPES m_type;
    IPv4Header* m_header;
};

#endif /* IPV4PACKET_H */

