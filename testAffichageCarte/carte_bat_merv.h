#ifndef CARTE_BATIMENT_MERVEILLE_H
#define CARTE_BATIMENT_MERVEILLE_H
#include <iostream>
#include <string>
using namespace std;
constexpr int NB_RESSOURCES = 5;

enum Ressource {
    bois,
    argile,
    pierre,
    verre,
    papyrus,
    aucuneRessource // Valeur necessaire pour pouvoir retourner nul s'il n'y a pas de ressource, a laisser en dernier
};

enum SymboleScientifique {
    roue,
    plume,
    globe,
    bol,
    horloge,
    A,
    balance,
    aucunSymbole // Valeur necessaire pour pouvoir retourner nul s'il n'y a pas de symbole, a laisser en dernier
};

enum TypeCarte {
    merveille,
    matierePremiere,
    produitManufacture,
    batimentCivil,
    batimentScientifique,
    batimentCommerce,
    batimentMilitaire,
    guilde,
    jetonProgres,
    aucuneCarte
};

enum Chainage {
    fer,
    epee,
    tour,
    cible,
    casque,
    livre,
    engrenage,
    harpe,
    lampe,
    masque,
    poutre,
    lune,
    soleil,
    goutte,
    temple,
    vase,
    tonneau,
    aucun
};

//Fonctions de conversion des enumerations en string:
ostream& operator<<(ostream& f, Ressource ressource);
ostream& operator<<(ostream& f, SymboleScientifique symbole);
ostream& operator<<(ostream& f, TypeCarte type);
ostream& operator<<(ostream& os, Chainage chainage);



class Carte {
protected:
    string nom;
    unsigned int cout_piece = 0;
    unsigned int cout_ressources[NB_RESSOURCES];
    TypeCarte type_carte;
public:
    Carte(const string& n, const unsigned int &cout_piece, const unsigned int cout_prod[NB_RESSOURCES])
        : nom(n), cout_piece(cout_piece) {
            for (unsigned int i = 0; i < NB_RESSOURCES; i++) {
                cout_ressources[i] = cout_prod[i];
            }
        }
    
    
     /*
    int prix_final_j1 (const Joueur& j1,const Joueur& j2) const; // on met const pour
                                                                    // que la méthode ne
                                                                    // modifie pas les
                                                                    // attributs
    int prix_final_j2 (const Joueur& j1,const Joueur& j2) const; */

    string getNom() const { return nom; }
    unsigned int getCoutPiece() const { return cout_piece; }
    const unsigned int* getCoutRessources() const { return cout_ressources; }
    TypeCarte getType() const { return type_carte; }
    virtual ~Carte() = default;

    // Déclarations virtuelles des méthodes d'accès aux attributs des classes filles de Batiment
    // afin de pouvoir y accéder à partir d'un pointeur de type Batiment** ou Carte**
    

    // Matiere_Premiere et Produit_Manufacture
    virtual Ressource getRessource() const { return aucuneRessource; }
    virtual int getNb() const { return 0; }

    // Commerce
    virtual const bool* getRessourcesAffectees() const { return nullptr; }
    virtual bool engendrePrixFixe() const { return false; }
    virtual bool engendreProduction() const { return false; }

    virtual int getPoints() const { return 0; } // Sert aussi pour Civil, Scientifique, Merveille
    virtual int getSoldeApporte() const { return 0; } // Sert aussi pour Merveille
    virtual int getPieceParCarte() const {return 0;} // Dans cité du joueur concerné

    // Scientifique
    virtual SymboleScientifique getSymbole() const { return aucunSymbole; }

    // Guilde
    virtual int getPieceParCarteMax() const {return 0;} // Dans cité du joueur qui en a le +
    virtual int getPointsParCarte() const { return 0; }
    virtual TypeCarte getTypeCarteAffectee() const {return aucuneCarte;} // Sert aussi pour Commerce
    virtual TypeCarte getDeuxiemeTypeCarteAffectee() const { return aucuneCarte; }
    
    // Militaire
    virtual int getBoucliers() const { return 0; }

    // Merveille
    virtual const unsigned int* getRessources() const {return nullptr;}
    virtual int getSoldeRetireAdversaire() const { return 0; }
    virtual bool getTirage() const {return false;}
    virtual bool getConstruite() const {return false;}
    virtual bool getRejouer() const {return false;}
    virtual bool getPiocheDefausse() const {return false;}
    virtual bool getDefausseAdversaire() const {return false;}
    virtual TypeCarte getCarteDefausseAdversaire() const {return aucuneCarte;}

