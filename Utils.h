//
// Created by HanWool on 2017. 11. 17..
//

#ifndef NXPIOTCONTROLBRIDGEPARSER_UTILS_H_H
#define NXPIOTCONTROLBRIDGEPARSER_UTILS_H_H

#include "Types.h"
#include "Enums.h"
#include "ByteBuffer.h"

// ## Define function prototypes
byte_t getChecksumFromCompressedData(eMessageCommandType messageType, ByteBuffer* dataBuffer);
byte_t getChecksumFromUncompressedData(eMessageCommandType messageType, ByteBuffer* dataBuffer);
bool isNeedByteStuffing(byte_t aByte, bool isSpecial, bool isAscii);
ByteBuffer* compressingData(ByteBuffer* unCompressedData);
ByteBuffer* decompressData(ByteBuffer* compressedData);

#endif //NXPIOTCONTROLBRIDGEPARSER_UTILS_H_H
