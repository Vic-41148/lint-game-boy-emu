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