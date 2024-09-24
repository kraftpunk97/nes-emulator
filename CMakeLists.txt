cmake_minimum_required(VERSION 3.22)
project(nes-emulator CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/external/sdl2-cmake-scripts")
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
find_package(SDL2 REQUIRED)

add_subdirectory(external/spdlog)
find_package(spdlog)




set(SOURCE_FILES
        ) # <---- Add files here

add_executable(nesemu ${SOURCE_FILES} nes-emulator/main.cpp)
target_link_libraries(nesemu PRIVATE ${SDL2_LIBRARY} Threads::Threads spdlog)

add_executable(sandbox ${SOURCE_FILES} nes-emulator/sandbox.cpp)
target_link_libraries(sandbox PRIVATE ${SDL2_LIBRARY} Threads::Threads spdlog)