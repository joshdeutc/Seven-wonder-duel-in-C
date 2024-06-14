#ifndef PLATEAU_H
#define PLATEAU_H

#include <iostream>
#include <string>
#include <vector>
#include "jeu.h"
#include "utils.h"

using namespace std;

#include "carte_bat_merv.h"

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
    int tab_possibilite[20];
    int nb_possibilites = 0;

public:
    PlateauAge(int Age);
    ~PlateauAge();

    Carte**getCartes() const { return cartes; }
    int* getTabPossibilites() { return tab_possibilite; }
    int getNbPossibilites() { return nb_possibilites; }

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
    void choix_correct(int &choix);
    bool verif_plus_de_cartes();
};



class PlateauMerveille
{
private:
    Merveille** cartesPremierePhase = nullptr;
    Merveille** cartesDeuxiemePhase = nullptr;
    int taille1;
    int taille2;
public:
    PlateauMerveille();
    ~PlateauMerveille();
    void afficher(int phase, ostream& f=cout) const;
    Merveille** getMerveilles(int phase) const;
    void retirerCarte(int phase,int indice);
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

class PlateauJetonProgres {
private:
    JetonProgres** jetonprogres = nullptr;
    JetonProgres** jetonprogres_horsjeu = nullptr; // Servira à la pioche d'un jeton hors jeu
    int taille = 0; // Attribut pour stocker la taille actuelle du plateau
    int taille_horsjeu = 3; // Taille du tableau des jetons hors jeu
public:
    JetonProgres **getJetonProgres() const { return jetonprogres; }
    JetonProgres **getJetonProgresHorsJeu() const { return jetonprogres_horsjeu; }
    int getTaille() const { return taille; } // Méthode pour obtenir la taille actuelle
    int getTailleHorsJeu() const { return taille_horsjeu; } // Méthode pour obtenir la taille actuelle
    PlateauJetonProgres();
    ~PlateauJetonProgres();
    void supprimerJeton(int position); // Méthode pour supprimer un jeton
    void afficherJetons() const;
    void afficherJetonsHorsJeu() const;
};


#endif /* PLATEAU_H */