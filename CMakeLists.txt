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
"nes-emulator/main.cpp"
        nes-emulator/CPU/CPU.h) # <---- Add files here


add_executable(nesemu ${SOURCE_FILES})
target_link_libraries(nesemu PRIVATE ${SDL2_LIBRARY} Threads::Threads)