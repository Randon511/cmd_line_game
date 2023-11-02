cmake_minimum_required(VERSION 3.26)

# set(CMAKE_C_COMPILER "C:/ProgramData/mingw64/mingw64/bin/gdb.exe")
# set(CMAKE_CXX_COMPILER "C:/ProgramData/mingw64/mingw64/bin/gcc.exe")
# set(CMAKE_GENERATOR "Ninja" CACHE INTERNAL "" FORCE)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(cmd_line_game)
add_executable(cmd_line_game main.cpp)
