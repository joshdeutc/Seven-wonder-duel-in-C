
#include "carte_bat_merv.h"
#include "jeu.h"
#include "plateau.h"

int main() {
    // lancement du jeu
    Jeu *j = Jeu::getInstance();
    PlateauAge platage = PlateauAge(3);
    platage.accessibilite();
    int choix;
    do {
        std::cout << "Fais ton choix: ";
        std::cin >> choix;
        if (choix != 22) {
            platage.destruction_carte_plateau_age3(choix);
        }
        cout << "on a détruit la carte " << choix << endl;
        platage.accessibilite();
    } while (choix != 22);
}