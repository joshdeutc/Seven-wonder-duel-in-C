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
    vector<Carte*> defausses;
    Joueur* vainqueur = nullptr;
    Jeu* jeu;
    PlateauAge platAge;
    PlateauJetonMilit platMilitaire;
    PlateauMerveille platMerveille;
    PlateauJetonMilit platJeton;
    Joueur* joueurs[2];
public:
    Partie(const TypeJoueur &typJ1,const TypeJoueur &typJ2,string id1,string id2);
    ~Partie();
    void tour_suivant();
    bool fin_age();
    void choix_merveilles();
    void victoire_scientifique(Joueur j);
    void change_solde_militaire(PlateauJetonMilit &platmilit)
    void victoire_militaire();
    void victoire_civile();
    void addDefausse(Carte*carte);
    const vector<Carte*>& getDefausses() const { return defausses; }
    // pour faire une action avec un joueur
    void selection_action(Joueur &j,PlateauAge &platage);
    void choix_jeton(Joueur* j);
};

#endif