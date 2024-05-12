//
// Created by kxg220013 on 5/11/2024.
//

#include <iostream>
#include <fstream>
#include "Log/Log.h"
#include "Cartridge.h"

namespace nes {
    void Cartridge::loadROM(const std::string &filepath) {
        std::ifstream file;
        file.open(filepath, std::ios::binary);

        // Opening the ROM
        if (not file.is_open()) {
            LOG(Error) << "Error opening ROM\n";
            return;  // TODO: Maybe return something here
        }
        LOG(InfoVerbose) << "Successfully opened the ROM file\n";

        // Extracting the header
        if (not file.read(reinterpret_cast<char*>(&m_header[0]), HEADER_SIZE)) {
            LOG(Error) << "Error reading the header file\n";
            return;
        }
        LOG(InfoVerbose) << "Successfully loaded the header";

        std::vector<std::byte> nes_ascii = { static_cast<std::byte>(0x4E), static_cast<std::byte>(0x45),
                                                   static_cast<std::byte>(0x53), static_cast<std::byte>(0x1A)
        }; // NES*EOF*
        std::vector<std::byte> iNES_identifier(m_header.begin(), m_header.begin()+4);
        if (iNES_identifier != nes_ascii) {
            LOG(Error) << "This is not a valid NES ROM.\n";
            return;
        }
        std::cout << "ROM is valid\n";

        //
    }
}