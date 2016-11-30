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

class PacketObject {
public:
    PacketObject();
    PacketObject(const PacketObject& orig) = delete;
    virtual ~PacketObject();
private:

};

#endif /* PACKETOBJECT_H */

