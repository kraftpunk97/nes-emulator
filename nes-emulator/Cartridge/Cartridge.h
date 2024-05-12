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
        std::array<std::byte, HEADER_SIZE> m_header;
        std::vector<std::byte> m_trainer;
        std::vector<std::byte> m_PRG_ROM;
        std::vector<std::byte> m_CHR_ROM;
        std::vector<std::byte> m_INST_ROM;
        std::vector<std::byte> m_PROM;
    public:
        void loadROM(const std::string &filepath);
    };
}

#endif //NES_EMULATOR_CARTRIDGE_H
