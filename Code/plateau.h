#ifndef PLATEAU_H
#define PLATEAU_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "carte_bat_merv.h"

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
    vector<Batiment*> defausses;
    // vecteur permettant de mettre a jour le plateau
    vector<Batiment *> etage1;
    vector<Batiment *> etage2;
    vector<Batiment *> etage3;
    vector<Batiment *> etage4;
    vector<Batiment *> etage5;
    vector<Batiment *> etage6;
    vector<Batiment *> etage7;

public:
    PlateauAge(int Age);
    ~PlateauAge();
    Batiment **getCartes() const { return cartes; }
    const vector<Batiment*>& getDefausses() const { return defausses; }
    void addDefausse(Batiment *batiment);
    void accessibilite();
    bool deviens_accessible_age1(int &choix);
    bool deviens_accessible_age2(int &choix);
    bool deviens_accessible_age3(int &choix);
    vector<Batiment *>  trouver_etage_age1(int& choix);
    vector<Batiment *>  trouver_etage_age2(int &choix);
    vector<Batiment *> trouver_etage_age3(int &choix);
    void destruction_carte_plateau_age1(int &choix);
    void destruction_carte_plateau_age2(int &choix);
    void destruction_carte_plateau_age3(int &choix)
};



class PlateauMerveille : public Plateau
{
private:
    Merveille** cartesPremierPhase = nullptr;
    Merveille** cartesDeuxiemePhase = nullptr;
public:
    PlateauMerveille();
    ~PlateauMerveille();
};

class PlateauJetonMilit : public Plateau
{
private:
    JetonMilitaire** JetonsMilitaires = nullptr;
    JetonProgres** JetonProgres = nullptr;
public:
    PlateauJetonMilit();
    ~PlateauJetonMilit();
};

#endif /* PLATEAU_H */