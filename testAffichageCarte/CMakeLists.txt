cmake_minimum_required(VERSION 3.10)
project(testAffichageCarte)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-mconsole")
file(GLOB SOURCES "*.cpp")

add_executable(testAffichageCarte ${SOURCES}
        carte_bat_merv.h
        utils.cpp)
