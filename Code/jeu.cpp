#include "jeu.h"
#include "carte_bat_merv.h"


Jeu::Jeu()
{
    tabCartesAge1 = new Batiment*;
    tabCartesAge2 = new Batiment*;
    tabCartesAge3 = new Batiment*;
    tabCartesGuilde = new Guilde*;
    tabCartesMerveille = new Merveille*;
    tabJetonMilitaire = new JetonMilitaire*;
    tabJetonProgres = new JetonProgres*;

    // Il faudra initialiser toutes les cartes ici
    
}

Jeu::~Jeu()
{
    delete[] tabCartesAge1;
    delete[] tabCartesAge2;
    delete[] tabCartesAge3;
    delete[] tabCartesGuilde;
    delete[] tabCartesMerveille;
    delete[] tabJetonMilitaire;
    delete[] tabJetonProgres;
}

Jeu* Jeu::getInstance(){
    if (instance == nullptr)
    {
        instance = new Jeu;
    }
    return instance;
}

void Jeu::freeInstance(){
    delete instance;
    instance = nullptr;
}
