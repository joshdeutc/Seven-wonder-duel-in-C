#ifndef UTILS_H
#define UTILS_H

#include "utils.h"

#include <iostream>
#include <random>
#include <set>
#include <ctime>

/**
 * Génère un tableau d'entiers aléatoires distincts dans une plage donnée.
 *
 * @param[in] min La valeur minimale de la plage (incluse).
 * @param[in] max La valeur maximale de la plage (incluse).
 * @param[in] count Le nombre d'entiers à générer.
 * @return Un tableau d'entiers aléatoires distincts.
 * @exemple generateRandomDistinctIntegers(1, 10, 5) peut renvoyer {3, 1, 5, 9, 7}.
 */
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
