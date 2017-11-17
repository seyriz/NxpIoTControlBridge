//
// Created by HanWool on 2017. 11. 17..
//

#include "ByteBuffer.h"

void _free(ByteBuffer* this);
void add(ByteBuffer* this, byte_t aByte);
byte_t get(ByteBuffer* this, uint32_t index);
uint32_t size(ByteBuffer* this);
byteStreamPtr getArray(ByteBuffer* this);


// ### getByteBuffer
// Initializes ByteBuffer and allocates a member function. After using ByteBuffer, must be call free() for memory management.
ByteBuffer* getByteBuffer() {
    ByteBuffer* buffer = malloc(sizeof(ByteBuffer));
    buffer->free = _free;
    buffer->add = add;
    buffer->get = get;
    buffer->getArray = getArray;
    buffer->buffer = malloc(sizeof(byte_t));
    buffer->length = 0;
    return buffer;
}

void _free(ByteBuffer* this){
    free(this);
}

// ### add
// Add a new byte to the buffer.
// It creates a new buffer that is one size larger than the old one,
// copies the old buffer into the new buffer,
// adds the new byte to the end of the new buffer, and free () the old buffer.
void add(ByteBuffer* this, byte_t aByte) {
    byteStreamPtr old = this->buffer;
    byteStreamPtr new = malloc((sizeof(byte_t) * this->length) + 1);
    for (uint32_t i = 0; i < this->length; i++) {
        new[i] = old[i];
    }
    new[this->length] = aByte;
    this->length += 1;
    this->buffer = new;
    free(old);
}

// ###
// Get a single byte at an arbitrary point in the buffer. If the buffer is out of range, it returns 0x00.
byte_t get(ByteBuffer* this, uint32_t index) {
    if(index < this->length) {
        return this->buffer[index];
    }
    else {
        return 0x00;
    }
}

uint32_t size(ByteBuffer* this) {
    return this->length;
}

byteStreamPtr getArray(ByteBuffer* this) {
    byteStreamPtr old = this->buffer;
    byteStreamPtr new = malloc(sizeof(byte_t)*this->length);
    for (int32_t i = 0; i < this->length; i++) {
        new[i] = old[i];
    }
    return new;
}