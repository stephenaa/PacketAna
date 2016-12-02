/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PacketObject.h
 * Author: stephenaaskov
 *
 * Created on 27. november 2016, 22:13
 */

#ifndef PACKETOBJECT_H
#define PACKETOBJECT_H

#include <iostream>
#include <memory>
#include <netinet/if_ether.h>

class PacketObject {

public:
    PacketObject(const u_char* packet, uint32_t len);
    PacketObject(const PacketObject& orig) = delete;
    virtual ~PacketObject();
    virtual std::string toString() const { return std::string("PacketObject"); }

protected:
    std::unique_ptr<u_char> m_packet;
    //const u_char* m_packet;
    const ether_header* m_eth;
};



#endif /* PACKETOBJECT_H */

