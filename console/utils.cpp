#ifndef UTILS_H
#define UTILS_H

#include "utils.h"

#include <iostream>
#include <random>
#include <set>
#include <ctime>
#include <algorithm>

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
    
    // Génération d'une liste d'entiers dans la plage spécifiée
    std::vector<int> numbers;
    for (int i = min; i <= max; ++i) {
        numbers.push_back(i);
    }

    // Mélange des entiers pour obtenir une séquence aléatoire
    std::shuffle(numbers.begin(), numbers.end(), gen);

    // Sélection des premiers 'size' éléments
    return std::vector<int>(numbers.begin(), numbers.begin() + size);
}

#endif
