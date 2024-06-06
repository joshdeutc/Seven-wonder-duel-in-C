#include "partie.h"
#include "jeu.h"

int main(int argc, char const *argv[])
{
//    // Lancement du jeu
//    Jeu *j = Jeu::getInstance();
//
//    // Actions à réaliser pour le bon déroulement du jeu
//
//
//    // Fermeture du jeu
//    j->freeInstance();

    //Exemple d'utilisation de construireCarte et prixFinal avec les tableaux de choix
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
    cout << "Prix final de Étude pour joueur 2 : " << prix << endl;

    //modif
    // modif nadji
    return 0;
}