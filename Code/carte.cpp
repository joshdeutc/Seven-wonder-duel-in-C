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
int* compter_ressource_batiment(const )
int Carte::prix_final_j1(const Joueur &j1,const Joueur& j2){
    int res,j;
    res=0;
    int* tab1 = compter_ressource_merveille(j1.get_tab_merveille());
    int* tab2 = compter_ressource_batiment(j1.get_tab_batiment());
    int* tab3 = compter_ressource_merveille(j2.get_tab_merveille());
    int* tab4 = compter_ressource_batiment(j2.get_tab_batiment());
    for(j=0;j<5;j++){
        if(tab1[j]<)
    }
}
