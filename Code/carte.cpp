#include "carte.h"


int* compter_ressource_merveille(const Merveille** t1){
    int tab[5];
    int j=0;
    while(t1[j]){
        tab[0]+=t1[j]->get_nb_bois();
        tab[1]+=t1[j]->get_nb_argile();
        tab[2]+=t1[j]->get_nb_pierre();
        tab[3]+=t1[j]->get_nb_verre();
        tab[4]+=t1[j]->get_nb_papyrus();
    }
    return tab;
}
// probleme il faut mettre dans batiment l'apport de ressource même si cela ne donne rien
int* compter_ressource_batiment(const Batiment** t1){
    int tab[5];
    int j=0;
    while(t1[j]){
        tab[0]+=t1[j]->get_nb_bois();
        tab[1]+=t1[j]->get_nb_argile();
        tab[2]+=t1[j]->get_nb_pierre();
        tab[3]+=t1[j]->get_nb_verre();
        tab[4]+=t1[j]->get_nb_papyrus();
    }
    return tab;
}