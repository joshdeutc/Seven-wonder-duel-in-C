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
    Carte** cartes = nullptr;
    vector<Carte*> defausses;
    // vecteur permettant de mettre a jour le plateau
    vector<Carte*> etage1;
    vector<Carte*> etage2;
    vector<Carte*> etage3;
    vector<Carte*> etage4;
    vector<Carte*> etage5;
    vector<Carte*> etage6;
    vector<Carte*> etage7;
public:
    PlateauAge(int Age);
    ~PlateauAge();
    Carte**getCartes() const { return cartes; }
    const vector<Carte*>& getDefausses() const { return defausses; }
    void addDefausse(Carte*carte);
    void accessibilite();
    bool deviens_accessible_age1(int &choix);
    bool deviens_accessible_age2(int &choix);
    bool deviens_accessible_age3(int &choix);
    vector<Carte*>  trouver_etage_age1(int& choix);
    vector<Carte*>  trouver_etage_age2(int &choix);
    vector<Carte*> trouver_etage_age3(int &choix);
    void destruction_carte_plateau_age1(int &choix);
    void destruction_carte_plateau_age2(int &choix);
    void destruction_carte_plateau_age3(int &choix);
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

    JetonProgres** jetonProgres = nullptr;
public:
    PlateauJetonMilit();
    ~PlateauJetonMilit();
};

#endif /* PLATEAU_H */