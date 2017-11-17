//
// Created by HanWool on 2017. 11. 17..
//

#ifndef NXPIOTCONTROLBRIDGEPARSER_BYTEBUFFER_H
#define NXPIOTCONTROLBRIDGEPARSER_BYTEBUFFER_H

#include <stdlib.h>
#include "Types.h"

typedef struct _ByteBuffer {
    byteStreamPtr buffer;
    uint32_t length;
    void (*free)(struct _ByteBuffer* this);
    void (*add)(struct _ByteBuffer* this, byte_t aByte);
    byte_t (*get)(struct _ByteBuffer* this, uint32_t index);
    uint32_t (*size)(struct _ByteBuffer* this);
    byteStreamPtr (*getArray)(struct _ByteBuffer* this);
} ByteBuffer;

ByteBuffer* getByteBuffer();

#endif //NXPIOTCONTROLBRIDGEPARSER_BYTEBUFFER_H
