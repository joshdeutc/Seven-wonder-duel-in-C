#ifndef CARTE_H
#define CARTE_H
#include <iostream>
#include <string>
using namespace std;

#include "joueur.h"
#include "pioche.h"
#include "partie.h"

enum Ressource{
    bois,
    argile,
    pierre,
    verre,
    papyrus
};

enum statut{
    defausse,
    joueur1,
    joueur2,
    centre
};

enum SymboleScientifique{roue,plume,globe,bol,horloge,A,balance};

class Carte{
    protected:
        string nom;
        unsigned int cout_piece;
        unsigned int cout_bois;
        unsigned int cout_argile;
        unsigned int cout_pierre;
        unsigned int cout_verre;
        unsigned int cout_papyrus;
        Partie* p = nullptr;        
    public:
        int prix_final_j1(const Joueur& j1,const Joueur& j2);
        Carte(const string& n,const unsigned int cout_piece, const unsigned int cout_bois, const unsigned int cout_argile, const unsigned int cout_pierre, const unsigned int cout_verre, const unsigned int cout_papyrus);
};

class Batiment : public Carte{
protected:
    int age; // peux pas depasser 3
    bool face_visible;
    bool accesible;
    statut st;
    unsigned int nb_bois = 0;
    unsigned int nb_argile = 0;
    unsigned int nb_pierre = 0;
    unsigned int nb_verre = 0;
    unsigned int nb_papyrus = 0;
public:
    int get_nb_bois() const{return nb_bois;}
    int get_nb_argile() const{return nb_argile;}
    int get_nb_pierre() const{return nb_pierre;}
    int get_nb_verre() const{return nb_verre;}
    int get_nb_papyrus() const{return nb_papyrus;}

public:
    const Batiment& chainage(const Batiment& b2);
    void setStatut(statut s) {st = s;};
};

class Matiere_Premiere : public Batiment {
private:
    // Ressources
    string type = "Matiere_Premiere";
};

class Matiere_Manufacture : public Batiment{
private :
    string type="Matiere_Manufacture";
    // Ressources
};


class Civil : public Batiment{
private:
    int point;
};

class Scientifique : public Batiment{
private:
    int point;
    SymboleScientifique sym;// dans joueur il serais bien de faire une liste de liste de symbole
};

class Commerce : public Batiment{
private:
    string type="Commerce";
    // Ressources
    int points;
    int solde_apporte;
    Ressource affecte;
};

class Guilde : public Batiment{
private:
    bool piece;
    int points;
};

class Militaire : public Batiment{
private:
    int bouclier;
};

class Merveille : public Carte{
private:
    // Ressources
    unsigned int nb_bois = 0;
    unsigned int nb_argile = 0;
    unsigned int nb_pierre = 0;
    unsigned int nb_verre = 0;
    unsigned int nb_papyrus = 0;
    int points;
    int argent_app;
    Ressource affecte;
    bool tirage_trois_jetons;
    bool construite;
public:
    int get_nb_bois() const{return nb_bois;}
    int get_nb_argile() const{return nb_argile;}
    int get_nb_pierre() const{return nb_pierre;}
    int get_nb_verre() const{return nb_verre;}
    int get_nb_papyrus() const{return nb_papyrus;}
};
#endif