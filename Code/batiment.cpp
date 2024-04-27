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
}


