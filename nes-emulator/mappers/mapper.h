//
// Created by kxg220013 on 5/11/2024.
//

#ifndef NES_EMULATOR_MAPPER_H
#define NES_EMULATOR_MAPPER_H

#include <cstdint>
#include <string>
#include <vector>
#include <array>
#include "../specs.h"

namespace nes {
    class Mapper {
    private:
        std::array<uint8_t, HEADER_SIZE> m_header;
        std::array<uint8_t, TRAINER_SIZE> m_trainer;
        std::vector<uint8_t> m_PRGROM;
        std::vector<uint8_t> m_CHRROM;
        uint8_t m_PRGROM_blocks, m_CHRROM_blocks;
        uint8_t m_nametable_arrangement;
        bool m_is_PRGRAM, m_is_trainer;
        bool m_alternative_nt_layout;
        bool m_is_vs, m_nes2_identifier;
        uint16_t m_mapper_num;

        void loadHeader(std::ifstream& rom);
        void parseHeader();
        void loadTrainer(std::ifstream& rom);
        void loadPRGROM(std::ifstream& rom);
        void loadCHRROM(std::ifstream& rom);

    public:
        Mapper(const std::string &filepath);

    };
}

#endif //NES_EMULATOR_MAPPER_H
