#include <iostream>
#include <string>
using namespace std;


enum Ressource {bois,argile,pierre,verre,papyrus};
enum statut{defausse,joueur1,joueur2,centre};
enum symbole {roue,plume,globe,bol,horloge,A};



 // **************** // Partie Josh // ******************** //


class Carte{
    protected:
        string nom;
        int cout_piece;
        int tab_ressource[5];
        bool en_jeu;
    public:
        /*prix_final(Joueur& j){ // problème au niveau de la conception pour
        connâitre le nombre de ressources.
        };*/
        Carte(const string& n,const int& ca,const Ressource& cp,const bool& v);
        /* l'attribut ressource est à revoir car il nous faut ici une liste des ressources que l'on possède */

};
class Batiment : public Carte{
protected:
    int age;// peux pas depasser 3
    bool face_visible;
    bool accesible;
    statut st;
public:
    const Batiment& chainage(const Batiment& b2);
};
class Matiere_Premiere : public Batiment{
private:
    Ressource type;
};
class Matiere_Manufacture : public Batiment{
private :
    Ressource type;
};
class Civil : public Batiment{
private:
    int point;
};
class Scientifique : public Batiment{
private:
    int point;
    symbole sym;// dans joueur il serais bien de faire une liste de liste de symbole
};
class Commerce : public Batiment{
private:
    Ressource production;
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
    Ressource production;
    int points;
    int argent_app;
    Ressource affecte;
    bool tirage_trois_jetons;
    bool construite;
};


