#include <string>

// #ifndef INTERIEUR_HH
// #define INTERIEUR_HH
#include "Interieur.hh"

class Restaurant: public Interieur{

public:
/* Constructor */
Restaurant();

Restaurant( std::string nom,std::size_t numero,std::string rue,std::size_t code_p,float prix,std::size_t capacite, std::size_t nb_ecran ,std::size_t superficie):Interieur(nom,numero,rue,code_p,prix,capacite,nb_ecran,superficie){}

/* Fonctions */




/* Attributs */
private:
	
    
};

//#endif