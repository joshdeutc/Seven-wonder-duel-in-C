#ifndef CARTE_H
#define CARTE_H
#include <iostream>
#include <string>
using namespace std;

#include "joueur.h"

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
        int cout_piece;
        bool en_jeu;
    public:
        int prix_final(Joueur& j);
        Carte(const string& n,const int& ca,const Ressource& cp,const bool& v);
        /* l'attribut ressource est à revoir car il nous faut ici une liste des ressources que l'on possède */

};

class Batiment : public Carte{
protected:
    int age; // peux pas depasser 3
    bool face_visible;
    bool accesible;
    statut st;
public:
    const Batiment& chainage(const Batiment& b2);
    void setStatut(statut s) {st = s;};
};

class Matiere_Premiere : public Batiment{
private:
    // Ressources
    unsigned int nb_bois = 0;
    unsigned int nb_argile = 0;
    unsigned int nb_pierre = 0;
    unsigned int nb_verre = 0;
    unsigned int nb_papyrus = 0;
};

class Matiere_Manufacture : public Batiment{
private :
    // Ressources
    unsigned int nb_bois = 0;
    unsigned int nb_argile = 0;
    unsigned int nb_pierre = 0;
    unsigned int nb_verre = 0;
    unsigned int nb_papyrus = 0;
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
    // Ressources
    unsigned int nb_bois = 0;
    unsigned int nb_argile = 0;
    unsigned int nb_pierre = 0;
    unsigned int nb_verre = 0;
    unsigned int nb_papyrus = 0;

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
};
#endif