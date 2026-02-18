cmake_minimum_required(VERSION 3.27)
project(projet_lo21)

set(CMAKE_CXX_STANDARD 14)

include_directories(console)

add_executable(projet_lo21
        console/joueur.cpp
        console/joueur.h
        console/main.cpp
        console/partie.h
        console/plateau.cpp
        console/plateau.h
        console/utils.cpp
        console/carte_bat_merv.h
        console/jeu.cpp
        console/jeu.h
        console/partie.cpp
        console/carte_bat_merv.cpp
        console/wondersException.cpp
)
add_subdirectory(testAffichageCarte)
