#pragma once

#include <string>
#include <vector>
#include <cstdint>

class bios_loader
{
public:
    void bios_loader_(const std::string& file_path_,std::vector<uint8_t>& bios_file_);
};