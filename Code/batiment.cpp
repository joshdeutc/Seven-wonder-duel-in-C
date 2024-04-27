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
Commerce::Commerce(const string &n, const unsigned int &cout_piece, const unsigned int &cout_bois,
                   const unsigned int &cout_argile, const unsigned int &cout_pierre, const unsigned int &cout_verre,
                   const unsigned int &cout_papyrus, const int &a,const bool &f, const bool &ac,
                   const statut &s, const string &c)
    :Batiment::Batiment(n, cout_piece, cout_bois, cout_argile, cout_pierre, cout_verre, cout_papyrus, a, f, ac, s, c)
    {

    }

