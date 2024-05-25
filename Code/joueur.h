#ifndef JOUEUR_H
#define JOUEUR_H
#include <iostream>
#include <string>
#include "carte_bat_merv.h"

using namespace std;

#define NB_SYMB 7
#define NB_JETONS 10


enum TypeJoueur{
    humain,
    IA_aleatoire
};

class Joueur{
    TypeJoueur type;
    string id;
    int points = 0;
    int solde = 0;
    int ressources_prod[NB_RESSOURCES] = {0,0,0,0,0}; //Inutile de stocker la valeur nulle
    int ressources_non_prod[NB_RESSOURCES] = {0,0,0,0,0}; //Inutile de stocker la valeur nulle
    int symboles[NB_SYMB] = {0,0,0,0,0,0,0}; //On se servira de l'enum pour acceder aux symboles par leur nom
    int nb_cartesMax = 10; //Taille du tableau de pointeurs vers batiments
    const Carte** cartes;
    int nb_cartes = 0;
    JetonProgres* jetons[NB_JETONS];
    int nb_jetons=0;
public:
    Joueur(TypeJoueur type_joueur, string identifiant);
    ~Joueur();
    int nbSymboles() const;
    bool doubleSymbole(SymboleScientifique s); // Vaut-il mieux mettre la carte en argument ou son symbole direct?
    void ajouter_jeton(JetonProgres* jeton);
    void action();
    bool prix_fixe(Ressource r);
    void defausser();
    void ajouter_carte(const Carte& c);
    void construire_carte(const Carte& c);
    bool possede_chainage(string Nom_Chaine);
    void construire_merveille();
    int get_couleur(TypeCarte couleur1,TypeCarte couleur2);
    void choisir_merveille();
};






#endif