//
// Created by kxg220013 on 5/11/2024.
//

#ifndef NES_EMULATOR_CARTRIDGE_H
#define NES_EMULATOR_CARTRIDGE_H

#include <cstdint>
#include <string>
#include <vector>
#include <array>
#include "specs.h"

namespace nes {
    class Cartridge {
    private:
        std::array<u_char, HEADER_SIZE> m_header;
        bool m_is_trainer;
        bool m_is_PRG_RAM;
        bool m_alternative_nt_layout;
        bool m_is_vs;
        bool m_nes2_identifier;
        u_char m_mapper_num;
        std::vector<u_char> m_PRG_ROM;
        std::vector<u_char> m_CHR_ROM;
        std::vector<u_char> m_INST_ROM;
        std::vector<u_char> m_PROM;
    public:
        void loadROM(const std::string &filepath);
        void loadDummy(const std::string &filepath);  // TODO: Delete later
        
    };
}

#endif //NES_EMULATOR_CARTRIDGE_H
