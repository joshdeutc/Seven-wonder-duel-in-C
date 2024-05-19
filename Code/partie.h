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
    void selection_action(Joueur* j); //Fonction que doit faire Joshua. C'est celle qui permet au joueur j de choisir
    //ce qu'il veut faire (construire un batiment ou une merveille)
    // IL EXISTE UNE FONCTION DOUBLE_SYMBOLE(STRING S) DANS LA CLASSE JOUEUR QUI PERMET DE VÉRIFIER SI LE SYMBOLE ENTRÉ
    // EN ARGUMENT EST DÉJÀ DANS LA CITÉ DU JOUEUR!! IL FAUT UTILISER CETTE FONCTION QD ON CONSTRUIT UN BATIMENT
    //SCIENTIFIQUE POUR SAVOIR SI LE JOUEUR PEUT CHOISIR UN JETON!!
    void choix_jeton(Joueur* j); //Fonction appelée par selection_action() si le joueur a choisi une action qui permet
    //de construire un jeton (par ex si il a construit un batiment scientifique et que ça lui a apporté un symbole
    //identique à un de ceux qu'il a déjà dans sa cité). Cette fonction permet donc au joueur de sélectionner le jeton
    //qu'il souhaite. Il faut que cette méthode appelle la méthode de joueur ajouter_jeton() une fois le jeton choisi
    // car cette méthode de joueur s'occupe de mettre ses attributs à jour.
    void victoire_scientifique(Joueur j);
    void change_solde_militaire(signed int nb_boucliers);
    void victoire_militaire();
    void victoire_civile();
};

#endif