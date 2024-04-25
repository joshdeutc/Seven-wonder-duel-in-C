#ifndef PLATEAU_H
#define PLATEAU_H

#include <iostream>
#include <string>

using namespace std;

#include "carte.h"

class Plateau
{
private:
    /* data */
public:
    Plateau(/* args */);
    ~Plateau();
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
    PlateauAge(/* args */);
    ~PlateauAge();
};

PlateauAge::PlateauAge(/* args */)
{
}

PlateauAge::~PlateauAge()
{
}

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
    JetonScientifique** JetonScientifiques = nullptr;
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