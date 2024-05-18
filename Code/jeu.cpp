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
    // ⚠️⚠️⚠️ Les variables non entières, exceptés les noms devront être modifiés pour correspondre au jeu 
    Merveille* merveilleCircusMaximus = new Merveille("Circus Maximus", 0, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 5, papyrus, false, false);
    Merveille* merveilleColosse = new Merveille("Le Colosse", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 7, pierre, false, false);
    Merveille* merveilleGrandPhare = new Merveille("Le Grand Phare", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 7, verre, false, false);
    Merveille* merveilleJardinsSuspendus = new Merveille("Les Jardins Suspendus", 0, 0, 2, 0, 0, 1, 0, 0, 0, 0, 0, 6, verre, false, false);
    Merveille* merveilleGrandeBibliotheque = new Merveille("La Grande Bibliotheque", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 7, papyrus, false, false);
    Merveille* merveilleMausolee = new Merveille("Le Mausolee", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 7, pierre, false, false);
    Merveille* merveillePiree = new Merveille("Le Pirée", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 7, bois, false, false);
    Merveille* merveillePyramides = new Merveille("Les Pyramides", 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 9, papyrus, false, false);
    Merveille* merveilleSphinx = new Merveille("Le Sphinx", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 7, pierre, false, false);
    Merveille* merveilleStatueDeZeus = new Merveille("La Statue de Zeus", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 7, bois, false, false);
    Merveille* merveilleTempleDArtemis = new Merveille("Le Temple d’Artémis", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 7, papyrus, false, false);
    Merveille* merveilleViaAppia = new Merveille("La Via Appia", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 7, verre, false, false);
    tabCartesMerveille[0] = merveilleCircusMaximus;
    tabCartesMerveille[1] = merveilleColosse;
    tabCartesMerveille[2] = merveilleGrandPhare;
    tabCartesMerveille[3] = merveilleJardinsSuspendus;
    tabCartesMerveille[4] = merveilleGrandeBibliotheque;
    tabCartesMerveille[5] = merveilleMausolee;
    tabCartesMerveille[6] = merveillePiree;
    tabCartesMerveille[7] = merveillePyramides;
    tabCartesMerveille[8] = merveilleSphinx;
    tabCartesMerveille[9] = merveilleStatueDeZeus;
    tabCartesMerveille[10] = merveilleTempleDArtemis;
    tabCartesMerveille[11] = merveilleViaAppia;

    // Cartes Age 1
        // Sans chainage
    Matiere_Premiere* matierePremiereChantier = new Matiere_Premiere("Chantier", 0, 0, 0, 0, 0, 0, 1, false, false, statut, "", 1, 0, 0, 0, 0, "Batiment", 1);
    Matiere_Premiere* matierePremiereExploitation = new Matiere_Premiere("Exploitation", 0, 1, 0, 0, 0, 0, 1, false, false, statut, "", 1, 0, 0, 0, 0, "Batiment", 1);
    Matiere_Premiere* matierePremiereBassinArgileux = new Matiere_Premiere("Bassin Argileux", 0, 0, 0, 0, 0, 0, 1, false, false, statut, "", 0, 1, 0, 0, 0, "Batiment", 1);
    Matiere_Premiere* matierePremiereCavite = new Matiere_Premiere("Cavité", 1, 0, 0, 0, 0, 0, 1, false, false, statut, "", 0, 1, 0, 0, 0, "Batiment", 1);
    Matiere_Premiere* matierePremiereGisement = new Matiere_Premiere("Gisement", 0, 0, 0, 0, 0, 0, 1, false, false, statut, "", 0, 0, 1, 0, 0, "Batiment", 1);
    Matiere_Premiere* matierePremiereMine = new Matiere_Premiere("Mine", 1, 0, 0, 0, 0, 0, 1, false, false, statut, "", 0, 0, 1, 0, 0, "Batiment", 1);
    Produit_Manufacture* produitManufactureVerrerie = new Produit_Manufacture("Verrerie", 0, 0, 0, 0, 0, 0, 1, false, false, statut, "", 0, 0, 0, 1, 0, "Batiment", 1);
    Produit_Manufacture* produitManufacturePresse = new Produit_Manufacture("Presse", 1, 0, 0, 0, 0, 0, 1, false, false, statut, "", 0, 0, 0, 0, 1, "Batiment", 1);
    Militaire* militaireTourDeGarde = new Militaire("Tour de garde", 0, 0, 0, 0, 0, 0, 1, false, false, statut, "", 1, "Batiment", 1);
    Scientifique* scientifiqueAtelier = new Scientifique("Atelier", 0 ,0 ,0 ,0, 0, 1, 1, false, false, statut, "", 1, A,"Batiment", 1));
    Scientifique* scientifiqueAtelier = new Scientifique("Apothicaire", 0 ,0 ,0 ,0, 1, 0, 1, false, false, statut, "", 1, roue,"Batiment", 1));
    Commerce* commerceDepotDePierre = new Commerce("Dépôt de pierre", 3, 0, 0, 0, 0, 0, 1, false, false, statut, "", 0, 1, pierre, 0, 0, 0, 0, 0, "Batiment", 1);
    Commerce* commerceDepotDArgile = new Commerce("Dépôt d'argile", 3, 0, 0, 0, 0, 0, 1, false, false, statut, "", 0, 1, argile, 0, 0, 0, 0, 0, "Batiment", 1);
    Commerce* commerceDepotDeBois = new Commerce("Dépôt de bois", 3, 0, 0, 0, 0, 0, 1, false, false, statut, "", 0, 1, bois, 0, 0, 0, 0, 0, "Batiment", 1);

        // Avec chainage
    Militaire* militaireEcuries = new Militaire("Ecuries", 0, 1, 0, 0, 0, 0, 1, false, false, statut, "Haras", 1, "Militaire", 1); )
    Militaire* militaireCaserne = new Militaire("Caserne", 0, 0, 1, 0, 0, 0, 1, false, false, statut, "Baraquements", 1, "Militaire", 1);
    Militaire* militairePalissade = new Militaire("Palissade", 2, 0, 0, 0, 0, 0, 1, false, false, statut, "Fortifications", 1, "Militaire", 1);
    Civil* civilTheatre = new Civil("Théâtre", 0, 0, 0, 0, 0, 0, 1, false, false, statut, "Statue", 3, "Civil", 1);
    Civil* civilAutel = new Civil("Autel", 0, 0, 0, 0, 0, 0, 1, false, false, statut, "Temple", 3, "Civil", 1);
    Civil* civilBains = new Civil("Bains", 0, 0, 0, 1, 0, 0, 1, false, false, statut, "Aqueduc", 3, "Civil", 1);
    Commerce* commerceTaverne = new Commerce("Taverne", 0, 0, 0, 0, 0, 0, 1, false, false, statut, "Phare", 99, 4, 0, 0, 0, 0, 0, 0, "Commerce", 1); // Bizarre

    // Age 2
        // Sans chainage
    Matiere_Premiere* matierePremiereScierie = new Matiere_Premiere("Scierie", 2, 0, 0, 0, 0, 0, 2, false, false, statut, "", 2, 0, 0, 0, 0, "Matiere Premiere", 2);
    Matiere_Premiere* matierePremiereBriqueterie = new Matiere_Premiere("Briqueterie", 2, 0, 0, 0, 0, 0, 2, false, false, statut, "", 0, 2, 0, 0, 0, "Matiere Premiere", 2);
    Matiere_Premiere* matierePremiereCarriere = new Matiere_Premiere("Carriere", 2, 0, 0, 0, 0, 0, 2, false, false, statut, "", 0, 0, 2, 0, 0, "Matiere Premiere", 2);
    Produit_Manufacture* matierePremiereSoufflerie = new Produit_Manufacture("Soufflerie", 0, 0, 0, 0, 0, 0, 2, false, false, statut, "", 0, 0, 0, 1, 0, "Produit Manufacture", 2);
    Produit_Manufacture* matierePremiereSechoir = new Produit_Manufacture("Sechoir", 0, 0, 0, 0, 0, 0, 2, false, false, statut, "", 0, 0, 0, 0, 1, "Produit Manufacture", 2);
    Militaire* militaireMuraille = new Militaire("Muraille", 0, 0, 0, 2, 0, 0, 2, false, false, statut, "", 2, "Militaire", 2);
    Commerce* commerceForum = new Commerce("Forum", 3, 0, 1, 0, 0, 0, 2, false, false, statut, "", 0, 0, 
    Commerce* commerceCaravanserail = new Commerce("Caravanserail", 2, 0, 0, 0, 1, 1, 2, false, false, statut, "", 0, 0, 0, 0, 0, "Commerce", 2);
    Commerce* commerceDouanes = new Commerce("Douanes", 4, 0, 0, 0, 0, 0, 2, false, false, statut, "", ...);
    Civil* civilTribunal = new Civil("Tribunal", 0, 2, 0, 0, 1, 0, 2, false, false, statut, "", 5, "Civil", 2);

        // Avec chainage
    Militaire* militaireHaras = new Militaire("Haras", 0, 1, 1, 0, 0, 0, 2, false, false, statut, "Ecuries", 1, "Militaire", 2);
    Militaire* militaireBaraquements = new Militaire("Baraquements", 0, 1, 1, 0, 0, 0, 2, false, false, statut, "Caserne", 1, "Militaire", 2);
    Militaire* militaireChampsDeTir = new Militaire("Champs de Tir", 0, 1, 0, 1, 0, 1, 2, false, false, statut, "Atelier de siege", 2, "Militaire", 2);
    Militaire* militairePlaceDArmes = new Militaire("Place d'Armes", 0, 0, 2, 0, 1, 0, 2, false, false, statut, "Cirque", 2, "Militaire", 2);
    Civil* civilBibliotheque = new Civil("Bibliotheque", 0, 1, 0, 1, 1, 0, 2, false, false, statut, "Scriptorium", 2, "Civil", 2);
    
    // Age 3
        // Sans chainage
    Militaire* militaireArsenal = new Militaire("Arsenal", 0, 2, 3, 0, 0, 0, 3, false, false, statut, "", 3, "Militaire", 3);
    Militaire* militairePretoire = new Militaire("Pretoire", 8, 0, 0, 0, 0, 0, 3, false, false, statut, "", 3, "Militaire", 3);
    Scientifique* scientifiqueAcademie = new Scientifique("Academie", 0, 1, 0, 1, 2, 0, 3, false, false, statut, "", 3, horloge, "Scientifique", 3);
    Scientifique* scientifiqueEtude = new Scientifique("Etude", 0, 2, 0, 0, 1, 1, 3, false, false, statut, "", 3, horloge, "Scientifique", 3);
    
    Civil* civilPalace = new Civil("Palace", 0, 1, 1, 1, 2, 0, 3, false, false, statut, "", 7, "Civil", 3);
    Civil* civilHotelDeVille = new Civil("Hotel de Ville", 0, 2, 0, 3, 0, 0, 3, false, false, statut, "", 7, "Civil", 3);
    Civil* civilObelisque = new Civil("Obelisque", 0, 0, 0, 2, 1, 0, 3, false, false, statut, "", 5, "Civil", 3);
        // Avec chainage
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