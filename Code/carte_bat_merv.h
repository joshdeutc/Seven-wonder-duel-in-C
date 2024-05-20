#ifndef CARTE_BATIMENT_MERVEILLE_H
#define CARTE_BATIMENT_MERVEILLE_H
#include <iostream>
#include <string>
using namespace std;
#include <random>
#include "joueur.h"
#include "partie.h"
#define NB_RESSOURCES 5

enum Ressource{
    bois,
    argile,
    pierre,
    verre,
    papyrus
};

/* On peut surement supprimer le statut, car c'est seulement une répétition de ce qui est déjà complètement défini
 par le fait que les cartes sont dans les attributs d'un des joueurs ou d'un plateau. il faut créer un plateau
 défausse.
enum statut{
    defausse,
    joueur1,
    joueur2,
    centre
};
*/
 
enum SymboleScientifique{
    roue,
    plume,
    globe,
    bol,
    horloge,
    A,
    balance
};

enum TypeCarte{
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

enum Chainage{
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

class Carte{
protected:
    string nom;
    unsigned int cout_piece;
    unsigned int cout_bois;
    unsigned int cout_argile;
    unsigned int cout_pierre;
    unsigned int cout_verre;
    unsigned int cout_papyrus;
    TypeCarte type_carte;
public:
    /*
    int prix_final_j1 (const Joueur& j1,const Joueur& j2) const; // on met const pour
                                                                    // que la méthode ne
                                                                    // modifie pas les
                                                                    // attributs
    int prix_final_j2 (const Joueur& j1,const Joueur& j2) const; */
    Carte(const string& n, const unsigned int &cout_piece, const unsigned int &cout_bois, const unsigned int &cout_argile,
           const unsigned int &cout_pierre, const unsigned int &cout_verre, const unsigned int &cout_papyrus)
            : nom(n), cout_piece(cout_piece), cout_bois(cout_bois), cout_argile(cout_argile), cout_pierre(cout_pierre),
            cout_verre(cout_verre), cout_papyrus(cout_papyrus){}
    string get_nom() const {return nom;}
    unsigned int getCoutPiece() const {return cout_piece;}
    unsigned int getCoutBois() const {return cout_bois;}
    unsigned int getCoutArgile() const {return cout_argile;}
    unsigned int getCoutPierre() const {return cout_pierre;}
    unsigned int getCoutVerre() const {return cout_verre;}
    unsigned int getCoutPapyrus() const {return cout_papyrus;}
    TypeCarte getTypeCarte() const {return type_carte;}
     ~Carte() =default;
    
    
    /* DECLARATIONS VIRTUELLES DES METHODES D'ACCES AUX ATTRIBUTS DES CLASSES FILLES DE BATIMENT
            AFIN DE POUVOIR Y ACCEDER A PARTIR D'UN POINTEUR DE TYPE BATIMENT** OU CARTE**      */
    
    //Matiere_Premiere et Produit_Manufacture
    virtual Ressource getRessource() const = 0;
    virtual int getNb() const = 0;
    //Commerce
    virtual bool affecteBois() const = 0;
    virtual bool affecteArgile() const = 0;
    virtual bool affectePierre() const = 0;
    virtual bool affecteVerre() const = 0;
    virtual bool affectePapyrus() const = 0;
    virtual bool engendrePrixFixe() const = 0;
    virtual bool engendreProduction() const = 0;
    virtual int getPoints() const = 0; //Sert aussi pour Civil, Scientifique, Guilde, Merveille
    virtual int getSoldeApporte() const = 0; // Sert aussi pour Merveille
    //Scientifique
    virtual SymboleScientifique getSymbole() const = 0;
    //Guilde
    virtual bool getPiece() const = 0;
    virtual TypeCarte getTypeCarteAffectee() const = 0;
    //Militaire
    virtual int getBoucliers() const = 0;
    //Merveille
    virtual const unsigned int* getRessources() const = 0;
    virtual int getSoldeRetireAdversaire() const = 0;
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
    
};


class Batiment : public Carte{
protected:
    int age; // peux pas depasser 3
    bool face_visible = false;
    bool accesible = false;
    Chainage chainageSortant = aucun; //Cette carte permet de construire gratuitement un autre batiment avec le même chaînage
    Chainage chainageEntrant = aucun; //Condition pour construire cette carte gratuitement par chainage
public:
    const Chainage& getChainageEntrant() const {return chainageEntrant;};
    const Chainage& getChainageSortant() const {return chainageSortant;};
    bool est_chainee() const {return (chainageSortant!=aucun || chainageEntrant!=aucun);}
    Batiment(const string& n, const unsigned int &cout_piece, const unsigned int &cout_bois, const unsigned int &cout_argile,
             const unsigned int &cout_pierre, const unsigned int &cout_verre, const unsigned int &cout_papyrus,
            const int& a, const Chainage &chout = aucun, const Chainage &chin = aucun)
    : Carte(n, cout_piece, cout_bois, cout_argile, cout_pierre, cout_verre,cout_papyrus) , age(a),
    chainageSortant(chout),chainageEntrant(chin){}
    
