#ifndef CARTE_BATIMENT_MERVEILLE_H
#define CARTE_BATIMENT_MERVEILLE_H
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

enum SymboleScientifique{
    roue,
    plume,
    globe,
    bol,
    horloge,
    A,
    balance
};

class Carte{
protected:
    string nom;
    unsigned int cout_piece;
    unsigned int cout_bois;
    unsigned int cout_argile;
    unsigned int cout_pierre;
    unsigned int cout_verre;
    unsigned int cout_papyrus;
public:
    int prix_final_j1(const Joueur& j1,const Joueur& j2);
    int prix_final_j2(const Joueur& j1,const Joueur& j2);
 Carte(const string& n, const unsigned int &cout_piece, const unsigned int &cout_bois, const unsigned int &cout_argile,
       const unsigned int &cout_pierre, const unsigned int &cout_verre, const unsigned int &cout_papyrus)
: nom(n), cout_piece(cout_piece), cout_bois(cout_bois), cout_argile(cout_argile), cout_pierre(cout_pierre),
 cout_verre(cout_verre), cout_papyrus(cout_papyrus) {}
    string get_nom() const {return nom;}
};

class Batiment : public Carte{
protected:
    int age; // peux pas depasser 3
    bool face_visible;
    bool accesible;
    statut st;
    string chainage;
public:
    void setStatut(statut s) {st = s;};
    statut getStatut() const {return st;};
    void setChainage(const string& c) {chainage = c;};
    const string& getChainage() const {return chainage;};
    static bool est_chainée(const Joueur&j);
    Batiment(const string& n, const unsigned int &cout_piece, const unsigned int &cout_bois, const unsigned int &cout_argile,
             const unsigned int &cout_pierre, const unsigned int &cout_verre, const unsigned int &cout_papyrus,const int &a, const bool &f,
             const bool &ac, const statut &s, const string &c)
             : Carte(n, cout_piece, cout_bois, cout_argile, cout_pierre, cout_verre, cout_papyrus) , age(a), face_visible(f),
             accesible(ac), st(s), chainage(c) {}
};

class Matiere_Premiere : public Batiment {
private:
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
    Matiere_Premiere(const string& n, const unsigned int &cout_piece, const unsigned int &cout_bois, const unsigned int &cout_argile,
                     const unsigned int &cout_pierre, const unsigned int &cout_verre, const unsigned int &cout_papyrus,const int &a, const bool &f,
                     const bool &ac, const statut &s, const string &c, const unsigned int &nb_bois, const unsigned int &nb_argile,
                     const unsigned int &nb_pierre, const unsigned int &nb_verre, const unsigned int &nb_papyrus)
                     : Batiment(n, cout_piece, cout_bois, cout_argile, cout_pierre, cout_verre, cout_papyrus, a, f, ac, s, c),
                     nb_bois(nb_bois), nb_argile(nb_argile), nb_pierre(nb_pierre), nb_verre(nb_verre), nb_papyrus(nb_papyrus) {}
};

class Matiere_Manufacture : public Batiment{
private :
//    string type="Matiere_Manufacture";
    // Ressources
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
    Matiere_Manufacture(const string& n, const unsigned int &cout_piece, const unsigned int &cout_bois, const unsigned int &cout_argile,
                        const unsigned int &cout_pierre, const unsigned int &cout_verre, const unsigned int &cout_papyrus,const int &a, const bool &f,
                        const bool &ac, const statut &s, const string &c, const unsigned int &nb_bois, const unsigned int &nb_argile,
                        const unsigned int &nb_pierre, const unsigned int &nb_verre, const unsigned int &nb_papyrus)
                        : Batiment(n, cout_piece, cout_bois, cout_argile, cout_pierre, cout_verre, cout_papyrus, a, f, ac, s, c),
                        nb_bois(nb_bois), nb_argile(nb_argile), nb_pierre(nb_pierre), nb_verre(nb_verre), nb_papyrus(nb_papyrus) {}
};
class Commerce : public Batiment{
private:
//    string type="Commerce";
    // Ressources
    int points;
    int solde_apporte;
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
    int getPoints() const {return points;}
    int getSolde() const {return solde_apporte;}

};

class Civil : public Batiment{
private:
    int point;
public:
    int getPoint() const {return point;}
};

class Scientifique : public Batiment{
private:
    int point;
    SymboleScientifique sym;
public:
    int getPoint() const {return point;}
    SymboleScientifique getSym() const {return sym;}

};


class Guilde : public Batiment{
private:
    bool piece;
    int points;
public:
    bool getPiece() const {return piece;}
    int getPoints() const {return points;}
};

class Militaire : public Batiment{
private:
    int bouclier;
public:
    int getBouclier() const {return bouclier;}
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

class Jeton : public Carte
{
private:
    /* data */
public:
    Jeton(/* args */);
    ~Jeton();
};

Jeton::Jeton(/* args */)
{
}

Jeton::~Jeton()
{
}

class JetonMilitaire : public Jeton
{
private:
    unsigned int montantSaccage;
public:
    JetonMilitaire(/* args */);
    ~JetonMilitaire();
    int getMontantSaccage() const {return montantSaccage;}
};

JetonMilitaire::JetonMilitaire(/* args */)
{
}

JetonMilitaire::~JetonMilitaire()
{
}

class JetonProgres : public Jeton
{
private:
    string nom;
public:
    JetonProgres(/* args */);
    ~JetonProgres();
    const string& getNom() const {return nom;}
};

JetonProgres::JetonProgres(/* args */)
{
}

JetonProgres::~JetonProgres()
{
}


#endif