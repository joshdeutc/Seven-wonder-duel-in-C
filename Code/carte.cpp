#include "carte_bat_merv.h"
#include "joueur.h"

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

int* verifier_ressource(const Joueur &j1){
    int tab_verif_aff[5];
    while(j1.get_tab_commerce()){
        if(j1.get_tab_commerce()->get_aff()==bois){
            tab_verif_aff[0]=1;
        }
        if(j1.get_tab_commerce()->get_aff()==argile){
            tab_verif_aff[1]=1;
        }
        if(j1.get_tab_commerce()->get_aff()==pierre){
            tab_verif_aff[2]=1;
        }
        if(j1.get_tab_commerce()->get_aff()==verre){
            tab_verif_aff[3]=1;
        }
        if(j1.get_tab_commerce()->get_aff()==papyrus){
            tab_verif_aff[4]=1;
        }
    }
    return tab_verif_aff;
}



int Carte::prix_final_j1(const Joueur &j1,const Joueur& j2){
    if(Batiment::est_chainée(j1)){
        return 0;
    }
    int res,j;
    res=0;
    int tab_tot_j1[5];
    int tab_tot_j2[5];
    // on compte du joueur j1
    int* tab1 = compter_ressource_merveille(j1.get_tab_merveille());
    int* tab2 = compter_ressource_matiere_premiere(j1.get_tab_manufacture());
    int* tab3 = compter_ressource_matiere_manufact(j1.get_tab_premiere());
    int* tab4 = compter_ressource_commerce(j1.get_tab_commerce());
    // on fait la somme totales des ressources de j1
    for(j=0;j<5;j++){
        tab_tot_j1[j]=tab1[j]+tab2[j]+tab3[j]+tab4[j];
    }
    // on compte les ressources produites par m. manufacture et m. premiere pour j2
    int* tab5 = compter_ressource_matiere_manufact(j2.get_tab_manufacture());
    int* tab6 = compter_ressource_matiere_premiere(j2.get_tab_premiere());
    // on fait la somme totales des ressources de j2
    for(j=0;j<5;j++){
        tab_tot_j2[j]=tab5[j]+tab6[j];
    }
    // verifie si le joueur j1 possède une ou plusieurs affectations de ressource
    int *tab_verif_aff=verifier_ressource(j1);
    // on verifie si le joueur j1 a assez de ressources pour construire la carte
    if(tab_tot_j1[0]<cout_bois){
        if(tab_verif_aff[0]==0){
            res+=(2+tab_tot_j2[0])*cout_bois-tab_tot_j1[0];
        }
        else{
            res+=1;
        }
    }
    if(tab_tot_j1[1]<cout_argile){
        if(tab_verif_aff[1]==0){
            res+=(2+tab_tot_j2[1])*cout_argile-tab_tot_j1[1];
        }
        else {
            res += 1;
        }
    }
    if(tab_tot_j1[2]<cout_pierre){
        if(tab_verif_aff[2]==0){
            res+=(2+tab_tot_j2[2])*cout_pierre-tab_tot_j1[2];
        }
        else {
            res += 1;
        }
    }
    if(tab_tot_j1[3]<cout_verre){
        if(tab_verif_aff[3]==0){
            res+=(2+tab_tot_j2[3])*cout_verre-tab_tot_j1[3];
        }
        else {
            res += 1;
        }
    }
    if(tab_tot_j1[4]<cout_papyrus){
        if(tab_verif_aff[4]==0){
            res+=(2+tab_tot_j2[4])*cout_papyrus-tab_tot_j1[4];
        }
        else {
            res += 1;
        }
    }
    return res+=cout_piece;
}

int Carte::prix_final_j2(const Joueur &j1,const Joueur& j2) {
    if(Batiment::est_chainée(j2)){
        return 0;
    }
    int res, j;
    res = 0;
    int tab_tot_j1[5];
    int tab_tot_j2[5];
    // on compte les ressources du joueur j2
    int *tab1 = compter_ressource_merveille(j2.get_tab_merveille());
    int *tab2 = compter_ressource_matiere_premiere(j2.get_tab_manufacture());
    int *tab3 = compter_ressource_matiere_manufact(j2.get_tab_premiere());
    int *tab4 = compter_ressource_commerce(j2.get_tab_commerce());
    // on fait la somme totales des ressources de j2
    for (j = 0; j < 5; j++) {
        tab_tot_j2[j] = tab1[j] + tab2[j] + tab3[j] + tab4[j];
    }
    // on compte les ressources produites par m. manufacture et m. premiere pour j1
    int *tab5 = compter_ressource_matiere_manufact(j1.get_tab_manufacture());
    int *tab6 = compter_ressource_matiere_premiere(j1.get_tab_premiere());
    // on fait la somme totales des ressources de j1
    for (j = 0; j < 5; j++) {
        tab_tot_j1[j] = tab5[j] + tab6[j];
    }
    // on verifie si le joueur j2 possède une ou plusieurs affectations de ressource
    int *tab_verif_aff = verifier_ressource(j2);

    // on verifie si le joueur j2 a assez de ressources pour construire la carte
    if (tab_tot_j2[0] < cout_bois) {
        if (tab_verif_aff[0] == 0) {
            res += (2 + tab_tot_j1[0]) * cout_bois - tab_tot_j2[0];
        } else {
            res += 1;
        }
    }
    if (tab_tot_j2[1] < cout_argile) {
        if (tab_verif_aff[1] == 0) {
            res += (2 + tab_tot_j1[1]) * cout_argile - tab_tot_j2[1];
        } else {
            res += 1;
        }
    }
    if (tab_tot_j2[2] < cout_pierre) {
        if (tab_verif_aff[2] == 0) {
            res += (2 + tab_tot_j1[2]) * cout_pierre - tab_tot_j2[2];
        } else {
            res += 1;
        }
    }
    if (tab_tot_j2[3] < cout_verre) {
        if (tab_verif_aff[3] == 0) {
            res += (2 + tab_tot_j1[3]) * cout_verre - tab_tot_j2[3];
        } else {
            res += 1;
        }
    }
    if (tab_tot_j2[4] < cout_papyrus) {
        if (tab_verif_aff[4] == 0) {
            res += (2 + tab_tot_j1[4]) * cout_papyrus - tab_tot_j2[4];
        } else {
            res += 1;
        }
    }
    return res += cout_piece;
}