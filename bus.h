#pragma once

#include <vector>
#include <cstdint>


class bus
{
private:
    std::vector<uint8_t> rom_bank_00_;
    std::vector<uint8_t> rom_bank_01_nn_;
    std::vector<uint8_t> vram_;
    std::vector<uint8_t> external_ram_;
    std::vector<uint8_t> work_ram_1_;
    std::vector<uint8_t> work_ram_2_cgb_switchable_;
    std::vector<uint8_t> echo_ram_;         //mirror of work ram 1 prohibited
    std::vector<uint8_t> object_attribute_memory_;
    std::vector<uint8_t> not_usable_;       //usage prohibited
    std::vector<uint8_t> io_registers_;
    std::vector<uint8_t> high_ram_;

    uint8_t interrupt_enable_register_;

public:
    //cons
    bus();

    //reader
    uint8_t read8(uint32_t address);

    //writer
    void write8(uint32_t address, uint8_t data);
};