#ifndef JOUEUR_H
#define JOUEUR_H
#include <iostream>
#include <string>
#include "carte.h"

using namespace std;

#define NB_SYMB 6

class Joueur{
    string type;
    string id;
    int points;
    int solde;
    int symboles[7]; //On se servira de l'enum pour acceder aux symboles par leur nom
    // ******** proposition josh ******** //
    Commerce ** tab_commerce;
    Matiere_Premiere ** tab_matiere;
    Matiere_Manufacture ** tab_manufacture;
    Civil ** tab_civil;
    Scientifique ** tab_scientifique;
    Guilde ** tab_guilde;
    Militaire ** tab_militaire;
    // ********************************* //
    int nb_bat = 0;
    Merveille** tab_merveille;
    Batiment** tab_batiment;
    int nb_mer = 0;
  /*  Jeton_progres** jetons;*/
public:
    int nb_symboles() const;
    bool double_symbole(string s); // Vaut-il mieux mettre la carte en argument ou son symbole direct?
    bool tirage_jetons(bool en_jeu);
    void action();
    bool prix_fixe(Ressource r);
    void defausser(Batiment& bat);
    void construire_batiment();
    bool possede_chainage(string Nom_Chaine);
    void construire_merveille();
    /*int get_couleur(couleur1,couleur2);*/
    void choisir_merveille();

};




#endif