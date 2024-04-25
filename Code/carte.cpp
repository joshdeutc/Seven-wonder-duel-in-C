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

int* compter_ressource_commerce(const Commerce** t1){
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
int* compter_ressource_matiere_premiere(const Matiere_Premiere** t1){
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

int* compter_ressource_matiere_manufact(const Matiere_Manufacture** t1){
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
int Carte::prix_final_j1(const Joueur &j1,const Joueur& j2){
    int i=0;
    while(j1.get_tab_batiment()[i] && j1.get_tab_batiment()[i]->get_nom()==j1.get_tab_batiment()[i]->getChainage){
        i++;
    }
    if(j1.get_tab_batiment()[i]->get_nom()==j1.get_tab_batiment()[i]->getChainage){
        return 0;
    }
    int res,j;
    res=0;
    int tab_tot_j1[5];
    int tab_tot_j2[5];
    // on compte du joueur j1
    int* tab1 = compter_ressource_merveille(j1.get_tab_merveille());
    int* tab2 = compter_ressource_matiere_premiere(j1.get_tab_matier_manufacture());
    int* tab3 = compter_ressource_matiere_manufact(j1.get_tab_matier_premiere());
    int* tab4 = compter_ressource_commerce(j1.get_tab_commerce());
    // on fait la somme totales des ressources de j1
    for(j=0;j<5;j++){
        tab_tot_j1[j]=tab1[j]+tab2[j]+tab3[j]+tab4[j];
    }
    // on compte les ressources produites par m. manufacture et m. premiere pour j2
    int* tab5 = compter_ressource_matiere_manufact(j2.get_tab_matier_manufacture());
    int* tab6 = compter_ressource_matiere_premiere(j2.get_tab_matier_premiere());
    // on fait la somme totales des ressources de j2
    for(j=0;j<5;j++){
        tab_tot_j2[j]=tab5[j]+tab6[j];
    }
    // on verifie si le joueur j1 a assez de ressources pour construire la carte
    if(tab_tot_j1[0]<cout_bois){
        res+=2+tab_tot_j2[0];
    }
    if(tab_tot_j1[1]<cout_argile){
        res+=2+tab_tot_j2[1];
    }
    if(tab_tot_j1[2]<cout_pierre){
        res+=2+tab_tot_j2[2];
    }
    if(tab_tot_j1[3]<cout_verre){
        res+=2+tab_tot_j2[3];
    }
    if(tab_tot_j1[4]<cout_papyrus){
        res+=2+tab_tot_j2[4];
    }
    return res+=cout_piece;
}

int Carte::prix_final_j2(const Joueur &j1,const Joueur& j2) {
    int i = 0;
    while (j2.get_tab_batiment()[i] && j2.get_tab_batiment()[i]->get_nom() == j2.get_tab_batiment()[i]->getChainage) {
        i++;
    }
    if (j2.get_tab_batiment()[i]->get_nom() == j2.get_tab_batiment()[i]->getChainage) {
        return 0;
    }
    int res, j;
    res = 0;
    int tab_tot_j1[5];
    int tab_tot_j2[5];
    // on compte les ressources du joueur j2
    int *tab1 = compter_ressource_merveille(j2.get_tab_merveille());
    int *tab2 = compter_ressource_matiere_premiere(j2.get_tab_matier_manufacture());
    int *tab3 = compter_ressource_matiere_manufact(j2.get_tab_matier_premiere());
    int *tab4 = compter_ressource_commerce(j2.get_tab_commerce());
    // on fait la somme totales des ressources de j2
    for (j = 0; j < 5; j++) {
        tab_tot_j2[j] = tab1[j] + tab2[j] + tab3[j] + tab4[j];
    }
    // on compte les ressources produites par m. manufacture et m. premiere pour j1
    int *tab5 = compter_ressource_matiere_manufact(j1.get_tab_matier_manufacture());
    int *tab6 = compter_ressource_matiere_premiere(j1.get_tab_matier_premiere());
    // on fait la somme totales des ressources de j1
    for (j = 0; j < 5; j++) {
        tab_tot_j1[j] = tab5[j] + tab6[j];
    }
    // on verifie si le joueur j2 a assez de ressources pour construire la carte
    if (tab_tot_j2[0] < cout_bois) {
        res += 2 + tab_tot_j1[0];
    }
    if (tab_tot_j2[1] < cout_argile) {
        res += 2 + tab_tot_j1[1];
    }
    if (tab_tot_j2[2] < cout_pierre) {
        res += 2 + tab_tot_j1[2];
    }
    if (tab_tot_j2[3] < cout_verre) {
        res += 2 + tab_tot_j1[3];
    }
    if (tab_tot_j2[4] < cout_papyrus) {
        res += 2 + tab_tot_j1[4];
    }
    return res += cout_piece;
}