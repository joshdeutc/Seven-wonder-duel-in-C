#include "partie.h"

Partie::Partie() {
    platAge = PlateauAge(); // Initialiser le plateau de l'âge
    platMilitaire = PlateauJetonMilit(); // Initialiser le plateau militaire
    platMerveille = PlateauMerveille(); // Initialiser le plateau des merveilles
    platJeton = PlateauJetonMilit(); // Initialiser le plateau des jetons
    joueurs[0] = new Joueur(/* args */); // Créer le joueur 1
    joueurs[1] = new Joueur(/* args */); // Créer le joueur 2
    
    // Autres initialisations si nécessaire
}

Partie::~Partie() {
    // Libérer la mémoire allouée pour le tableau de cartes
    delete[] cartes;
    
    
    // Libérer la mémoire allouée pour les joueurs
    for (int i = 0; i < 2; ++i) {
        delete joueurs[i];
    }

    //Libérer la mémoire plateaux
}

void Partie::tour_suivant(){
    if(tour == 1) tour = 2;
    else tour = 1;
}

void Partie::fin_age(){
    if(platAge.getCartes() == nullptr){//Si il ne reste plus de carte sur le plateau
        if (age == 1) age = 2;
        else if(age == 2) age = 3;
        else victoire_civile(); //age 3 finit, vict civile
    }
}

void Partie::accessibilite(Batiment* CarteCourante){
    //PlateauAge est un tableau de 20 éléments
    //La disposition des cartes est similaire à un arbre pour
    Batiment** tableauCartes = platAge.getCartesPlatAge();

    
}

void Partie::change_solde_militaire(signed int nbBoucliers){
    solde_militaire += nbBoucliers;
    if(abs(solde_militaire) >= 9) victoire_militaire();
}

void Partie::victoire_militaire(){
    if (solde_militaire>9) vainqueur = joueurs[0];
    else vainqueur = joueurs[1];
}

void Partie::victoire_civile(){
    //Parcourir toutes les cartes ainsi que les merveilles construites du joueur, et conversion des pieces en points de pouvoir pour chaque joueur
    //declare un gagnant et un perdant
    unsigned int PtV1 = 0, PtV2 = 0;
    PtV1 += joueurs[0]->getSolde()/3;
    PtV1 += joueurs[1]->getSolde()/3;

    vainqueur =  (PtV1 > PtV2) joueurs[0] : joueurs[1];
}

void Partie::victoire_scientifique(Joueur j){

}

void Partie::distribuer(){
    //methode  qui peut integrer la classe Plateau, methode qui ressemble a celle de la classe controleur de l'ex SET
}