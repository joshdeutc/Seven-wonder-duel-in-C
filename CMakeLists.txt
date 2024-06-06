cmake_minimum_required(VERSION 3.27)
project(projet_lo21)

set(CMAKE_CXX_STANDARD 14)

include_directories(Code)

add_executable(projet_lo21
        Code/joueur.cpp
        Code/joueur.h
        Code/main.cpp
        Code/partie.h
        Code/plateau.cpp
        Code/plateau.h
        Code/utils.cpp
        Code/carte_bat_merv.h
        Code/jeu.cpp
        Code/jeu.h
        Code/partie.cpp
        Code/carte_bat_merv.cpp
        Code/wondersException.cpp
        Code/wondersException.cpp
)
add_subdirectory(testAffichageCarte)
