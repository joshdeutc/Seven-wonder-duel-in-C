#ifndef CARTE_BATIMENT_MERVEILLE_H
#define CARTE_BATIMENT_MERVEILLE_H
#include <iostream>
#include <string>
using namespace std;
#define NB_RESSOURCES 5

enum Ressource {
    nul, // Valeur necessaire pour pouvoir retourner nul s'il n'y a pas de ressource
    bois,
    argile,
    pierre,
    verre,
    papyrus
};

enum SymboleScientifique {
    aucunSymbole, // Valeur necessaire pour pouvoir retourner nul s'il n'y a pas de symbole
    roue,
    plume,
    globe,
    bol,
    horloge,
    A,
    balance
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
    jetonProgres
};

enum Chainage {
    aucun,
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
    tonneau
};

class Carte {
protected:
    string nom;
    unsigned int cout_piece = 0;
    unsigned int cout_bois = 0;
    unsigned int cout_argile = 0;
    unsigned int cout_pierre = 0;
    unsigned int cout_verre = 0;
    unsigned int cout_papyrus = 0;
    TypeCarte type_carte;
public:
    Carte(const string& n, const unsigned int &cout_piece, const unsigned int &cout_bois, const unsigned int &cout_argile,
          const unsigned int &cout_pierre, const unsigned int &cout_verre, const unsigned int &cout_papyrus)
        : nom(n), cout_piece(cout_piece), cout_bois(cout_bois), cout_argile(cout_argile), cout_pierre(cout_pierre),
          cout_verre(cout_verre), cout_papyrus(cout_papyrus) {}

     /*
    int prix_final_j1 (const Joueur& j1,const Joueur& j2) const; // on met const pour
                                                                    // que la méthode ne
                                                                    // modifie pas les
                                                                    // attributs
    int prix_final_j2 (const Joueur& j1,const Joueur& j2) const; */

    string getNom() const { return nom; }
    unsigned int getCoutPiece() const { return cout_piece; }
    unsigned int getCoutBois() const { return cout_bois; }
    unsigned int getCoutArgile() const { return cout_argile; }
    unsigned int getCoutPierre() const { return cout_pierre; }
    unsigned int getCoutVerre() const { return cout_verre; }
    unsigned int getCoutPapyrus() const { return cout_papyrus; }
    TypeCarte getType() const { return type_carte; }
    virtual ~Carte() = default;

    // Déclarations virtuelles des méthodes d'accès aux attributs des classes filles de Batiment
    // afin de pouvoir y accéder à partir d'un pointeur de type Batiment** ou Carte**

    // Matiere_Premiere et Produit_Manufacture
    virtual Ressource getRessource() const { return nul; }
    virtual int getNb() const { return 0; }

    // Commerce
    virtual const bool* getRessourcesAffectees() const { return nullptr; }
    virtual bool engendrePrixFixe() const { return false; }
    virtual bool engendreProduction() const { return false; }

    virtual int getPoints() const { return 0; } // Sert aussi pour Civil, Scientifique, Guilde, Merveille
    virtual int getSoldeApporte() const { return 0; } // Sert aussi pour Merveille

    // Scientifique
    virtual SymboleScientifique getSymbole() const { return aucunSymbole; }

    // Guilde
    virtual bool getPiece() const = 0;
    virtual TypeCarte getTypeCarteAffectee() const = 0;

    // Militaire
    virtual int getBoucliers() const { return 0; }

    // Merveille
    virtual const unsigned int* getRessources() const = 0;
    virtual int getSoldeRetireAdversaire() const { return 0; }
    virtual bool getTirage() const = 0;
    virtual bool getConstruite() const = 0;
    virtual bool getRejouter() const = 0;
    virtual bool getPiocheDefausse() const = 0;
    virtual bool getDefausseAdversaire() const = 0;
    virtual TypeCarte getCarteDefausseAdversaire() const = 0;

    // Batiment
    virtual const Chainage& getChainageEntrant() const = 0;
    virtual const Chainage& getChainageSortant() const = 0;
    virtual bool est_chainee() const = 0;
    virtual bool set_accessible(bool f);
    virtual bool set_face_visible(bool v);
    virtual bool est_accessible() const;
};

class Batiment : public Carte {
protected:
    int age; // peut pas dépasser 3
    bool face_visible = false;
    bool accesible = false;
    Chainage chainageSortant = aucun; // Cette carte permet de construire gratuitement un autre batiment avec le même chaînage
    Chainage chainageEntrant = aucun; // Condition pour construire cette carte gratuitement par chainage
public:
    const Chainage& getChainageEntrant() const override { return chainageEntrant; }
    const Chainage& getChainageSortant() const override { return chainageSortant; }
    bool est_chainee() const override { return (chainageSortant != aucun || chainageEntrant != aucun); }
    bool set_accessible(bool f) override { accesible = f;  }
    bool set_face_visible(bool v) override { face_visible = v; }
    bool est_accessible() const override { return accesible; }
       /* Il y avait initialement les arguments face_visible(f), accessible(ac), st(s), chainage(c)
     dans le constructeur mais ils ne sont pas initialisés à la construction du batiment. ils sont initialisés par plateau.
     */

