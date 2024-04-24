#ifndef PARTIE_H
#define PARTIE_H

#include "carte.h"

class Partie
{
private:
            signed int solde_militaire;
            int age; // {1,2,3}
            int merveille_construite;
            int tour; // {1,2} : Au tour de joueur 1 ou 2
            int nb_tour;
        public:
            Partie(/* args */);
            ~Partie();
            void mise_en_jeu_batiments();
            void mise_en_jeu_jeton_progres();
            void mise_en_jeu_merveilles(); // Added return type 'void'
            void tour_suivant(); // Added semicolon at the end
            void fin_age();
            void accessibilite(Batiment);
            void victoire_scientifique(Joueur);
            void change_solde_militaire(Joueur,nb_boucliers);
            void victoire_militaire();
            void victoire_civile();
};

Partie::Partie(/* args */)
{
}

Partie::~Partie()
{
}


#endif