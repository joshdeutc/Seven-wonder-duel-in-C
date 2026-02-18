#include "partie.h"
#include "jeu.h"

int main(int argc, char const *argv[])
{
    // ******************* PARTIE TEST JOSHUA ******************* //
    try{
        Partie p;
        p.jouer();
    } catch (const WondersException& e) {
        cerr << e.getInfo() << endl;
    }

    return 0;
}