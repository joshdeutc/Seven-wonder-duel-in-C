#ifndef JOUEUR_H
#define JOUEUR_H
#include <iostream>
#include <string>
#include "carte_bat_merv.h"

using namespace std;

#define NB_SYMB 6

enum TypeJoueur{
    humain,
    IA_aleatoire
};

class Joueur{
    TypeJoueur type;
    string id;
    int points = 0;
    int solde = 0;
    int ressources_prod[5] = {0,0,0,0,0};
    int ressources_non_prod[5] = {0,0,0,0,0};
    int symboles[7] = {0,0,0,0,0,0,0}; //On se servira de l'enum pour acceder aux symboles par leur nom
    int nb_batMax = 10; //Taille du tableau de pointeurs vers batiments
    Batiment* batiments[nb_batMax];
    int nb_bat = 0;
    Merveille* merveilles[7];
    int nb_mer = 0;
    JetonProgres* jetons[NB_JETONS];
    int nb_jetons=0;
public:
    Joueur(TypeJoueur type_joueur, string identifiant);
    int nb_symboles() const;
    bool double_symbole(string s); // Vaut-il mieux mettre la carte en argument ou son symbole direct?
    void ajouter_jeton(JetonProgres* jeton);
    void action();
    bool prix_fixe(Ressource r);
    void defausser(Batiment* bat);
    void construire_batiment();
    bool possede_chainage(string Nom_Chaine);
    void construire_merveille();
    int get_couleur(couleur1,couleur2);
    void choisir_merveille();
    int get_solde() const {return solde;}
    void set_solde(int &s) { solde=s;}
    void add_carte(const Carte& c);
};





#endif