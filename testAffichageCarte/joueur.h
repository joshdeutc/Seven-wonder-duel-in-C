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
    void ajouterJeton(JetonProgres* jeton);
    void action();
    bool prixFixe(Ressource r);
    void defausser();
    void ajouterCarte(const Carte& c);
    void construireCarte(const Carte& c);
    void supprimerCarte(const Carte& c);
    bool possede_chainage(string Nom_Chaine);
    int get_couleur(TypeCarte couleur1,TypeCarte couleur2);
    void afficherCartesDeCategorie(TypeCarte typeRecherche, ostream& f);
    unsigned int nombreCartesDeCategorie(TypeCarte typeRecherche);
    int getNbCartes() const {return nb_cartes;}
    int getNbJetons() const {return nb_jetons;}
    int getSolde() const {return solde;}
    void setSolde(int s) {solde += s;}
    int getPoints() const {return points;}
    void setPoints(int p) {points = p;}
    const Carte** getCartes() const {return cartes;}
    bool operator==(const Joueur& other) const {
        return id == other.id;
    }
};






#endif