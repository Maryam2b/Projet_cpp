#include <string>

#include "Exterieur.hh"


class Parc: public Exterieur{

public:
/* Constructor */

Parc( std::string nom,std::size_t numero,std::string rue,std::size_t code_p,float prix,std::size_t capacite,std::size_t nb_ecran):Exterieur(nom,numero,rue,code_p,prix,capacite,nb_ecran){}

/* Fonctions */


/* Attributs */

};
