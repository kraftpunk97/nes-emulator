//
// Created by kxg220013 on 5/11/2024.
//

#include <iostream>
#include <fstream>
#include <stdexcept>
#include "log/log.h"
#include "mapper.h"
#include "exception.h"

namespace nes {
    Mapper::Mapper(const std::string &filepath) {
        std::ifstream file;
        file.open(filepath, std::ios::binary);

        // Opening the ROM
        if (not file.is_open()) {
            LOG(Error) << "Error opening ROM\n";
            throw std::invalid_argument("Error opening ROM");
        }
        LOG(InfoVerbose) << "Successfully opened the ROM file\n";

        loadHeader(file);
        parseHeader();

        if (m_is_trainer) {
            loadTrainer(file);
        }

        loadPRGROM(file);

        file.close();
    }

    void Mapper::loadHeader(std::ifstream& rom) {
        // Extracting the header
        if (not rom.read(reinterpret_cast<char*>(&m_header[0]), HEADER_SIZE)) {
            LOG(Error) << "Error reading the header file\n";
            throw std::invalid_argument("Error reading the header file");
        }
        LOG(InfoVerbose) << "Successfully loaded the header";
        std::vector<uint8_t> nes_ascii = {0x4E, 0x45, 0x53, 0x1A}; // NES*EOF*
        std::vector<uint8_t> iNES_identifier(m_header.begin(), m_header.begin()+4);
        if (iNES_identifier != nes_ascii) {
            LOG(Error) << "This is not a valid NES ROM.\n";
            throw std::invalid_argument("This is not a valid NES ROM");
        }
        LOG(InfoVerbose) << "ROM is valid\n";
    }
    void Mapper::parseHeader() {
        uint8_t flags6 = m_header[6];
        uint8_t flags7 = m_header[7];
        uint8_t flags8 = m_header[8];
        uint8_t flags9 = m_header[9];

        // Byte 6 flags
        m_nametable_arrangement = flags6 & 0x01;
        m_is_PRGRAM = (flags6&0x02)!=0;
        m_is_trainer = (flags6&0x04)!=0;
        m_alternative_nt_layout = (flags6&0x08)!=0;

        // Byte 7 flags
        m_is_vs = flags7 & 0x01;
        m_nes2_identifier = (flags7&0x0C) == 0x08;

        uint8_t m_PRGRAM_blocks = m_header[8]; // TODO: Unsure about this...

        if (not m_nes2_identifier and
        m_header[12]==m_header[13]==m_header[14]==m_header[15]==0x0) {
            printf("iNES\n");
        } else if (m_nes2_identifier) {
            printf("NES2.0\n");
        }

        // Extract PRG and CHR ROM sizes
        if (m_nes2_identifier) {
            m_PRGROM_blocks = (flags9&0xF0) | m_header[4];
            m_CHRROM_blocks = ((flags9&0x0F)<<4) | m_header[5];
        } else {
            m_PRGROM_blocks = m_header[4];
            m_CHRROM_blocks = m_header[5];
        }
        LOG(InfoVerbose) << PRGROM_BLOCK_SIZE*m_PRGROM_blocks << " bytes reserved for PRG ROM\n";
        LOG(InfoVerbose) << CHRROM_BLOCK_SIZE*m_CHRROM_blocks << " bytes reserved for CHR ROM\n";
        printf("%d (%X) bytes reserved for PRG ROM\n", PRGROM_BLOCK_SIZE*m_PRGROM_blocks,PRGROM_BLOCK_SIZE*m_PRGROM_blocks);
        printf("%d (%X) bytes reserved for CHR ROM\n", CHRROM_BLOCK_SIZE*m_CHRROM_blocks, CHRROM_BLOCK_SIZE*m_CHRROM_blocks);

        // Mapper identification
        m_mapper_num = (flags7 & 0xF0) | ((flags6 & 0xF0) >> 4);
        if (m_nes2_identifier) {
            m_mapper_num = (static_cast<uint16_t>(flags8&0x0F)<<8) | m_mapper_num;
        }
        LOG(InfoVerbose) << "Mapper number -> " << std::ios::dec << m_mapper_num;
        printf("Mapper number: %d\n", m_mapper_num);
    }

        void Mapper::loadTrainer(std::ifstream& rom) {
        if (not rom.read(reinterpret_cast<char*>(&m_trainer[0]), TRAINER_SIZE)) {
            LOG(Error) << "Unable to load trainer\n";
            throw NESException("Unable to load trainer.");
        }
    }

    void Mapper::loadPRGROM(std::ifstream& rom) {
        size_t PRGROM_size = m_PRGROM_blocks * PRGROM_BLOCK_SIZE;
        m_PRGROM.reserve(PRGROM_size);
        if (not rom.read(reinterpret_cast<char*>(&m_PRGROM[0]),PRGROM_size)) {
            LOG(Error) << "Unable to load PRG ROM\n";
            throw NESException("Unable to load PRG ROM.");
        };
    }

    void Mapper::loadCHRROM(std::ifstream &rom) {
        size_t CHRROM_size = m_CHRROM_blocks * CHRROM_BLOCK_SIZE;
        m_CHRROM.reserve(CHRROM_size);
        if (not rom.read(reinterpret_cast<char*>(&m_CHRROM[0]), CHRROM_size)) {
            LOG(Error) << "Unable to load CHR ROM\n";
            throw NESException("Unable to load CHR ROM.");
        }
    }

}