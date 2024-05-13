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

        std::vector<u_char> nes_ascii = {0x4E, 0x45, 0x53, 0x1A}; // NES*EOF*
        std::vector<u_char> iNES_identifier(m_header.begin(), m_header.begin()+4);
        if (iNES_identifier != nes_ascii) {
            LOG(Error) << "This is not a valid NES ROM.\n";
            return;
        }
        LOG(InfoVerbose) << "ROM is valid\n";

        // Extract PRG ROM size
        m_PRG_ROM.reserve(static_cast<size_t>(16*0x400*m_header[4]));
        LOG(InfoVerbose) << 16*0x400*m_header[4] << " bytes reserved for PRG ROM\n";

        // Extract CHR ROM size
        m_CHR_ROM.reserve(static_cast<size_t>(8*0x400*m_header[5]));
        LOG(InfoVerbose) << 8*0x400*m_header[5] << " bytes reserved for CHR ROM\n";

        u_char flags6 = m_header[6];
        bool nametable_arrangement = flags6 & 0x01;
        m_is_PRG_RAM = (flags6&0x02)!=0;
        m_is_trainer = (flags6&0x04)!=0;
        m_alternative_nt_layout = (flags6&0x08)!=0;

        u_char flags7 = m_header[7];
        m_is_vs = flags7 & 0x01;
        m_nes2_identifier = (flags7 & 0x0C) == 0x08;
        m_mapper_num = (flags7&0xF0) | ((flags6&0xF0)>>4);

        int PRG_RAM_size = 8*0x400*m_header[8];

        if (not m_nes2_identifier and
        m_header[12]==m_header[13]==m_header[14]==m_header[15]==0x0) {
            printf("iNES\n");
        } else if (m_nes2_identifier) {
            printf("NES2.0\n");
        }



    }

    void Cartridge::loadDummy(const std::string &filepath) { // TODO: Delete later
        return;
    }
}