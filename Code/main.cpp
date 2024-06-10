#include "partie.h"
#include "jeu.h"

int main(int argc, char const *argv[])
{
    // ******************* PARTIE TEST JOSHUA ******************* //
    int tab_ressourcesgratuites_jetons[NB_RESSOURCES];
    int tab_ressourcesgratuites_cartes[NB_RESSOURCES];
    // démarrage du Jeu //
    Jeu::getInstance();
    // choix des types de joueurs et  instanciation partie//
    cout<<"Choissisez le type du premier joueur : 0 pour humain, 1 pour IA"<<endl;
    int type1;cin>>type1;
    cout<<"Choissisez le type du deuxieme joueur : 0 pour humain, 1 pour IA"<<endl;
    int type2;cin>>type2;
    if(type1==0) {
        cout<<"Entrez le nom du premier joueur"<<endl;
        string nom1;cin>>nom1;
        Joueur j1(humain,nom1);
        if(type2==0) {
            cout<<"Entrez le nom du deuxieme joueur"<<endl;
            string nom2;cin>>nom2;
            Joueur j2(humain,nom2);
            Partie p(humain,humain,nom1,nom2);
            // choix des merveilles //

            p.choix_merveilles();

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
                p.fin_age();
            }
        }
        else {
            Joueur j2(IA_aleatoire,"IA2");
            Partie p(humain,IA_aleatoire,nom1,"IA2");
            // choix des merveilles //

            p.choix_merveilles();

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
                p.fin_age();
            }
        }

    }
    else {
        Joueur j1(IA_aleatoire,"IA1");
        if(type2==0) {
            cout<<"Entrez le nom du deuxieme joueur"<<endl;
            string nom2;cin>>nom2;
            Joueur j2(humain,nom2);
            Partie p(IA_aleatoire,humain,"IA1",nom2);
            // choix des merveilles //

            p.choix_merveilles();

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
                p.fin_age();
            }
        }
        else {
            Joueur j2(IA_aleatoire,"IA2");
            Partie p(IA_aleatoire,IA_aleatoire,"IA1","IA2");
            // choix des merveilles //

            p.choix_merveilles();

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
                p.fin_age();
            }
        }

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