    /* Il y avait initialement les arguments face_visible(f), accessible(ac), st(s), chainage(c)
     mais ils ne sont pas initialisés à la construction du batiment. ils sont initialisés par plateau.
     */
    ~Batiment() =default;
};

// On pourra preciser le constructeur en verifiant que le type de ressource entre nest ni verre ni papyrus
class Matiere_Premiere : public Batiment {
private:
    Ressource ressource;
    unsigned int nb;
public:
    Ressource getRessource() const{return ressource;}
    int getNb() const{return nb;}
    TypeCarte getTypeCarte() const {return type_carte;}
    Matiere_Premiere(const string& n, const unsigned int &cout_piece, const unsigned int &cout_bois, const unsigned int &cout_argile,
                     const unsigned int &cout_pierre, const unsigned int &cout_verre, const unsigned int &cout_papyrus,
                     const int &age,
                     const Ressource &r, const unsigned int &nbr,
                     const Chainage &chout = aucun, const Chainage &chin = aucun)
                     : Batiment(n, cout_piece, cout_bois, cout_argile, cout_pierre, cout_verre, cout_papyrus,age,chout, chin),
                     ressource(r),nb(nbr){type_carte=matierePremiere;}
    
    ~Matiere_Premiere()=default;
};

class Produit_Manufacture : public Batiment{
private :
    Ressource ressource;
    unsigned int nb = 1; // Optionnel car un bat Produit manufacture ne peut produire qu'un seul truc
public:
    Ressource getRessource() const{return ressource;}
    int getNb() const{return nb;}
    Produit_Manufacture(const string& n, const unsigned int &cout_piece, const unsigned int &cout_bois, const unsigned int &cout_argile,
                const unsigned int &cout_pierre, const unsigned int &cout_verre, const unsigned int &cout_papyrus,
                const int &age,
                const Ressource &r,
                const unsigned int &nbr,
                const Chainage &chout = aucun, const Chainage &chin = aucun)
                : Batiment(n, cout_piece, cout_bois, cout_argile, cout_pierre, cout_verre, cout_papyrus,age,chout,chin),
                ressource(r),nb(nbr) {type_carte=produitManufacture;}
    ~Produit_Manufacture()=default;
};


class Commerce : public Batiment{
private:
// Ressources
    int points;
    int solde_apporte;
    bool prix_fixe; //Indique si le batiment fixe le prix d'une ressource (Douane et Depots)
    bool production; //Indique si le batiment produit une ressource (Forum et Caravanserail)
    bool affecte[NB_RESSOURCES]; //On pourra verifier si la ressource est affectée en testant affecte[nomRessourceDanslEnum]
public:
    bool affecteBois() const{return affecte[bois];}
    bool affecteArgile() const{return affecte[argile];}
    bool affectePierre() const{return affecte[pierre];}
    bool affecteVerre() const{return affecte[verre];}
    bool affectePapyrus() const{return affecte[papyrus];}
    bool engendrePrixFixe() const{return prix_fixe;}
    bool engendreProduction() const{return production;}
    int getPoints() const {return points;}
    int getSoldeApporte() const {return solde_apporte;}
    Commerce(const string &n, const unsigned int &cout_piece, const unsigned int &cout_bois,
             const unsigned int &cout_argile, const unsigned int &cout_pierre,
             const unsigned int &cout_verre,const unsigned int &cout_papyrus,
             const int &age,
             const int &p, const int &solde,
             const bool &fixe_le_prix, const bool &produit_ressource,
             const bool &affecte_bois, const bool &affecte_argile, const bool &affecte_pierre,
             const bool &affecte_verre, const bool &affecte_papyrus,
             const Chainage &chout = aucun, const Chainage &chin = aucun):
             Batiment(n, cout_piece, cout_bois, cout_argile, cout_pierre, cout_verre, cout_papyrus,age,chout,chin),
             points(p),solde_apporte(solde),
             prix_fixe(fixe_le_prix),production(produit_ressource)
             {
                 type_carte = batimentCommerce;
                affecte[bois] = affecte_bois;
                affecte[argile] = affecte_argile;
                affecte[pierre] = affecte_pierre;
                affecte[verre] = affecte_verre;
                affecte[papyrus] = affecte_papyrus;
             }
    ~Commerce()=default;
};

class Civil : public Batiment{
private:
    int points;
public:
    int getPoints() const {return points;}
    Civil(const string& n, const unsigned int &cout_piece, const unsigned int &cout_bois, const unsigned int &cout_argile,
          const unsigned int &cout_pierre, const unsigned int &cout_verre, const unsigned int &cout_papyrus,
           const int& age, const int &p, const Chainage &chout = aucun, const Chainage &chin = aucun)
          : Batiment(n, cout_piece, cout_bois, cout_argile, cout_pierre, cout_verre, cout_papyrus, age, chout,chin),
           points(p) {type_carte = batimentCivil;}
    ~Civil()=default;
};

class Scientifique : public Batiment{
private:
    int points;
    SymboleScientifique symbole;
public:
    int getPoints() const {return points;}
    SymboleScientifique getSymbole() const {return symbole;}
    Scientifique(const string& n, const unsigned int &cout_piece, const unsigned int &cout_bois, const unsigned int &cout_argile,
                 const unsigned int &cout_pierre, const unsigned int &cout_verre, const unsigned int &cout_papyrus,
                 const int& age,
                  const int &p, const SymboleScientifique &sym,const Chainage &chout = aucun, const Chainage &chin = aucun)
                 : Batiment(n, cout_piece, cout_bois, cout_argile, cout_pierre, cout_verre, cout_papyrus, age, chout,chin),
                points(p), symbole(sym) {type_carte=batimentScientifique;}
    ~Scientifique()=default;
};


class Guilde : public Batiment{
private:
    bool piece;
    int points;
    TypeCarte type_carte_affectee;
public:
    bool getPiece() const {return piece;}
    int getPoints() const {return points;}
    TypeCarte getTypeCarteAffectee() const {return type_carte_affectee;}
    Guilde(const string& n, const unsigned int &cout_piece, const unsigned int &cout_bois, const unsigned int &cout_argile,
           const unsigned int &cout_pierre, const unsigned int &cout_verre, const unsigned int &cout_papyrus,
           const int& age,
            const bool &p, const int &po, const TypeCarte &tca, const Chainage &chout = aucun, const Chainage &chin = aucun)
           : Batiment(n, cout_piece, cout_bois, cout_argile, cout_pierre, cout_verre, cout_papyrus,age, chout, chin),
            piece(p), points(po),type_carte_affectee(tca) {type_carte=guilde;}
    ~Guilde()=default;
};

class Militaire : public Batiment{
private:
    int boucliers;
public:
    int getBoucliers() const {return boucliers;}
    Militaire(const string& n, const unsigned int &cout_piece, const unsigned int &cout_bois, const unsigned int &cout_argile,
              const unsigned int &cout_pierre, const unsigned int &cout_verre, const unsigned int &cout_papyrus,
              const int& age, const int &b, const Chainage &chout = aucun, const Chainage &chin = aucun)
              : Batiment(n, cout_piece, cout_bois, cout_argile, cout_pierre, cout_verre, cout_papyrus,age, chout, chin),
              boucliers(b) {type_carte = batimentMilitaire;}
    ~Militaire()=default;
};

class Merveille : public Carte{
private:
    // Ressources
    unsigned int ressources[NB_RESSOURCES]; // Ressources parmi lesquelles la merveille produit au joueur une unite a chaque tour
    int points;
    int solde_apporte;
    int solde_retire_adversaire;
    bool tirage_trois_jetons;
    bool construite = false;
    bool rejouer;
    bool pioche_defausse;
    bool defausse_adversaire; // Pas besoin de renseigner ce champ à la construction d'une merveille qui ne permet pas
                              // de defausser une des cartes de l'adversaire
    TypeCarte carte_defausse_adversaire; // Cet attribut ne sera pas regarde si defausse_adversaire = false
                                         // Dans le constructeur on mettra la valeur par défaut à merveille, ce qui n'a pas d'importance
                                         // si defausse_adversaire est fausse.
public:
    /* Je suis pas sure que ces accesseurs soient necessaires
    int getNbBois() const{return ressources[bois];}
    int getNbArgile() const{return ressources[argile];}
    int getNbPierre() const{return ressources[pierre];}
    int getNbVerre() const{return ressources[verre];}
    int getNbPapyrus() const{return ressources[papyrus];} */
    const unsigned int* getRessources() const { return ressources; }
    int getPoints() const {return points;}
    int getSoldeApporte() const {return solde_apporte;}
    int getSoldeRetireAdversaire() const {return solde_retire_adversaire;}
    bool getTirage() const {return tirage_trois_jetons;}
    bool getConstruite() const {return construite;}
    bool getRejouter() const {return rejouer;}
    bool getPiocheDefausse() const {return pioche_defausse;}
    bool getDefausseAdversaire() const {return defausse_adversaire;}
    TypeCarte getCarteDefausseAdversaire() const {return carte_defausse_adversaire;}
    Merveille(const string& n, unsigned int cout_piece,
              unsigned int cout_bois, unsigned int cout_argile,
              unsigned int cout_pierre, unsigned int cout_verre,
              unsigned int cout_papyrus, unsigned int prod_bois,
              unsigned int prod_argile, unsigned int prod_pierre,
              unsigned int prod_verre, unsigned int prod_papyrus,
              int pts, int argt_app, int argt_rtr_adv, bool tirageJetons, bool permet_de_rejouer, bool piocher_dans_defausse,
              bool permet_defausse_adversaire = false, TypeCarte carte_d_adversaire = merveille) :
        Carte(n, cout_piece, cout_bois, cout_argile, cout_pierre, cout_verre, cout_papyrus),
        points(pts), solde_apporte(argt_app), solde_retire_adversaire(argt_rtr_adv),
        tirage_trois_jetons(tirageJetons), rejouer(permet_de_rejouer),
        pioche_defausse(piocher_dans_defausse),
        defausse_adversaire(permet_defausse_adversaire), carte_defausse_adversaire(carte_d_adversaire)
    {
        ressources[bois] = prod_bois;
        ressources[argile] = prod_argile;
        ressources[pierre] = prod_pierre;
        ressources[verre] = prod_verre;
        ressources[papyrus] = prod_papyrus;
    }
};

class Jeton : public Carte
{
private:
    /* data */
public:
    Jeton(/* args */);
    ~Jeton();
};

class JetonMilitaire : public Jeton
{
private:
    unsigned int montantSaccage;
public:
    JetonMilitaire(unsigned int montant):montantSaccage(montant){}
    ~JetonMilitaire();
    int getMontantSaccage() const {return montantSaccage;}
};

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