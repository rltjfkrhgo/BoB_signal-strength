// SignalStrength.h

#ifndef _SIGNAL_STRENGTH_H_
#define _SIGNAL_STRENGTH_H_

#include <string>
#include <cstring>
#include "mac.h"

#pragma pack(push, 1)
struct radiotap
{
    uint8_t   version;
    uint8_t   pad;
    uint16_t  len;
    uint32_t  present;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct dot11frame
{
    static const uint8_t  MASK_TYPE = 0b1100;
    static const uint8_t  MASK_SUBTYPE = 0b11110000;

    static const uint8_t  TYPE_MANAGEMENT = 0b0000;
    static const uint8_t  TYPE_CONTROL = 0b0100;
    static const uint8_t  TYPE_DATA = 0b1000;

    uint8_t   type;
    uint8_t   flags;
    uint8_t   duration[2];
    uint8_t   receiver[6];
    uint8_t   transmitter[6];
    uint8_t   address3[6];
};
#pragma pack(pop)

typedef struct radiotap Radiotap;
typedef struct dot11frame Dot11Frame;
typedef struct Mac Mac;

void SignalStrength(const u_char* packet, const Mac& targetMac);

#endif