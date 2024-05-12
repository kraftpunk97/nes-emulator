//
// Created by kxg220013 on 5/11/2024.
//

#include <iostream>
#include "Cartridge/Cartridge.h"

int main(int argc, char* args[]) {
    if (argc < 1) {
        std::cerr << "Missing ROM File Path\n";
    }
    nes::Cartridge cartridge;
    cartridge.loadROM(args[1]);
    return 0;
}