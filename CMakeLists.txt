cmake_minimum_required(VERSION 3.27)
project(projet_lo21)

set(CMAKE_CXX_STANDARD 14)

include_directories(Code)

add_executable(projet_lo21
        Code/joueur.cpp
        Code/joueur.h
        Code/main.cpp
        Code/partie.h
        Code/carte.cpp
        Code/plateau.cpp
        Code/plateau.h
        Code/pioche.cpp
        Code/batiment.cpp
        Code/batiment.cpp
        Code/utils.cpp
        Code/carte_bat_merv.h
        Code/carte_bat_merv.h
)
