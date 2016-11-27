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

#include "PacketAnalyzer.h"
#include <iostream>

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

PacketObject* PacketAnalyzer::getObject(const struct pcap_pkthdr* pkthdr, const u_char* packet)
{
 std::cout <<  "getObject" << std::endl;
 return nullptr;
}
