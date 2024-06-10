cmake_minimum_required(VERSION 3.10)
project(testAffichageCarte)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-mconsole")

file(GLOB SOURCES "*.cpp")
# Supprimer les fichiers spécifiques de la liste des sources

add_executable(testAffichageCarte
        carte_bat_merv.h
        carte_bat_merv.cpp
        jeu.cpp
        jeu.h
        plateau.cpp
        plateau.h
        utils.cpp
        utils.h
        main.cpp
        )
