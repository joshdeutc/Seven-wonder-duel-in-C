#include "jeu.h"
#include "carte.h"

Jeu::Jeu()
{
    Carte** tabCartesAge1 = new Carte*;
    Carte** tabCartesAge2 = new Carte*;
    Carte** tabCartesAge3 = new Carte*;
    Carte** tabCartesGuilde = new Carte*;
    Carte** tabCartesMerveille = new Carte*;
    Carte** tabJetonMilitaire = new Carte*;
    Carte** tabJetonScientifique = new Carte*;

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
    delete[] tabJetonScientifique;
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
