//
// Created by kxg220013 on 5/16/2024.
//

#ifndef NES_EMULATOR_EXCEPTION_H
#define NES_EMULATOR_EXCEPTION_H

#include <exception>
#include <string>

namespace nes {
class NESException: public std::exception {
        std::string message;
public:
    NESException(const char* msg): message(msg) {}
    [[nodiscard]] const char* what() const noexcept override {
        return message.c_str();
    }
    };
}


#endif //NES_EMULATOR_EXCEPTION_H
