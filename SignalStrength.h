// SignalStrength.h

#ifndef _SIGNAL_STRENGTH_H_
#define _SIGNAL_STRENGTH_H_

#include <string>
#include <cstring>

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
    static const uint8_t  TYPE = 0x80;

    uint8_t   type;
    uint8_t   flags;
    uint8_t   duration[2];
    uint8_t   receiver[6];
    uint8_t   transmitter[6];
    uint8_t   bssid[6];
};
#pragma pack(pop)


#endif