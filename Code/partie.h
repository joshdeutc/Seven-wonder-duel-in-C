#ifndef PARTIE_H
#define PARTIE_H


#include "plateau.h"
#include "jeu.h"
#include "joueur.h"
#include "carte_bat_merv.h"

using namespace std;


class Partie
{
private:
    signed int solde_militaire = 0;
    int age = 1; // {1,2,3}
    int merveille_construite = 0;
    int tour = 0; // {1,0} : Au tour de joueur 1 ou 2
    int nb_tour = 0;
    vector<Carte*> defausses;
    Joueur* vainqueur = nullptr;
    bool match_nul = false;
    static int tab_ressourcesgratuites_jeton[NB_RESSOURCES];
    static int tab_ressourcesgratuites_cartes[NB_RESSOURCES];
    Jeu* jeu;
    PlateauAge* platAge;
    PlateauJetonMilit* platMilitaire;
    PlateauMerveille* platMerveille;
    PlateauJetonProgres* platProgres;
    Joueur* joueurs[2] = {nullptr,nullptr};

    static int free_res_jetons[NB_RESSOURCES];
    static int free_res_cartes[NB_RESSOURCES];
public:
    Partie();
    ~Partie();
    void tour_suivant();
    bool fin_age();
    void choix_merveilles();
    void victoire_militaire();
    void victoire_scientifique(Joueur& j);
    void change_solde_militaire(bool current,int nb_boucliers);
    void victoire_civile();
    void addDefausse(Carte*carte);
    const vector<Carte*>& getDefausses() const { return defausses; }
    
    // pour faire une action avec un joueur
    void selection_action();
    bool construire_batiment();
    bool construire_merveille();
    bool defausser();
    
    void choix_jeton(Joueur &j);
    Joueur* autre_joueur();

    Joueur* const* getJoueurs() const { return joueurs; }
    void afficherSoldeMilitaire();
    Joueur* getVainqueur() const { return vainqueur; }
    int get_tour() const { return tour; }

    void initJoueurs();
    void jouer();
};




#endif