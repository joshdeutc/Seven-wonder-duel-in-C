#ifndef JOUEUR_H
#define JOUEUR_H
#include <iostream>
#include <string>
#include "carte_bat_merv.h"

using namespace std;

#define NB_SYMB 6

class Joueur{
    string type;
    string id;
    int points;
    int solde;
    int symboles[7]; //On se servira de l'enum pour acceder aux symboles par leur nom
    // ******** utilisation d'un tableau par type de batiment, qu'on souhaite remplacer par un seul tableau Batiment** par la suite ******** //
    Commerce ** tab_commerce;
    Matiere_Premiere ** tab_matiere;
    Produit_Manufacture ** tab_manufacture;
    Civil ** tab_civil;
    Scientifique ** tab_scientifique;
    Guilde ** tab_guilde;
    Militaire ** tab_militaire;
    // ********************************* //
    int nb_com = 0;
    int nb_pre = 0;
    int nb_manu = 0;
    int nb_civ = 0;
    int nb_sci = 0;
    int nb_gui = 0;
    int nb_mil = 0;
    int nb_bat = 0;
    int nb_merveille = 0;
    int nb_mer = 0;
    Merveille** tab_merveille;
    Batiment** tab_batiment;
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
    Commerce** get_tab_commerce() const {return tab_commerce;}
    Matiere_Premiere** get_tab_premiere() const {return tab_matiere;}
    Produit_Manufacture** get_tab_manufacture() const {return tab_manufacture;}
    Civil** get_tab_civil() const {return tab_civil;}
    Scientifique** get_tab_scientifique() const {return tab_scientifique;}
    Guilde** get_tab_guilde() const {return tab_guilde;}
    Militaire** get_tab_militaire() const {return tab_militaire;}
    Batiment** get_tab_batiment() const {return tab_batiment;}
    Merveille** get_tab_merveille() const {return tab_merveille;}
    int get_solde() const {return solde;}
    void set_solde(int &s) { solde=s;}
    void add_carte(const Carte& c);
};





#endif