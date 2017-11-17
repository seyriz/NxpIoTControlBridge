cmake_minimum_required(VERSION 3.7)
project(NxpIoTControlBridgeParser)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES library.c library.h Utils.h Types.h ByteBuffer.h ByteBuffer.c Enums.h Utils.c CommandStructure.h CommandStructure.c)
add_library(NxpIoTControlBridgeParser ${SOURCE_FILES})