#include "partie.h"

bool Partie::aquisition_carte(Joueur& j1,const Joueur& j2,
                                 const Carte& c){
    int solde_future=j1.get_solde()-c.prix_final_j1(j1,j2);
    if(solde_future>0){
        j1.set_solde(solde_future);
        j1.add_carte(c);
        return true;
    }
    else{
        cout << "Solde insuffisant";
        return false;
    }
}