#ifndef PLATEAU_H
#define PLATEAU_H

#include <iostream>
#include <string>
#include <vector>
#include "jeu.h"
#include "utils.h"

using namespace std;

#include "carte_bat_merv.h"

//class Plateau
//{
//private:
//    //
//public:
//    Plateau(/* args */);
//    ~Plateau();
//    friend class Jeu;
//};
//
//Plateau::Plateau(/* args */)
//{
//}
//
//Plateau::~Plateau()
//{
//}

class PlateauAge
{
private:
    Carte** cartes = nullptr;
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



class PlateauMerveille
{
private:
    Merveille** cartesPremierPhase = nullptr;
    Merveille** cartesDeuxiemePhase = nullptr;
public:
    PlateauMerveille();
    ~PlateauMerveille();
};

class PlateauJetonMilit
{
private:
    bool jetonMilit1_j1 = false;
    bool jetonMilit2_j1 = false;
    bool jetonMilit1_j2 = false;
    bool jetonMilit2_j2 = false;
public:
    PlateauJetonMilit()=default;
    ~PlateauJetonMilit()=default;

    bool getJetonMilit1_j1() const { return jetonMilit1_j1; }
    bool getJetonMilit2_j1() const { return jetonMilit2_j1; }
    bool getJetonMilit1_j2() const { return jetonMilit1_j2; }
    bool getJetonMilit2_j2() const { return jetonMilit2_j2; }
    void setJetonMilit1_j1(bool b) { jetonMilit1_j1 = b; }
    void setJetonMilit2_j1(bool b) { jetonMilit2_j1 = b; }
    void setJetonMilit1_j2(bool b) { jetonMilit1_j2 = b; }
    void setJetonMilit2_j2(bool b) { jetonMilit2_j2 = b; }
};
class PlateauJetonProgres{
private:
    JetonProgres** jetonprogres = nullptr;
public:
    JetonProgres **getJetonProgres() const { return jetonprogres; }
    PlateauJetonProgres();
    ~PlateauJetonProgres();
};
#endif /* PLATEAU_H */