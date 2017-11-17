//
// Created by HanWool on 2017. 11. 17..
//

#include <stdbool.h>
#include "Utils.h"
#include "Enums.h"

// ### getChecksumFromCompressedData
// 압축된 데이터에 대한 체크섬을 생성합니다.
byte_t getChecksumFromCompressedData(eMessageCommandType messageType, ByteBuffer* dataBuffer) {
    byte_t checksum;
    // get Checksum from message type
    checksum = (byte_t) (((messageType >> 8) & 0xFF) ^ ((messageType) & 0xFF));
    // get Checksum from data length
    checksum ^= (byte_t) (((dataBuffer->length >> 8) & 0xFF) ^ ((dataBuffer->length) & 0xFF));

    if (dataBuffer != NULL) {
        // get Checksum from data
        byteStreamPtr array = dataBuffer->getArray(dataBuffer);
        for(uint32_t i = 0; i < dataBuffer->length; i++) {
            checksum ^= (byte_t)(i & 0xFF);
        }
        free(array);
    }
    return checksum;
}

// ### getChecksumFromUncompressedData
// 압축되지 않은 데이터에 대한 체크섬을 생성합니다.
byte_t getChecksumFromUncompressedData(eMessageCommandType messageType, ByteBuffer* dataBuffer) {
    byte_t checksum;
    // get Checksum from message type
    checksum = (byte_t)(((messageType >> 8) & 0xFF) ^ ((messageType) & 0xFF));
    // get Checksum from data length
    checksum ^= (byte_t)(((dataBuffer->length/2 >> 8) & 0xFF) ^ ((dataBuffer->length/2) & 0xFF));

    if (&dataBuffer != NULL) {
        bool bIn = true;
        byte_t aByte = 0;
        byteStreamPtr array = dataBuffer->getArray(dataBuffer);
        for(uint32_t i = 0; i < dataBuffer->length; i++) {
            if (bIn) {
                aByte = (byte_t) ((array[i] << 4) & 0xFF);
                bIn = false;
            } else {
                aByte |= (byte_t) (array[i] & 0xFF);
                checksum ^= aByte;
                bIn = true;
            }
        }
        free(array);
    }
    return checksum;
}

bool isNeedByteStuffing(byte_t aByte, bool isSpecial, bool isAscii) {
    ByteBuffer stuffedByte;
    if(isAscii) {
        return !isSpecial && aByte < 0x10;
    }
    else {
        return !isSpecial && (int32_t)aByte < 0x10;
    }
}

ByteBuffer* compressingData(ByteBuffer* unCompressedData) {
    ByteBuffer* compressed = getByteBuffer();
    bool bIn = true;
    byte_t aByte = 0;
    byteStreamPtr array = unCompressedData->getArray(unCompressedData);
    for(uint32_t i = 0; i < unCompressedData->length; i++) {
        if (bIn) {
            aByte = (byte_t)((array[i]<<4) & 0xFF);
            bIn = false;
        }
        else {
            aByte |= (byte_t)(array[i] & 0xFF);
            compressed->add(compressed, aByte);
            bIn = true;
        }
    }
    free(array);
    free(unCompressedData);
    return compressed;
}

ByteBuffer* decompressData(ByteBuffer* compressedData) {
    ByteBuffer* deCompressed = getByteBuffer();
    byteStreamPtr array = compressedData->getArray(compressedData);
    for(uint32_t i = 0; i < compressedData->length; i++) {
        deCompressed->add(deCompressed, (byte_t)((array[i] & 0xF0) >> 4));
        deCompressed->add(deCompressed, (byte_t)((array[i] & 0x0F)));
    }
    return deCompressed;
}