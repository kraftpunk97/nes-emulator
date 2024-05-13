//
// Created by kxg220013 on 5/11/2024.
//

#ifndef NES_EMULATOR_SPECS_H
#define NES_EMULATOR_SPECS_H

// CPU
#define CPU_CLOCK_FREQ 1.8e6
#define CPU_RAM_SIZE 0x800

// PPU
#define SCREEN_WIDTH 256
#define SCREEN_HEIGHT 240
#define PPU_CLOCK_FREQ 5.37e6
#define PPU_RAM_SIZE 0x800
#define PPU_OAM 0x100
#define PPU_COLOR_PALLETE_SIZE 0x1C


// Cartridge
#define HEADER_SIZE 0x10

// typedefs
#define u_char unsigned char

#endif //NES_EMULATOR_SPECS_H