    // Batiment
    virtual const Chainage getChainage1() const {return aucun;}
    virtual const Chainage getChainage2() const {return aucun;}
    virtual bool estChainee() const {return false;}
    virtual const int getAge() const {return 0;}
    virtual void set_accessible(bool ac) {}
    virtual void set_face_visible(bool fv) {}
    virtual bool get_accessible() const {return false;}
    virtual bool get_face_visible() const {return false;}

    //Affichage
    void afficher(std::ostream& f= cout) const;
};

class Batiment : public Carte {
protected:
    int age; // peut pas dépasser 3
    bool face_visible = false;
    bool accesible = false;
    Chainage chainage1 = aucun;
    Chainage chainage2 = aucun;
public:
    const int getAge() const override {return age;}
    const Chainage getChainage1() const override { return chainage1; }
    const Chainage getChainage2() const override { return chainage2; }
    bool estChainee() const override { return (chainage1 != aucun || chainage2!=aucun); }
    void set_accessible(bool ac) override { accesible = ac; set_face_visible(true); }
    void set_face_visible(bool fv) override { face_visible = fv; }
    bool get_accessible() const override { return accesible; }
    bool get_face_visible() const override { return face_visible; }

       /* Il y avait initialement les arguments face_visible(f), accessible(ac), st(s), chainage(c)
     dans le constructeur mais ils ne sont pas initialisés à la construction du batiment. ils sont initialisés par plateau.
     */

    Batiment(const string& n, const unsigned int &cout_piece, const unsigned int cout_prod[NB_RESSOURCES],
             const int& a, const Chainage &ch1 = aucun, const Chainage &ch2 = aucun)
        : Carte(n, cout_piece, cout_prod), age(a),
          chainage1(ch1), chainage2(ch2) {}

    ~Batiment() = default;
};

class Matiere_Premiere : public Batiment {
private:
    Ressource ressource;
    unsigned int nb;
public:
    Ressource getRessource() const override { return ressource; }
    int getNb() const override { return nb; }
    TypeCarte getTypeCarte() const { return type_carte; }

    Matiere_Premiere(const string& n, const unsigned int &cout_piece, const unsigned int cout_prod[NB_RESSOURCES],
                     const int &age,
                     const Ressource &r, const unsigned int &nbr,
                     const Chainage &ch1 = aucun, const Chainage &ch2 = aucun)
        : Batiment(n, cout_piece, cout_prod, age, ch1, ch2),
          ressource(r), nb(nbr) { type_carte = matierePremiere; }

    ~Matiere_Premiere() = default;
};

class Produit_Manufacture : public Batiment {
private:
    Ressource ressource;
    unsigned int nb = 1; // Optionnel car un bat Produit manufacture ne peut produire qu'un seul truc
public:
    Ressource getRessource() const override { return ressource; }
    int getNb() const override { return nb; }

    Produit_Manufacture(const string& n, const unsigned int &cout_piece, const unsigned int cout_prod[NB_RESSOURCES],
                        const int &age,
                        const Ressource &r,
                        const unsigned int &nbr,
                        const Chainage &ch1 = aucun, const Chainage &ch2 = aucun)
        : Batiment(n, cout_piece, cout_prod, age, ch1, ch2),
          ressource(r), nb(nbr) { type_carte = produitManufacture; }

    ~Produit_Manufacture() = default;
};

class Commerce : public Batiment {
private:
    int points;
    int solde_apporte;
    bool prix_fixe; // Indique si le batiment fixe le prix d'une ressource (Douane et Depots)
    bool production; // Indique si le batiment produit une ressource (Forum et Caravanserail)
    bool affecte[NB_RESSOURCES]; // On pourra verifier si la ressource est affectée en testant affecte[nomRessourceDanslEnum]
    int piece_par_carte = 0;
    TypeCarte type_carte_affectee = aucuneCarte;
public:
    const bool* getRessourcesAffectees() const override { return affecte; }
    bool engendrePrixFixe() const override { return prix_fixe; }
    bool engendreProduction() const override { return production; }
    int getPoints() const override { return points; }
    int getSoldeApporte() const override { return solde_apporte; }
    int getPieceParCarte() const override {return piece_par_carte;}
    TypeCarte getTypeCarteAffectee() const override { return type_carte_affectee; }

