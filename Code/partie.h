#ifndef PARTIE_H
#define PARTIE_H


#include "plateau.h"
#include "jeu.h"
#include "joueur.h"
#include "carte_bat_merv.h"
class Partie
{
private:
    signed int solde_militaire = 0;
    int age = 1; // {1,2,3}
    int merveille_construite = 0;
    int tour = 1; // {1,2} : Au tour de joueur 1 ou 2
    int nb_tour = 0;
    Joueur* vainqueur = nullptr;

    Jeu* jeu;
    PlateauAge platAge;
    PlateauJetonMilit platMilitaire;
    PlateauMerveille platMerveille;
    PlateauJetonMilit platJeton;
    Joueur* joueurs[2];
public:
    Partie();
    ~Partie();
    void tour_suivant();
    void fin_age();
    void choix_merveilles();
    void victoire_scientifique(Joueur j);
    void change_solde_militaire(signed int nb_boucliers);
    void victoire_militaire();
    void victoire_civile();
};

#endif