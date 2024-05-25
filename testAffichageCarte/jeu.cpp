#include "jeu.h"
#include "carte_bat_merv.h"

// Initialiser le pointeur à nullptr
Jeu* Jeu::instance = nullptr;

Jeu::Jeu()
{
    
    const int nbCartesAge1 = 23;
    const int nbCartesAge2 = 23;
    const int nbCartesAge3 = 20;
    const int nbCartesGuilde = 7; // Ajustez selon vos besoins
    const int nbCartesMerveille = 12; // Ajustez selon vos besoins
    const int nbJetonsProgres = 10;
    
    tabCartesAge1 = new Batiment*[nbCartesAge1];
    tabCartesAge2 = new Batiment*[nbCartesAge2];
    tabCartesAge3 = new Batiment*[nbCartesAge3];
    tabCartesGuilde = new Guilde*[nbCartesGuilde];
    tabCartesMerveille = new Merveille*[nbCartesMerveille];
    tabJetonProgres = new JetonProgres*[nbJetonsProgres];

    // Il faudra initialiser toutes les cartes ici
    
    unsigned int prix_aucun[NB_RESSOURCES];
    unsigned int prix[NB_RESSOURCES];
    
    for(int i=0;i<NB_RESSOURCES;i++){
        prix_aucun[i] = 0;
        prix[i] = 0;
    }
    
    
    // MATIERES PREMIERES
    
    tabCartesAge1[0] = new Matiere_Premiere("CHANTIER", 0, prix_aucun, 1, bois, 1);
    tabCartesAge1[1] = new Matiere_Premiere("EXPLOITATION", 1, prix_aucun, 1, bois, 1);
    tabCartesAge1[2] = new Matiere_Premiere("BASSIN ARGILEUX",0,prix_aucun,1,argile,1);
    tabCartesAge1[3] = new Matiere_Premiere("CAVITÉ",1,prix_aucun,1,argile,1);
    tabCartesAge1[4] = new Matiere_Premiere("GISEMENT",0,prix_aucun,1,pierre,1);
    tabCartesAge1[5] = new Matiere_Premiere("MINE",1,prix_aucun,1,pierre,1);
    
    tabCartesAge2[0] = new Matiere_Premiere("SCIERIE",2,prix_aucun,2,bois,2);
    tabCartesAge2[1] = new Matiere_Premiere("BRIQUETERIE",2,prix_aucun,2,argile,2);
    tabCartesAge2[2] = new Matiere_Premiere("CARRIÈRE",2,prix_aucun,2,pierre,2);

    // PRODUIT MANUFACTURE
    
    tabCartesAge1[6] = new Produit_Manufacture("VERRERIE", 1, prix_aucun, 1, verre, 1);
    tabCartesAge1[7] = new Produit_Manufacture("PRESSE", 1, prix_aucun, 1, papyrus, 1);
    
    tabCartesAge2[3] = new Produit_Manufacture("SOUFFLERIE", 0, prix_aucun, 2, verre, 1);
    tabCartesAge2[4] = new Produit_Manufacture("SÉCHOIR", 0, prix_aucun, 2, papyrus, 1);
    
    // MILITAIRE
    
    tabCartesAge1[8] = new Militaire("TOUR DE GARDE", 0, prix_aucun, 1, 1);
    prix[bois]=1;
    tabCartesAge1[9] = new Militaire("ÉCURIES", 0, prix, 1, 1,fer);
    prix[bois]=0; prix[argile] = 1;
    tabCartesAge1[10] = new Militaire("CASERNE", 0, prix, 1, 1,epee);
    prix[argile] = 0;
    tabCartesAge1[11] = new Militaire("PALISSADE", 2, prix_aucun, 1, 1,tour);
    
    prix[pierre]=2;
    tabCartesAge2[5] = new Militaire("MURAILLE", 0, prix, 2, 2);
    prix[pierre]=0; prix[argile] = 1; prix[bois] = 1;
    tabCartesAge2[6] = new Militaire("HARAS", 0, prix, 2, 1,fer);
    tabCartesAge2[7] = new Militaire("BARAQUEMENTS", 3, prix_aucun, 2, 1,epee);
    prix[pierre]=1; prix[argile] = 0; prix[papyrus] = 1;
    tabCartesAge2[8] = new Militaire("CHAMP DE TIR", 0, prix, 2, 2,cible);
    prix[pierre]=0; prix[argile] = 2; prix[bois] = 0; prix[verre]=1; prix[papyrus] = 0;
    tabCartesAge2[9] = new Militaire("PLACE D'ARMES", 0, prix, 2, 2,casque);
    
    prix[argile]=3; prix[bois]=2;
    tabCartesAge3[0] = new Militaire("ARSENAL", 0, prix, 3, 3);
    tabCartesAge3[1] = new Militaire("PRÉTOIRE", 8, prix_aucun, 3, 3);
    prix[pierre]=2; prix[argile]=1; prix[papyrus] = 1; prix[verre] = 0;
    tabCartesAge3[2] = new Militaire("FORTIFICATIONS", 0, prix, 3, 2,tour);
    prix[pierre]=0; prix[argile]=0; prix[papyrus] = 0; prix[verre] = 1; prix[bois]=3;
    tabCartesAge3[3] = new Militaire("ATELIER DE SIÈGE", 0, prix, 3, 2,cible);
    prix[pierre]=2; prix[argile]=2; prix[verre] = 0; prix[argile] = 2;
    tabCartesAge3[4] = new Militaire("CIRQUE", 0, prix, 3, 2,casque);




    // SCIENTIFIQUE
    
    prix[argile] = 0; prix[verre] = 0; prix[papyrus] = 1;
    tabCartesAge1[12] = new Scientifique("ATELIER", 0, prix, 1, A,1);
    prix[verre] = 1; prix[papyrus] = 0;
    tabCartesAge1[13] = new Scientifique("APOTHICAIRE", 0, prix, 1, roue,1);
    tabCartesAge1[14] = new Scientifique("SCRIPTORIUM", 2, prix_aucun, 1, plume,0,livre);
    tabCartesAge1[15] = new Scientifique("OFFICINE", 2, prix_aucun, 1, bol,0,engrenage);
    
    prix[bois] = 1; prix[pierre] = 1;
    tabCartesAge2[10] = new Scientifique("BIBLIOTHÈQUE", 0, prix, 2, plume,2,livre);
    prix[bois]=0; prix[verre]=0; prix[argile]=2;
    tabCartesAge2[11] = new Scientifique("DISPENSAIRE", 0, prix, 2, bol,2,engrenage);
    prix[argile]=0;prix[pierre]=0;prix[bois]=1;prix[papyrus]=3;
    tabCartesAge2[12] = new Scientifique("ÉCOLE", 0, prix, 2, roue,1,harpe);
    prix[papyrus]=0; prix[verre]=2;
    tabCartesAge2[13] = new Scientifique("LABORATOIRE", 0, prix, 2, A,1,lampe);
    
    prix[pierre]=1;
    tabCartesAge3[5] = new Scientifique("ACADÉMIE", 0, prix, 3, horloge,3);
    prix[bois]=2; prix[verre]=1; prix[papyrus] = 1; prix[pierre] = 0;
    tabCartesAge3[6] = new Scientifique("ÉTUDE", 0, prix, 3, horloge,3);
    prix[bois] = 0; prix[argile] = 1;
    tabCartesAge3[7] = new Scientifique("UNIVERSITÉ", 0, prix, 3, globe,2,harpe);
    prix[argile] = 0; prix[verre] = 0; prix[papyrus] = 2; prix[pierre] = 1;
    tabCartesAge3[8] = new Scientifique("OBSERVATOIRE", 0, prix, 3, globe,2,lampe);
    
    // COMMERCE
    
    bool affecte[NB_RESSOURCES];
    
    for(int i=0;i<NB_RESSOURCES;i++){
        affecte[i] = false;
    }
    
    affecte[pierre]=true;
    tabCartesAge1[16] = new Commerce("DÉPÔT DE PIERRE", 3, prix_aucun, 1, 0,0,true,false,affecte,0,aucuneCarte);
    affecte[pierre]=false; affecte[argile] = true;
    tabCartesAge1[17] = new Commerce("DÉPÔT D'ARGILE'", 3, prix_aucun, 1, 0,0,true,false,affecte,0,aucuneCarte);
    affecte[argile]=false; affecte[bois]=true;
    tabCartesAge1[18] = new Commerce("DÉPÔT DE BOIS", 3, prix_aucun, 1, 0,0,true,false,affecte,0,aucuneCarte);
    affecte[bois]=false;
    tabCartesAge1[19] = new Commerce("TAVERNE", 0, prix_aucun, 1, 0,4,false,false,affecte,0,aucuneCarte,vase);
    
    prix[argile] = 1; prix[papyrus] = 0; prix[verre] = 0;
    affecte[verre] = true; affecte[papyrus] = true;
    prix[pierre] = 0;
    tabCartesAge2[14] = new Commerce("FORUM", 3, prix, 2, 0,0,false,true,affecte,0,aucuneCarte);
    prix[verre]=1; prix[papyrus]=1; prix[argile]=0;
    affecte[verre] = false; affecte[papyrus] = false;
    affecte[bois] = true; affecte[argile] = true; affecte[pierre] = true;
    tabCartesAge2[15] = new Commerce("CARAVANSERAIL", 2, prix, 2, 0,0,false,true,affecte,0,aucuneCarte);
    affecte[verre] = true; affecte[papyrus] = true;
    affecte[bois] = false; affecte[argile] = false; affecte[pierre] = false;
    tabCartesAge2[16] = new Commerce("DOUANES", 4, prix_aucun, 2, 0,0,true,false,affecte,0,aucuneCarte);
    affecte[verre] = false; affecte[papyrus] = false;
    tabCartesAge2[17] = new Commerce("BRASSERIE", 0, prix_aucun, 2, 0,6,false,false,affecte,0,aucuneCarte,tonneau);
    
    prix[verre] = 0; prix[papyrus] = 2;
    tabCartesAge3[9] = new Commerce("CHAMBRE DE COMMERCE", 0, prix, 3, 3,0,false,false,affecte,3,produitManufacture);
    prix[verre] = 1; prix[papyrus] = 1; prix[bois] = 1;
    tabCartesAge3[10] = new Commerce("PORT", 0, prix, 3, 3,0,false,false,affecte,2,matierePremiere);
    prix[papyrus] = 0; prix[bois] = 0; prix[pierre] = 2;
    tabCartesAge3[11] = new Commerce("ARMURERIE", 0, prix, 3, 3,0,false,false,affecte,1,batimentMilitaire);
    prix[pierre] = 0; prix[argile] = 2;
    tabCartesAge3[12] = new Commerce("PHARE", 0, prix, 3, 3,0,false,false,affecte,1,batimentCommerce,vase);
    prix[pierre] = 1; prix[argile] = 1; prix[verre] = 0; prix[bois] = 1;
    tabCartesAge3[13] = new Commerce("ARÈNE", 0, prix, 3, 3,0,false,false,affecte,2,merveille,tonneau);

    
    //CIVIL
 
    tabCartesAge1[20] = new Civil("THÉÂTRE", 0, prix_aucun, 1, 3,masque);
    tabCartesAge1[21] = new Civil("AUTEL", 0, prix_aucun, 1, 3,lune);
    prix[bois] = 0; prix[argile] = 0;
    tabCartesAge1[22] = new Civil("BAINS", 0, prix, 1, 3,goutte);
    
    prix[bois] = 2; prix[verre] = 1; prix[pierre] = 0;
    tabCartesAge2[18] = new Civil("TRIBUNAL", 0, prix, 2, 5);
    prix[bois] = 0; prix[verre] = 0; prix[argile] = 2;
    tabCartesAge2[19] = new Civil("STATUE", 0, prix, 2, 4, masque, poutre);
    prix[argile] = 0; prix[papyrus] = 1; prix[bois] = 1;
    tabCartesAge2[20] = new Civil("TEMPLE", 0, prix, 2, 4, lune, soleil);
    prix[bois] = 0; prix[papyrus] = 0; prix[pierre] = 3;
    tabCartesAge2[21] = new Civil("AQUEDUC", 0, prix, 2, 5, goutte);
    prix[pierre] = 1; prix[bois] = 1;
    tabCartesAge2[22] = new Civil("ROSTRES",0,prix,2,4,temple);
    
    prix[argile] = 1; prix[verre] = 2;
    tabCartesAge3[14] = new Civil("PALACE", 0, prix, 3, 7);
    prix[argile] = 0; prix[verre] = 0; prix[pierre] = 3; prix[bois] = 2;
    tabCartesAge3[15] = new Civil("HOTEL DE VILLE", 0, prix, 3, 7);
    prix[bois] = 0; prix[pierre] = 2; prix[verre] = 1;
    tabCartesAge3[16] = new Civil("OBÉLISQUE", 0, prix, 3, 5);
    prix[argile] = 2; prix[bois] = 2; prix[verre] = 0; prix[pierre] = 0;
    tabCartesAge3[17] = new Civil("JARDINS", 0, prix, 3, 6,poutre);
    prix[argile] = 1; prix[bois] = 1; prix[papyrus] = 2;
    tabCartesAge3[18] = new Civil("PANTHÉON", 0, prix, 3, 6,soleil);
    prix[argile] = 2; prix[bois] = 0; prix[papyrus] = 1; prix[pierre] = 1;
    tabCartesAge3[19] = new Civil("SÉNAT", 0, prix, 3, 5,temple);
    
    
    //GUILDE
    
    prix[pierre] = 0; prix[argile] = 1; prix[bois] = 1; prix[verre] = 1;
    tabCartesGuilde[0] = new Guilde("GUILDE DES COMMERÇANTS", 0, prix, 0, 1,1,batimentCommerce);
    prix[bois] = 0; prix[pierre] = 1;
    tabCartesGuilde[1] = new Guilde("GUILDE DES ARMATEURS",0,prix,0,1,1,matierePremiere,produitManufacture);
    prix[bois] = 1; prix[pierre] = 2; prix[papyrus] = 0;
    tabCartesGuilde[2] = new Guilde("GUILDE DES BÂTISSEURS",0,prix,0,2,0,merveille);
    prix[bois] = 2; prix[pierre] = 0; prix[papyrus] = 1; prix[verre] = 0;
    tabCartesGuilde[3] = new Guilde("GUILDE DES MAGISTRATS",0,prix,0,1,1,batimentCivil);
    prix[argile] = 2; prix[papyrus] = 0;
    tabCartesGuilde[4] = new Guilde("GUILDE DES SCIENTIFIQUES",0,prix,0,1,1,batimentScientifique);
    prix[argile] = 0; prix[pierre] = 2;
    tabCartesGuilde[5] = new Guilde("GUILDE DES USURIERS",0,prix,0,1,0,aucuneCarte);
    prix[bois] = 0; prix[argile] = 1; prix[papyrus] = 1;
    tabCartesGuilde[6] = new Guilde("GUILDE DES TACTICIENS",0,prix,0,1,1,batimentMilitaire);
    

}



Jeu::~Jeu()
{
    delete[] tabCartesAge1;
    delete[] tabCartesAge2;
    delete[] tabCartesAge3;
    delete[] tabCartesGuilde;
    delete[] tabCartesMerveille;
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