    Commerce(const string &n, const unsigned int &cout_piece, const unsigned int cout_prod[NB_RESSOURCES],
             const int &age,
             const int &p, const int &sa,
             const bool &prixF, const bool &prod,
             const bool affect[NB_RESSOURCES],
             const int piece_p_carte, const TypeCarte carte_aff,
             const Chainage &ch1 = aucun, const Chainage &ch2 = aucun)
        : Batiment(n, cout_piece, cout_prod, age, ch1, ch2),
          points(p), solde_apporte(sa), prix_fixe(prixF), production(prod),
          piece_par_carte(piece_p_carte), type_carte_affectee(carte_aff){
        for (unsigned int i = 0; i < NB_RESSOURCES; i++) {
            affecte[i] = affect[i];
        }
        type_carte = batimentCommerce;
    }

    ~Commerce() = default;
};



class Civil : public Batiment {
private:
    int points;
public:
    int getPoints() const override { return points; }

    Civil(const string& n, const unsigned int &cout_piece, const unsigned int cout_prod[NB_RESSOURCES],
          const int &age,
          const int &p,
          const Chainage &ch1 = aucun, const Chainage &ch2 = aucun)
        : Batiment(n, cout_piece, cout_prod, age, ch1, ch2), points(p) {
        type_carte = batimentCivil;
    }

    ~Civil() = default;
};

class Scientifique : public Batiment {
private:
    SymboleScientifique symbole;
    int points;
public:
    SymboleScientifique getSymbole() const override { return symbole; }
    int getPoints() const override { return points; }

    Scientifique(const string& n, const unsigned int &cout_piece, const unsigned int cout_prod[NB_RESSOURCES],
                 const int &age,
                 const SymboleScientifique &s, const int &p,
                 const Chainage &ch1 = aucun, const Chainage &ch2 = aucun)
        : Batiment(n, cout_piece, cout_prod, age, ch1, ch2),
          symbole(s), points(p) {
        type_carte = batimentScientifique;
    }

    ~Scientifique() = default;
};

class Militaire : public Batiment {
private:
    int boucliers;
public:
    int getBoucliers() const override { return boucliers; }

    Militaire(const string& n, const unsigned int &cout_piece, const unsigned int cout_prod[NB_RESSOURCES],
              const int &age,
              const int &b,
              const Chainage &ch1 = aucun, const Chainage &ch2 = aucun)
        : Batiment(n, cout_piece, cout_prod, age, ch1, ch2), boucliers(b) {
        type_carte = batimentMilitaire;
    }

    ~Militaire() = default;
};

class Guilde : public Batiment {
private:
    int points_par_carte;
    int piece_par_carte;
    // ATTENTION CONTRAIREMENT AUX CARTES COMMERCE
    // LES PIECES APPORTES SONT PAR CARTE DE LA CITE QUI
    // EN POSSEDE LE PLUS (C'EST LA CITE DU JOUEUR CONCERNÉ POUR COMMERCE)
    TypeCarte type_carte_affectee_1; // Si ce champ est à nul, alors les points sont donnés par les pieces
    TypeCarte type_carte_affectee_2;
public:
    int getPieceParCarteMax() const override {return piece_par_carte;}
    int getPointsParCarte() const override {return points_par_carte;}
    TypeCarte getTypeCarteAffectee() const override { return type_carte_affectee_1; }
    TypeCarte getDeuxiemeTypeCarteAffectee() const override { return type_carte_affectee_2; }

    Guilde(const string& n, const unsigned int &cout_piece, const unsigned int cout_prod[NB_RESSOURCES],
           const int &age,
           const int &pts, const int &piece,
           const TypeCarte &tc_affectee,
           const TypeCarte &tc_affectee_2=aucuneCarte)
        : Batiment(n, cout_piece, cout_prod, age),
          points_par_carte(pts), piece_par_carte(piece), 
          type_carte_affectee_1(tc_affectee), type_carte_affectee_2(tc_affectee_2){
        type_carte = guilde;
    }

    ~Guilde() = default;
};

