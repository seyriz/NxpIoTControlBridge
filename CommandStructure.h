//
// Created by HanWool on 2017. 11. 17..
//

#ifndef NXPIOTCONTROLBRIDGEPARSER_COMMANDSTRUCTURE_H
#define NXPIOTCONTROLBRIDGEPARSER_COMMANDSTRUCTURE_H

#include "Types.h"
#include "Enums.h"
#include "ByteBuffer.h"

typedef struct _Packet {
    uint16_t messageCommandType;
    eParsingStatus parsingStatus;
    uint8_t checksum;
    uint16_t dataLength;
    ByteBuffer* dataBuffer;
    void (*setMessageType)(struct _Packet* this, uint16_t messageType);
    void (*setParsingStatus)(struct _Packet* this, eParsingStatus parsingStatus);
    void (*setChecksum)(struct _Packet* this, uint8_t checksum);
    void (*setDataLength)(struct _Packet* this, uint16_t dataLength);
    void (*setData)(struct _Packet* this, ByteBuffer* data);
    void (*parseData)(struct _Packet* this);
} sPacket;

sPacket* initPacketObject();


#endif //NXPIOTCONTROLBRIDGEPARSER_COMMANDSTRUCTURE_H
