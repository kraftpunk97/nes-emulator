//
// Created by kxg220013 on 5/13/2024.
//

#include "Mappers/NROM.h"

namespace nes {
    u_char& operator[](u_int16_t address) {
        if (0x6000<=address<=0x7FFF) {
            return mapper::m_PRG_ROM[address];
        }
    }
}