class Merveille : public Carte {
private:
    int points;
    int solde_apporte;
    int solde_retire_adversaire;
    bool tirage; // Si true, alors l'effet de la merveille est de tirer une carte supplémentaire
    bool construite = false;
    bool rejouer; // Si true, alors on rejoue après avoir construit cette merveille
    bool pioche_defausse; // Si true, alors la merveille permet de piocher dans la défausse
    bool defausse_adversaire; // Si true, alors la merveille permet de défausser une carte à l'adversaire
    bool engendre_production;
    TypeCarte carte_defausse_adversaire; // Si ce champ n'est pas nul, la merveille force l'adversaire à défausser ce type de carte
    bool ressources[NB_RESSOURCES]; // Nombre de chaque ressource
public:
    int getPoints() const override { return points; }
    int getSoldeApporte() const override { return solde_apporte; }
    int getSoldeRetireAdversaire() const override { return solde_retire_adversaire; }
    bool getTirage() const override { return tirage; }
    bool getConstruite() const override { return construite; }
    bool getRejouer() const override { return rejouer; }
    bool getPiocheDefausse() const override { return pioche_defausse; }
    bool getDefausseAdversaire() const override { return defausse_adversaire; }
    bool engendreProduction() const override { return engendre_production; }
    TypeCarte getCarteDefausseAdversaire() const override { return carte_defausse_adversaire; }
    /* Je suis pas sure que ces accesseurs soient necessaires
        int getNbBois() const{return ressources[bois];}
        int getNbArgile() const{return ressources[argile];}
        int getNbPierre() const{return ressources[pierre];}
        int getNbVerre() const{return ressources[verre];}
        int getNbPapyrus() const{return ressources[papyrus];} */
    const bool* getRessourcesAffectees() const override { return ressources; }
    Merveille(const string& n, const unsigned int &cout_piece, const unsigned int cout_prod[NB_RESSOURCES],
              const int &p, const int &sa, const int &sra,
              const bool &t, const bool &r, const bool &pd,
              const bool &da, const TypeCarte &cda,
              const bool &engendre_prod,const bool res[NB_RESSOURCES])
        : Carte(n, cout_piece, cout_prod), points(p),
          solde_apporte(sa), solde_retire_adversaire(sra), tirage(t), rejouer(r), pioche_defausse(pd),
          defausse_adversaire(da), carte_defausse_adversaire(cda), engendre_production(engendre_prod) {
        for (unsigned int i = 0; i < NB_RESSOURCES; i++) {
            ressources[i] = res[i];
        }
        type_carte = merveille;
    }

    ~Merveille() = default;
};


class JetonProgres : public Carte {
private:
    const unsigned int solde_apporte;
    const unsigned int points_immediats;
    const unsigned int points_condition;
    const unsigned int ressources_gratuites; // Si >0, le joueur choisira lesquelles a chaque tour
    const TypeCarte carte_condition;
    const unsigned int boucliers_supplementaires;
    const bool effet_rejouer;
    const bool condition_chainage;
    SymboleScientifique symbole;
public:
    JetonProgres(const string& n, const unsigned int &cout_piece, const unsigned int cout_prod[NB_RESSOURCES],
                 const unsigned int sld_immediat,const unsigned int pts_immediats,
                 const unsigned int pts_condition,const unsigned int ressources,TypeCarte carte_cdt,
                 bool cdt_chainage,int boucliers_supp,bool rejouer,SymboleScientifique symb) :
                 Carte(n, cout_piece, cout_prod),
                 solde_apporte(sld_immediat), points_immediats(pts_immediats), points_condition(pts_condition),
                 ressources_gratuites(ressources), carte_condition(carte_cdt), boucliers_supplementaires(boucliers_supp),
                 effet_rejouer(rejouer), condition_chainage(cdt_chainage), symbole(symb) {
        type_carte = jetonProgres;
    }
    
    int getPoints() const override { return points_immediats; }
    int getPointsCondition() const { return points_condition; }
    int getSoldeApporte() const override { return solde_apporte; }
    int getRessourcesGratuites() const { return ressources_gratuites; }
    TypeCarte getTypeCarteCondition() const { return carte_condition; }
    int getBoucliers() const override { return boucliers_supplementaires; }
    bool getEffetRejouer() const { return effet_rejouer; }
    bool getCondChainage() const { return condition_chainage; }
    SymboleScientifique getSymbole() const override { return symbole; }

    ~JetonProgres() = default;
};

#endif