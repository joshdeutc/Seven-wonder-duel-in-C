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
    Batiment** cartes;
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
    Merveille** cartes;
public:
    PlateauMerveille(/* args */);
    ~PlateauMerveille();
};

PlateauMerveille::PlateauMerveille(/* args */)
{
}

PlateauMerveille::~PlateauMerveille()
{
}

class PlateauJetonMilit : public Plateau
{
private:
    JetonMilitaire** JetonsMilitaires;
    JetonScientifique** JetonScientifiques;
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