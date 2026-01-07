#pragma once

#include <cstdint>

class register_af
{
public:
    static constexpr uint8_t zero_flag__= 0x80;            //7th bit
    static constexpr uint8_t subtraction_flag_ = 0x40;     //6th bit
    static constexpr uint8_t half_carry_flag_ = 0x20;      //5th bit
    static constexpr uint8_t carry_flag_ = 0x10;           //4th bit

    union
    {
        struct
        {
            uint8_t f_;
            uint8_t a_;
        };
        uint16_t af_;
    };


    constexpr register_af() : af_(0){};

    void set(uint16_t value)
    {
        af_=value & 0xFFF0;     //lower 4 bits 0
    }

    uint16_t get() const
    {
        return af_;
    }
};