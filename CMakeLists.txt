cmake_minimum_required(VERSION 3.27)
project(projet_lo21)

set(CMAKE_CXX_STANDARD 14)

include_directories(Code)

add_executable(projet_lo21
        Code/carte.h
        Code/joueur.cpp
        Code/joueur.h
        Code/main.cpp
        Code/partie.h
        Code/carte.cpp
)
