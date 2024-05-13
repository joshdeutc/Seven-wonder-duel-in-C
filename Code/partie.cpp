#include "partie.h"
#include "plateau.h"


bool Partie::aquisition_carte(Joueur& j1,const Joueur& j2,
                                 const Carte& c,const Plateau& pla){
    int solde_future=j1.get_solde()-c.prix_final_j1(j1,j2);
    if(solde_future>0){
        j1.set_solde(solde_future);
        j1.add_carte(c);
        if(c.get_type_carte()==)// a finir plus tard ne pas oublier que
            // les cartes sont stockées dans differents tableaux
            // selon leur type et que certaines ne vont pas dans la défausse
            // (merveille)
        return true;
    }
    else{
        cout << "Solde insuffisant";
        return false;
    }
}