#ifndef JEU_H
#define JEU_H

#include <iostream>
#include <string>

#include "carte.h"

using namespace std;

class Jeu { // Singleton Jeu
private:

    static Jeu* instance;
    Jeu();
    Jeu(Jeu &other) = delete;
    virtual ~Jeu();
    void operator=(const Jeu &) = delete;

    Carte** tabCartesAge1;
    Carte** tabCartesAge2;
    Carte** tabCartesAge3;
    Carte** tabCartesGuilde;
    Carte** tabCartesMerveille;
    Carte** tabJetonMilitaire;
    Carte** tabJetonScientifique;

public:
    static Jeu* getInstance();
    static void freeInstance();
};

// Initialiser le pointeur à nullptr
Jeu* Jeu::instance = nullptr;

#endif /* JEU_H */