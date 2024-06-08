#include "partie.h"
#include "jeu.h"

int main(int argc, char const *argv[])
{
    // ******************* PARTIE TEST JOSHUA ******************* //
    int tab_ressourcesgratuites_jetons[NB_RESSOURCES];
    Joueur j1(humain,"joshua");
    Joueur j2(humain, "Quentin");
    Partie p(humain,humain,"joshua","quentin");

    const Carte* merv=Jeu::getInstance()->rechercherCarte("LA PIREE");
    j1.construireCarte(*merv,j2);
    // le joueur 1 commence

    Joueur* j_current = &j1;

    // boucle de jeu
    while(!p.getVainqueur()) {
        p.selection_action(*j_current);
        if(p.get_tour()==0) {
            p.tour_suivant();
        }
        else if(p.get_tour()==1) {
            p.tour_suivant();
        }
        j_current=p.autre_joueur();
    }





























    /*//Exemple d'utilisation de construireCarte et prixFinal avec les tableaux de choix
    Joueur j1(humain,"Chloe");
    Joueur j2(humain, "Quentin");

    j1.construireCarte(*Jeu::getInstance()->rechercherCarte("CHANTIER"),j2);

    j1.construireCarte(*Jeu::getInstance()->rechercherCarte("EXPLOITATION"),j2);

    j2.construireCarte(*Jeu::getInstance()->rechercherCarte("VERRERIE"),j1);

    j1.construireCarte(*Jeu::getInstance()->rechercherCarte("TRIBUNAL"),j2);

    j1.construireCarte(*Jeu::getInstance()->rechercherCarte("ATELIER"),j2);

    j2.construireCarte(*Jeu::getInstance()->rechercherCarte("FORUM"),j1);

    j2.afficher();
    cout << endl << endl;
    j1.afficher();
    cout << endl << endl;


    int tabcj[NB_RESSOURCES];
    int tabcc[NB_RESSOURCES];
    for(int i=0; i<NB_RESSOURCES; i++){
        tabcj[i]=0;
        tabcc[i]=0;
    }

    j2.choixRessourcesGratuitesJeton(tabcj);
    j2.choixRessourcesGratuitesCartes(tabcc);

    int prix = j2.prixFinal(*Jeu::getInstance()->rechercherCarte("ÉTUDE"),j1,tabcj,tabcc);
    cout << "Prix final de Étude pour joueur 2 : " << prix << endl;*/

    return 0;
}