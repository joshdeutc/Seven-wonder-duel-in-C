#include "plateau.h"
#include "jeu.h"

PlateauAge::PlateauAge(int Age)
{
    switch (Age){
        case 1:{
            // Initialiser la graine de la fonction rand()
            srand(time(nullptr));
            
            // Tableau pour stocker les indices des cartes sélectionnées
            int indicesSelectionnes[20];
            
            // Sélection aléatoire de 20 indices distincts
            int nombreCartes = 23;
            for (int i = 0; i < 20; ++i) {
                int indice;
                bool dejaSelectionne;
                do {
                    indice = rand() % nombreCartes; // Générer un index aléatoire
                    dejaSelectionne = false;
                    // Vérifier si l'index a déjà été sélectionné
                    for (int j = 0; j < i; ++j) {
                        if (indicesSelectionnes[j] == indice) {
                            dejaSelectionne = true;
                            break;
                        }
                    }
                } while (dejaSelectionne); // Répéter tant que l'index est déjà sélectionné
                indicesSelectionnes[i] = indice;
            }
            
            // Allocation dynamique du tableau de cartes sélectionnées
            cartes = new Batiment*[20];
            
            // Copie des cartes sélectionnées dans le tableau du plateau
            for (int i = 0; i < 20; ++i) {
                cartes[i] = Jeu::getInstance()->tabCartesAge1[indicesSelectionnes[i]];
            }
            break;}
        case 2:{
            // Initialiser la graine de la fonction rand()
            srand(time(nullptr));
            
            // Tableau pour stocker les indices des cartes sélectionnées
            int indicesSelectionnes[20];
            
            // Sélection aléatoire de 20 indices distincts
            int nombreCartes = 23;
            for (int i = 0; i < 20; ++i) {
                int indice;
                bool dejaSelectionne;
                do {
                    indice = rand() % nombreCartes; // Générer un index aléatoire
                    dejaSelectionne = false;
                    // Vérifier si l'index a déjà été sélectionné
                    for (int j = 0; j < i; ++j) {
                        if (indicesSelectionnes[j] == indice) {
                            dejaSelectionne = true;
                            break;
                        }
                    }
                } while (dejaSelectionne); // Répéter tant que l'index est déjà sélectionné
                indicesSelectionnes[i] = indice;
            }
            
            // Allocation dynamique du tableau de cartes sélectionnées
            cartes = new Batiment*[20];
            
            // Copie des cartes sélectionnées dans le tableau du plateau
            for (int i = 0; i < 20; ++i) {
                cartes[i] = Jeu::getInstance()->tabCartesAge2[indicesSelectionnes[i]];
            }
            break;}
        case 3:{
            // Initialiser la graine de la fonction rand()
            srand(time(nullptr));
            
            // Tableau pour stocker les indices des cartes Age sélectionnées
            int indicesSelectionnesAge3[17];
            
            // Sélection aléatoire de 17 indices distincts
            int nombreCartes = 20;
            for (int i=0; i<17; ++i) {
                int indice;
                bool dejaSelectionne;
                do {
                    indice = rand() % nombreCartes; // Générer un index aléatoire
                    dejaSelectionne = false;
                    // Vérifier si l'index a déjà été sélectionné
                    for (int j= 0; j<i; ++j) {
                        if (indicesSelectionnesAge3[j] == indice) {
                            dejaSelectionne = true;
                            break;
                        }
                    }
                } while (dejaSelectionne); // Répéter tant que l'index est déjà sélectionné
                indicesSelectionnesAge3[i] = indice;
            }
            
            // Tableau pour stocker les indices des cartes Guilde sélectionnées
            int indicesSelectionnesGuilde[3];
            
            //Sélection aléatoire de 3 indices distincts
            nombreCartes = 7;
            for(int i = 0;i<3;i++){
                int indice;
                bool dejaSelectionne;
                do {
                    indice = rand() % nombreCartes; // Générer un index aléatoire
                    dejaSelectionne = false;
                    // Vérifier si l'index a déjà été sélectionné
                    for (int j= 0; j<i; ++j) {
                        if (indicesSelectionnesGuilde[j] == indice) {
                            dejaSelectionne = true;
                            break;
                        }
                    }
                } while (dejaSelectionne); // Répéter tant que l'index est déjà sélectionné
                indicesSelectionnesGuilde[i] = indice;
            }
            
            
            // Allocation dynamique du tableau de cartes sélectionnées
            cartes = new Batiment*[20];
            
            // Distribution aléatoire des cartes de l'Âge 3 et des cartes Guilde dans le tableau cartes
            int indiceAge3 = 0;
            int indiceGuilde = 0;
            for (int i = 0; i < 20; ++i) {
                // Sélectionner aléatoirement entre une carte de l'Âge 3 et une carte Guilde
                double probaCarteAge3 = (17.0 - indiceAge3) / (20.0 - i); // Probabilité de choisir une carte de l'Âge 3
                double probaCarteGuilde = (3.0 - indiceGuilde) / (20.0 - i); // Probabilité de choisir une carte Guilde
                bool estCarteAge3 = (rand() / (RAND_MAX + 1.0)) < probaCarteAge3; // Comparaison avec une probabilité uniforme entre 0 et 1
                
                if (estCarteAge3 && indiceAge3 < 17) {
                    // Si c'est une carte de l'Âge 3 et il reste des cartes de l'Âge 3 non sélectionnées
                    cartes[i] = Jeu::getInstance()->tabCartesAge3[indicesSelectionnesAge3[indiceAge3]];
                    ++indiceAge3;
                } else if (indiceGuilde < 3) {
                    // Si c'est une carte Guilde et il reste des cartes Guilde non sélectionnées
                    cartes[i] = Jeu::getInstance()->tabCartesGuilde[indicesSelectionnesGuilde[indiceGuilde]]; 
                    ++indiceGuilde;
                } else {
                    // Si on a épuisé les cartes Guilde disponibles, distribuer les cartes de l'Âge 3 restantes
                    cartes[i] = Jeu::getInstance()->tabCartesAge3[indicesSelectionnesAge3[indiceAge3]];
                    ++indiceAge3;
                }
            }
            break;
            
        }
            
    }
}

PlateauAge::~PlateauAge()
{
    //On ne supprime pas les cartes elles mêmes, elles seront supprimees quand l'instance Jeu sera supprimée.
    delete[] cartes;
}


PlateauMerveille::PlateauMerveille()
{
    Merveille** cartesPremierPhase = new Merveille*[4];
    Merveille** cartesDeuxiemePhase = new Merveille*[4];
    for (unsigned int i = 0; i < 4; i++)
    {
        //cartesPremierPhase[i] =
    }
    
}

PlateauMerveille::~PlateauMerveille()
{
}