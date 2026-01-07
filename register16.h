#pragma once

#include <cstdint>

class register16
{
    //flags
    static constexpr uint8_t zero_flag__= 0x80;            //7th bit
    static constexpr uint8_t subtraction_flag_ = 0x40;     //6th bit
    static constexpr uint8_t half_cary_flag_ = 0x20;       //5th bit
    static constexpr uint8_t carry_flag_ = 0x10;           //4th bit

    union
    {
        struct
        {
            uint8_t lo_;        //lil endian stuff
            uint8_t hi_;
        };
        uint16_t val16_;
    };
public:
    constexpr register16() : val16_(0) {}
};