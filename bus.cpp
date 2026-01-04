#include <iostream>
#include <vector>
#include <cstdint>
#include "bus.h"

//definitions
//cons
bus::bus()
{
    rom_bank_00_.resize(0x4000);                     //16.0 KiB
    rom_bank_01_nn_.resize(0x4000);                  //16.0 KiB
    vram_.resize(0x2000);                              //08.0 KiB
    external_ram_.resize(0x2000);                     //08.0 KiB
    work_ram_1_.resize(0x1000);                        //04.0 KiB
    work_ram_2_cgb_switchable_.resize(0x1000);         //04.0 KiB
    echo_ram_.resize(0x1E00);                         //07.5 KiB
    object_attribute_memory_.resize(0xA0);           //160  bytes
    not_usable_.resize(0x60);                         //96.0 bytes
    io_registers_.resize(0x80);                      //128  bytes
    high_ram_.resize(0x7F);                          //127  bytes
    interrupt_enable_register_=0x00;                   //1.00 bytes
}

//reader
uint8_t bus::read8(uint32_t address)
{
    if(address<=0x3FFF && address>=0x0000)
    {
        return rom_bank_00_[address];
    }
    else if(address<=0x7FFF && address>=0x4000)
    {
        return rom_bank_01_nn_[address-0x4000];
    }
    else if(address<=0x9FFF && address>=0x8000)
    {
        return vram_[address-0x8000];
    }
    else if(address<=0xBFFF && address>=0xA000)
    {
        return external_ram_[address-0xA000];
    }
    else if(address<=0xCFFF && address>=0xC000)
    {
        return work_ram_1_[address-0xC000];
    }
    else if(address<=0xDFFF && address>=0xD000)
    {
        return work_ram_2_cgb_switchable_[address-0xD000];
    }
    else if(address<=0xFDFF && address>=0xE000)
    {
        return echo_ram_[address-0xE000];
    }
    else if(address<=0xFE9F && address>=0xFE00)
    {
        return object_attribute_memory_[address-0xFE00];
    }
    else if(address<=0xFEFF && address>=0xFEA0)
    {
        return not_usable_[address-0xFEA0];
    }
    else if(address<=0xFF7F && address>=0xFF00)
    {
        return io_registers_[address-0xFF00];
    }
    else if(address<=0xFFFE && address>=0xFF80)
    {
        return high_ram_[address-0xFF80];
    }
    else if(address==0xFFFF)
    {
        return interrupt_enable_register_;
    }
    else
    {
        std::cout<<"invalid address!";
        return 0xFF;    //return all 1 on 8bit data line
    }
}

