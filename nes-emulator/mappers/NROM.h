//
// Created by kxg220013 on 5/13/2024.
//

#ifndef NES_EMULATOR_NROM_H
#define NES_EMULATOR_NROM_H

#include "mapper.h"

namespace nes {
    class NROM : public mapper {
    public:
        u_char& operator[](uint16_t address);
    };
}


#endif //NES_EMULATOR_NROM_H
