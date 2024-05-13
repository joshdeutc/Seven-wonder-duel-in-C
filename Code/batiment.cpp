#include "carte_bat_merv.h"


bool Batiment::est_chainée(const Joueur &j) {
    int i = 0;
    while (j.get_tab_batiment()[i] && j.get_tab_batiment()[i]->get_nom() == j.get_tab_batiment()[i]->getChainage) {
        i++;
    }
    if (j.get_tab_batiment()[i]->get_nom() == j.get_tab_batiment()[i]->getChainage) {
        return true;
    }
    return false;
};
Commerce::Commerce(const string &n, const unsigned int &cout_piece,
                   const unsigned int &cout_bois,const unsigned int &cout_argile,
                   const unsigned int &cout_pierre, const unsigned int &cout_verre,
                   const unsigned int &cout_papyrus, const int &a,const bool &f,
                   const bool &ac, const statut &s, const string &c,
                   const int &p, const int &solde,const Ressource &aff,
                   const unsigned int &nb_bois, const unsigned int &nb_argile,
                   const unsigned int &nb_pierre, const unsigned int &nb_verre,
                   const unsigned int &nb_papyrus,const string& t,const int& age)
                   : Batiment::Batiment(n, cout_piece,
                                        cout_bois, cout_argile,
                                        cout_pierre, cout_verre,
                                        cout_papyrus, a, f, ac, s, c,t,age),
                                        points(p), solde_apporte(solde),
                                        affecte(aff){
                                        int taille_rand=0;
                                        int ressource_rand[5];
                                        if(nb_bois>0){
                                            taille_rand++;
                                            ressource_rand[0]=nb_bois;
                                        }
                                        if(nb_argile>0){
                                            taille_rand++;
                                            ressource_rand[1]=nb_argile;
                                        }
                                        if(nb_pierre>0){
                                            taille_rand++;
                                            ressource_rand[2]=nb_pierre;
                                        }
                                        if(nb_verre>0){
                                            taille_rand++;
                                            ressource_rand[3]=nb_verre;
                                        }
                                        if(nb_papyrus>0){
                                            taille_rand++;
                                            ressource_rand[4]=nb_papyrus;
                                        }
                                        int x=rand()%taille_rand + 1;
                                        if(taille_rand){
                                            switch (x){
                                                case 1:
                                                    this->nb_bois=ressource_rand[0];
                                                    break;
                                                case 2:
                                                    this->nb_argile=ressource_rand[1];
                                                    break;
                                                case 3:
                                                    this->nb_pierre=ressource_rand[2];
                                                    break;
                                                case 4:
                                                    this->nb_verre=ressource_rand[3];
                                                    break;
                                                case 5:
                                                    this->nb_papyrus=ressource_rand[4];
                                                    break;
                                            }
                                        }

}



Merveille::Merveille(const string& n, const unsigned int &cout_piece,
                     const unsigned int &cout_bois, const unsigned int &cout_argile,
                     const unsigned int &cout_pierre, const unsigned int &cout_verre,
                     const unsigned int &cout_papyrus, const unsigned int &nb_bois,
                     const unsigned int &nb_argile, const unsigned int &nb_pierre,
                     const unsigned int &nb_verre, const unsigned int &nb_papyrus,
                     const int &p, const bool &t, const bool &c,const string &type,
                     const int& age)
                     // on appelle le constructeur de la classe mère
                     :Carte::Carte(n, cout_piece, cout_bois, cout_argile, cout_pierre,
                                   cout_verre, cout_papyrus,type,age), nb_bois(nb_bois), nb_argile(nb_argile),
                                   nb_pierre(nb_pierre), nb_verre(nb_verre), nb_papyrus(nb_papyrus),
                                   points(p), tirage_trois_jetons(t), construite(c) {
                                    // on regarde combien de ressources on a
                                    int taille_rand=0;
                                    int ressource_rand[5];
                                    if(nb_bois>0){
                                        taille_rand++;
                                        ressource_rand[0]=nb_bois;
                                    }
                                    if(nb_argile>0){
                                        taille_rand++;
                                        ressource_rand[1]=nb_argile;
                                    }
                                    if(nb_pierre>0){
                                        taille_rand++;
                                        ressource_rand[2]=nb_pierre;
                                    }
                                    if(nb_verre>0){
                                        taille_rand++;
                                        ressource_rand[3]=nb_verre;
                                    }
                                    if(nb_papyrus>0){
                                        taille_rand++;
                                        ressource_rand[4]=nb_papyrus;
                                    }
                                    int x=rand()%taille_rand + 1;
                                    // on vérifie que il y a des ressources
                                    if(taille_rand){
                                        // on attribue une ressource aléatoire
                                        switch (x){
                                            case 1:
                                                this->nb_bois=ressource_rand[0];
                                                break;
                                            case 2:
                                                this->nb_argile=ressource_rand[1];
                                                break;
                                            case 3:
                                                this->nb_pierre=ressource_rand[2];
                                                break;
                                            case 4:
                                                this->nb_verre=ressource_rand[3];
                                                break;
                                            case 5:
                                                this->nb_papyrus=ressource_rand[4];
                                                break;
                                        }
                                    }
}



