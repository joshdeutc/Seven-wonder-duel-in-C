#ifndef PLATEAU_H
#define PLATEAU_H

#include <iostream>
#include <string>

using namespace std;

#include "carte.h"

class Plateau
{
private:
    //
public:
    Plateau(/* args */);
    ~Plateau();
    friend class Jeu;
};

Plateau::Plateau(/* args */)
{
}

Plateau::~Plateau()
{
}

class PlateauAge : public Plateau
{
private:
    Batiment** cartes = nullptr;
public:
    PlateauAge(int Age);
    ~PlateauAge();
};



class PlateauMerveille : public Plateau
{
private:
    Merveille** cartesPremierPhase = nullptr;
    Merveille** cartesDeuxiemePhase = nullptr;
public:
    PlateauMerveille(/* args */);
    ~PlateauMerveille();
};

class PlateauJetonMilit : public Plateau
{
private:
    JetonMilitaire** JetonsMilitaires = nullptr;
    JetonProgres** JetonProgres = nullptr;
public:
    PlateauJetonMilit(/* args */);
    ~PlateauJetonMilit();
};

PlateauJetonMilit::PlateauJetonMilit(/* args */)
{
}

PlateauJetonMilit::~PlateauJetonMilit()
{
}


#endif /* PLATEAU_H */