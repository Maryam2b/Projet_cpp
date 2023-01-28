#include <string>

// #ifndef INTERIEUR_HH
// #define INTERIEUR_HH
#include "Interieur.hh"


class Bar: public Interieur{

public:
/* Constructor */
Bar();
Bar( std::string nom,std::size_t numero,std::string rue,std::size_t code_p,int prix,std::size_t capacite, std::size_t nb_ecran ,std::size_t superficie,bool repas):Interieur(nom,numero,rue,code_p,prix,capacite,nb_ecran,superficie),repas(repas){}

/* Fonctions */


void setRepas(bool r);

bool getRepas();


/* Attributs */
private:

	bool repas ; 
    
};


//#endif