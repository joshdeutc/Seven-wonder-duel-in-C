#ifndef UTILS_H
#define UTILS_H

#include "utils.h"

#include <iostream>
#include <random>
#include <set>
#include <ctime>

// Fonction pour générer un tableau d'entiers distincts aléatoires
std::vector<int> generateRandomDistinctIntegers(int size, int min, int max) {
    // Initialisation du générateur de nombres aléatoires
    std::random_device rd;
    std::mt19937 gen(rd());
    
    // Création d'un ensemble pour stocker les entiers distincts
    std::set<int> distinctIntegers;
    
    // Génération d'entiers aléatoires distincts jusqu'à ce que la taille désirée soit atteinte
    while (distinctIntegers.size() < size) {
        std::uniform_int_distribution<int> dis(min, max);
        distinctIntegers.insert(dis(gen));
    }
    
    // Conversion de l'ensemble en un vecteur
    std::vector<int> result(distinctIntegers.begin(), distinctIntegers.end());
    return result;
}

#endif
