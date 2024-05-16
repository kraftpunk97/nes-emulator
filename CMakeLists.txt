cmake_minimum_required(VERSION 3.22)
project(nes-emulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/sdl2-cmake-scripts")
set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(SDL2 REQUIRED)
find_package(Threads REQUIRED)

include_directories("nes-emulator/"
        ${SDL2_INCLUDE_DIR})

set(SOURCE_FILES
        nes-emulator/cpu/cpu.h
        nes-emulator/log/log.cpp
        nes-emulator/log/log.h
        nes-emulator/specs.h
        nes-emulator/mappers/mapper.cpp
        nes-emulator/mappers/mapper.h
        nes-emulator/mappers/NROM.cpp
        nes-emulator/mappers/NROM.h
        nes-emulator/exception.cpp
        nes-emulator/exception.h) # <---- Add files here


add_executable(nesemu ${SOURCE_FILES} nes-emulator/main.cpp)
target_link_libraries(nesemu PRIVATE ${SDL2_LIBRARY} Threads::Threads)

add_executable(sandbox ${SOURCE_FILES} nes-emulator/sandbox.cpp)
target_link_libraries(sandbox PRIVATE ${SDL2_LIBRARY} Threads::Threads)