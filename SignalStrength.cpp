// SignalStrength.cpp
// 정보통신기술용어해설
// 802.11 MAC 프레임
// http://www.ktword.co.kr/abbr_view.php?nav=&m_temp1=3352&id=761
// 802.11 주소 필드
// http://www.ktword.co.kr/abbr_view.php?nav=&m_temp1=2129&id=761

#include "SignalStrength.h"

void SignalStrength(const u_char* packet, const Mac& targetMac)
{
    Radiotap* radiotap = (Radiotap*)packet;
    Dot11Frame* dot11frame = (Dot11Frame*)(packet + radiotap->len);

    // 타입만 가져온다.
    uint8_t type = dot11frame->type & Dot11Frame::MASK_TYPE;

    // management 혹은 data 타입이 아니면 스킵
    // control은 잘 발생하지 않고 주소 개수가 제멋대로라 파악하기 힘들다
    if(type != Dot11Frame::TYPE_MANAGEMENT &&
       type != Dot11Frame::TYPE_DATA)
       return;

    if(dot11frame->transmitter == targetMac)
    {
        size_t  offset = 0;

        // TSFT
        if(radiotap->present & 0b1)
            offset += 8;
        
        // Flags
        if(radiotap->present & 0b10)
            offset += 1;
        
        // Rate
        if(radiotap->present & 0b100)
            offset += 1;

        // Channel
        if(radiotap->present & 0b1000)
            offset += 4;

        // FHSS
        if(radiotap->present & 0b10000)
            offset += 2;

        // Antenna signal
        if(radiotap->present & 0b100000)
        {
            int8_t  strength = *(int8_t*)(packet + sizeof(Radiotap) + offset);
            printf("%s  %d\n", std::string(dot11frame->transmitter).c_str(), strength);
        }
    }
}