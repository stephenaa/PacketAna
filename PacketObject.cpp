/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PacketObject.cpp
 * Author: stephenaaskov
 * 
 * Created on 27. november 2016, 22:13
 */

#include <iostream>
#include <cstdint>
#include <memory>
#include <string.h>
#include "PacketObject.h"

PacketObject::PacketObject(const u_char* packet, uint32_t len)  {
    
    m_packet.reset((u_char *)malloc(len));
    memcpy(m_packet.get(), packet, len);
    
    m_eth = (ether_header *)m_packet.get();
}


PacketObject::~PacketObject() {
}