    Batiment(const string& n, const unsigned int &cout_piece, const unsigned int &cout_bois, const unsigned int &cout_argile,
             const unsigned int &cout_pierre, const unsigned int &cout_verre, const unsigned int &cout_papyrus,
             const int& a, const Chainage &chout = aucun, const Chainage &chin = aucun)
        : Carte(n, cout_piece, cout_bois, cout_argile, cout_pierre, cout_verre, cout_papyrus), age(a),
          chainageSortant(chout), chainageEntrant(chin) {}

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

    Matiere_Premiere(const string& n, const unsigned int &cout_piece, const unsigned int &cout_bois, const unsigned int &cout_argile,
                     const unsigned int &cout_pierre, const unsigned int &cout_verre, const unsigned int &cout_papyrus,
                     const int &age,
                     const Ressource &r, const unsigned int &nbr,
                     const Chainage &chout = aucun, const Chainage &chin = aucun)
        : Batiment(n, cout_piece, cout_bois, cout_argile, cout_pierre, cout_verre, cout_papyrus, age, chout, chin),
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

    Produit_Manufacture(const string& n, const unsigned int &cout_piece, const unsigned int &cout_bois, const unsigned int &cout_argile,
                        const unsigned int &cout_pierre, const unsigned int &cout_verre, const unsigned int &cout_papyrus,
                        const int &age,
                        const Ressource &r,
                        const unsigned int &nbr,
                        const Chainage &chout = aucun, const Chainage &chin = aucun)
        : Batiment(n, cout_piece, cout_bois, cout_argile, cout_pierre, cout_verre, cout_papyrus, age, chout, chin),
          ressource(r), nb(nbr) { type_carte = produitManufacture; }

    ~Produit_Manufacture() = default;
};

class Commerce : public Batiment {
private:
    int points;
    int solde_apporte;
    bool prix_fixe; // Indique si le batiment fixe le prix d'une ressource (Douane et Depots)
    bool production; // Indique si le batiment produit une ressource (Forum et Caravanserail)
    bool affecte[NB_RESSOURCES + 1]; // On pourra verifier si la ressource est affectée en testant affecte[nomRessourceDanslEnum]
public:
    const bool* getRessourcesAffectees() const override { return affecte; }
    bool engendrePrixFixe() const override { return prix_fixe; }
    bool engendreProduction() const override { return production; }
    int getPoints() const override { return points; }
    int getSoldeApporte() const override { return solde_apporte; }

