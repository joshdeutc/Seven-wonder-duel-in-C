#ifndef JEU_H
#define JEU_H

#include <iostream>
#include <string>

#include "carte.h"

using namespace std;

class Jeu { // Singleton Jeu
private:
    friend class PlateauAge;
    static Jeu* instance;
    Jeu();
    Jeu(Jeu &other) = delete;
    virtual ~Jeu();
    void operator=(const Jeu &) = delete;

    Batiment** tabCartesAge1;
    Batiment** tabCartesAge2;
    Batiment** tabCartesAge3;
    Guilde** tabCartesGuilde;
    Merveille** tabCartesMerveille;
    JetonMilitaire** tabJetonMilitaire;
    JetonProgres** tabJetonProgres;

public:
    static Jeu* getInstance();
    static void freeInstance();
};

// Initialiser le pointeur à nullptr
Jeu* Jeu::instance = nullptr;

#endif /* JEU_H */