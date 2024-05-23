//
//  main.cpp
//  TESTSevenWonders
//
//  Created by Chloé on 23/05/2024.
//

#include "carte.hpp"

int main(int argc, const char * argv[]) {
    
    Matiere_Premiere exploitation("exploitation", 1, 0, 0, 0, 0, 0, 1, bois, 1);
    bool ressources[NB_RESSOURCES] = {false,false,true,false,false};
    Commerce depotpierre("Depot de Pierre", 3, 0, 0, 0, 0, 0, 1, 0, 0, true, false, ressources);
    
    exploitation.afficher();
    cout << endl << endl;
    depotpierre.afficher();
    cout << endl;
    return 0;
}