    Commerce(const string &n, const unsigned int &cout_piece, const unsigned int &cout_bois,
             const unsigned int &cout_argile, const unsigned int &cout_pierre,
             const unsigned int &cout_verre, const unsigned int &cout_papyrus,
             const int &age,
             const int &p, const int &sa,
             const bool &prixF, const bool &prod,
             const bool affect[NB_RESSOURCES + 1],
             const Chainage &chout = aucun, const Chainage &chin = aucun)
        : Batiment(n, cout_piece, cout_bois, cout_argile, cout_pierre, cout_verre, cout_papyrus, age, chout, chin),
          points(p), solde_apporte(sa), prix_fixe(prixF), production(prod) {
        for (unsigned int i = 0; i <= NB_RESSOURCES; i++) {
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

    Civil(const string& n, const unsigned int &cout_piece, const unsigned int &cout_bois, const unsigned int &cout_argile,
          const unsigned int &cout_pierre, const unsigned int &cout_verre, const unsigned int &cout_papyrus,
          const int &age,
          const int &p,
          const Chainage &chout = aucun, const Chainage &chin = aucun)
        : Batiment(n, cout_piece, cout_bois, cout_argile, cout_pierre, cout_verre, cout_papyrus, age, chout, chin), points(p) {
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

    Scientifique(const string& n, const unsigned int &cout_piece, const unsigned int &cout_bois, const unsigned int &cout_argile,
                 const unsigned int &cout_pierre, const unsigned int &cout_verre, const unsigned int &cout_papyrus,
                 const int &age,
                 const SymboleScientifique &s, const int &p,
                 const Chainage &chout = aucun, const Chainage &chin = aucun)
        : Batiment(n, cout_piece, cout_bois, cout_argile, cout_pierre, cout_verre, cout_papyrus, age, chout, chin),
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

    Militaire(const string& n, const unsigned int &cout_piece, const unsigned int &cout_bois, const unsigned int &cout_argile,
              const unsigned int &cout_pierre, const unsigned int &cout_verre, const unsigned int &cout_papyrus,
              const int &age,
              const int &b,
              const Chainage &chout = aucun, const Chainage &chin = aucun)
        : Batiment(n, cout_piece, cout_bois, cout_argile, cout_pierre, cout_verre, cout_papyrus, age, chout, chin), boucliers(b) {
        type_carte = batimentMilitaire;
    }

    ~Militaire() = default;
};

class Guilde : public Batiment {
private:
    int points;
    bool piece;
    TypeCarte type_carte_affectee; // Si ce champ est à nul, alors les points sont donnés par la couleur
public:
    bool getPiece() const override { return piece; }
    int getPoints() const override { return points; }
    TypeCarte getTypeCarteAffectee() const override { return type_carte_affectee; }

    Guilde(const string& n, const unsigned int &cout_piece, const unsigned int &cout_bois, const unsigned int &cout_argile,
           const unsigned int &cout_pierre, const unsigned int &cout_verre, const unsigned int &cout_papyrus,
           const int &age,
           const int &p, const bool &m,
           const TypeCarte &tc_affectee,
           const Chainage &chout = aucun, const Chainage &chin = aucun)
        : Batiment(n, cout_piece, cout_bois, cout_argile, cout_pierre, cout_verre, cout_papyrus, age, chout, chin),
          points(p), piece(m), type_carte_affectee(tc_affectee) {
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
    bool rejouter; // Si true, alors on rejoue après avoir construit cette merveille
    bool pioche_defausse; // Si true, alors la merveille permet de piocher dans la défausse
    bool defausse_adversaire; // Si true, alors la merveille permet de défausser une carte à l'adversaire
    TypeCarte carte_defausse_adversaire; // Si ce champ n'est pas nul, la merveille force l'adversaire à défausser ce type de carte
    unsigned int ressources[NB_RESSOURCES + 1]; // Nombre de chaque ressource (jsp si il faut vraiment mettre +1)
public:
    int getPoints() const override { return points; }
    int getSoldeApporte() const override { return solde_apporte; }
    int getSoldeRetireAdversaire() const override { return solde_retire_adversaire; }
    bool getTirage() const override { return tirage; }
    bool getConstruite() const override { return construite; }
    bool getRejouter() const override { return rejouter; }
    bool getPiocheDefausse() const override { return pioche_defausse; }
    bool getDefausseAdversaire() const override { return defausse_adversaire; }
    TypeCarte getCarteDefausseAdversaire() const override { return carte_defausse_adversaire; }
    /* Je suis pas sure que ces accesseurs soient necessaires
        int getNbBois() const{return ressources[bois];}
        int getNbArgile() const{return ressources[argile];}
        int getNbPierre() const{return ressources[pierre];}
        int getNbVerre() const{return ressources[verre];}
        int getNbPapyrus() const{return ressources[papyrus];} */
    const unsigned int* getRessources() const override { return ressources; }

    Merveille(const string& n, const unsigned int &cout_piece, const unsigned int &cout_bois, const unsigned int &cout_argile,
              const unsigned int &cout_pierre, const unsigned int &cout_verre, const unsigned int &cout_papyrus,
              const int &p, const int &sa, const int &sra,
              const bool &t, const bool &r, const bool &pd,
              const bool &da, const TypeCarte &cda,
              const unsigned int res[NB_RESSOURCES + 1])
        : Carte(n, cout_piece, cout_bois, cout_argile, cout_pierre, cout_verre, cout_papyrus), points(p),
          solde_apporte(sa), solde_retire_adversaire(sra), tirage(t), rejouter(r), pioche_defausse(pd),
          defausse_adversaire(da), carte_defausse_adversaire(cda) {
        for (unsigned int i = 0; i <= NB_RESSOURCES; i++) {
            ressources[i] = res[i];
        }
        type_carte = merveille;
    }

    ~Merveille() = default;
};


//Je pense que cette classe est inutile. On peut gerer ca directement avec le plateau militaire
/*
class JetonMilitaire : public Jeton
{
private:
    unsigned int montantSaccage;
public:
    JetonMilitaire(unsigned int montant):montantSaccage(montant){}
    ~JetonMilitaire();
    int getMontantSaccage() const {return montantSaccage;}
};
 */


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
    JetonProgres(const string& n, const unsigned int &cout_piece, const unsigned int &cout_bois, const unsigned int &cout_argile,
                 const unsigned int &cout_pierre, const unsigned int &cout_verre,
                 const unsigned int &cout_papyrus,
                 const unsigned int sld_immediat,const unsigned int pts_immediats,const unsigned int pts_condition,const unsigned int ressources,TypeCarte carte_cdt,
                 bool cdt_chainage,int boucliers_supp,bool rejouer,SymboleScientifique symb) :
                 Carte(n, cout_piece, cout_bois, cout_argile, cout_pierre, cout_verre, cout_papyrus),
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