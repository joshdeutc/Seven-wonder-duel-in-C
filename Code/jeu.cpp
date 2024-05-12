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

    // Jetons Militaires
        // Joueur 1
    JetonMilitaire* jetonMilitaire2_1 = new JetonMilitaire(2);
    JetonMilitaire* jetonMilitaire5_1 = new JetonMilitaire(5);
    tabJetonMilitaire[0] = jetonMilitaire2_1;
    tabJetonMilitaire[1] = jetonMilitaire5_1;

        // Joueur 2
    JetonMilitaire* jetonMilitaire2_2 = new JetonMilitaire(2);
    JetonMilitaire* jetonMilitaire5_2 = new JetonMilitaire(5);
    tabJetonMilitaire[2] = jetonMilitaire2_2;
    tabJetonMilitaire[3] = jetonMilitaire5_2;

    // Jetons Progrès
    JetonProgres *jetonProgresAgriculture = new JetonProgres("Agriculture");
    JetonProgres *jetonProgresArchitecture = new JetonProgres("Architecture");
    JetonProgres *jetonProgresEconomie = new JetonProgres("Economie");
    JetonProgres *jetonProgresLoi = new JetonProgres("Loi");
    JetonProgres *jetonProgresMaçonnerie = new JetonProgres("Maçonnerie");
    JetonProgres *jetonProgresMathematiques = new JetonProgres("Mathematiques");
    JetonProgres *jetonProgresPhilosophie = new JetonProgres("Philosophie");
    JetonProgres *jetonProgresStrategie = new JetonProgres("Strategie");
    JetonProgres *jetonProgresTheologie = new JetonProgres("Theologie");
    JetonProgres *jetonProgresUrbanisme = new JetonProgres("Urbanisme");
    tabJetonProgres[0] = jetonProgresAgriculture;
    tabJetonProgres[1] = jetonProgresArchitecture;
    tabJetonProgres[2] = jetonProgresEconomie;
    tabJetonProgres[3] = jetonProgresLoi;
    tabJetonProgres[4] = jetonProgresMaçonnerie;
    tabJetonProgres[5] = jetonProgresMathematiques;
    tabJetonProgres[6] = jetonProgresPhilosophie;
    tabJetonProgres[7] = jetonProgresStrategie;
    tabJetonProgres[8] = jetonProgresTheologie;
    tabJetonProgres[9] = jetonProgresUrbanisme;

    // Merveilles
    // Merveille(const string& nom, const unsigned int cout_piece,
    //         const unsigned int cout_bois, const unsigned int cout_argile,
    //         const unsigned int cout_pierre, const unsigned int cout_verre,
    //         const unsigned int cout_papyrus, const unsigned int nb_bois,
    //         const unsigned int nb_argile, const unsigned int nb_pierre,
    //         const unsigned int nb_verre, const unsigned int nb_papyrus,
    //         const int points, const Ressource affecte, const bool estTirage_trois_jetons,
    //         const bool estConstruite);
    Merveille* merveillePyramides = new Merveille("Les Pyramides", 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 9, nullptr, false, false);
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
