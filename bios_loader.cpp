#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdint>

#include "bios_loader.h"

void bios_loader::bios_loader_(const std::string& file_path_,std::vector<uint8_t>& bios_file_)
{
    std::ifstream file(file_path_,std::ios::binary | std::ios::ate);

    if(!file.is_open())
    {
        std::cerr<<"Failed to open bios file!";
        return;
    }

    std::streamsize size=file.tellg();

    if(size!= 0x100)
    {
        std::cerr << "Warning: DMG BIOS should be 256 bytes\n";
        return;
    }


    file.seekg(0,std::ios::beg);

    //std::vector<uint8_t> bios_file_(size);
    bios_file_.resize(size);

    if(!file.read(reinterpret_cast<char*>(bios_file_.data()), size))
    {
        std::cerr<<"Failed to read bios file!";
        bios_file_.clear();
        return;
    }
}