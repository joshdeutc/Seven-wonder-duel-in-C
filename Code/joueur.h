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
    int solde = 7;
    int ressources_prod[NB_RESSOURCES] = {0,0,0,0,0}; //Inutile de stocker la valeur nulle
    int ressources_non_prod[NB_RESSOURCES] = {0,0,0,0,0}; //Inutile de stocker la valeur nulle
    int symboles[NB_SYMB] = {0,0,0,0,0,0,0}; //On se servira de l'enum pour acceder aux symboles par leur nom
    const Carte** cartes;
    int nb_cartesMax = 10; //Taille du tableau de pointeurs vers les cartes construites
    int nb_cartes = 0;
    int nb_merveilles_construites = 0; //Taille du tableau de pointeurs vers les cartes non construites
    const Merveille* merveillesNonConstruites[7];
    int nb_merveilles_non_construites = 0;
    JetonProgres* jetons[NB_JETONS];
    int nb_jetons=0;
public:
    Joueur(TypeJoueur type_joueur, string identifiant);
    ~Joueur();
    int nbSymboles() const;
    bool doubleSymbole(SymboleScientifique s); // Vaut-il mieux mettre la carte en argument ou son symbole direct?
    void ajouterJeton(JetonProgres* jeton);
    void action();
    bool prixFixe(Ressource r) const;
    void defausser();
    // Ajouter la carte a la cite du joueur, en renseignant si on veut la construire ou non
    void ajouterCarte(const Carte& c, bool construire = false);
    void construireCarte(const Carte& c, const Joueur& other);
    
    void supprimerCarte(const Carte& c);
    
    bool possedeCarte(const Carte& c) const;
    bool estConstruite(const Carte& c) const;
    
    bool possedeChainage(Chainage ch) const;
    int prixFinal(const Carte& c, const Joueur& other) const;
    
    void afficherCartesDeCategorie(TypeCarte typeRecherche, ostream& f=cout) const;
    unsigned int nombreCartesDeCategorie(TypeCarte typeRecherche) const;
    void afficherCartes(ostream& f = cout) const;
    
    int getNbCartes() const { return nb_cartes; }
    int getNbJetons() const { return nb_jetons; }
    int getSolde() const { return solde; }
    void setSolde(int s) { solde = s; }
    int getPoints() const { return points; }
    void addPoints(int p) { points += p; }
    const int* getRessourcesProduites() const { return ressources_prod; }
    const Carte** getCartes() const { return cartes; }
    
    int getNbMerveillesConstruites() const {return nb_merveilles_construites;}
    
    //Affichage
    void afficher(std::ostream& f= cout) const;
    
    //Stratégies d'IA
    int choixEntier(int *tab, int n taille) const;
};






#endif