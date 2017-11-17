//
// Created by HanWool on 2017. 11. 17..
//

#include "CommandStructure.h"

void setMessageType(sPacket* this, uint16_t messageType);
void setParsingStatus(sPacket* this, eParsingStatus parsingStatus);
void setChecksum(struct _Packet* this, uint8_t checksum);
void setDataLength(struct _Packet* this, uint16_t dataLength);
void setData(struct _Packet* this, ByteBuffer* data);
void parseData(struct _Packet* this);

sPacket* initPacketObject() {
    sPacket* packet = &{0,};
    packet->setMessageType = setMessageType;
    packet->setParsingStatus = setParsingStatus;
    packet->setChecksum = setChecksum;
    packet->setDataLength = setDataLength;
    packet->setData = setData;
    return packet;
}

void setMessageType(sPacket* this, uint16_t messageType){
    this->messageCommandType = messageType;
}

void setParsingStatus(sPacket* this, eParsingStatus parsingStatus) {
    this->parsingStatus = parsingStatus;
}

void setChecksum(struct _Packet* this, uint8_t checksum) {
    this->checksum = checksum;
}

void setDataLength(struct _Packet* this, uint16_t dataLength) {
    this->dataLength = dataLength;
}

void setData(struct _Packet* this, ByteBuffer* data) {
    if(this->dataBuffer != NULL) {
        free(this->dataBuffer);
    }
    this->dataBuffer = data;
}

void parseData(struct _Packet* this) {
    switch (this->messageCommandType) {
        default:
            break;
    }
}