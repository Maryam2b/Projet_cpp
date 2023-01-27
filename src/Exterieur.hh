#include <string>
#ifndef LIEU_HH
#define LIEU_HH
#include "Lieu.hh"


class Exterieur: public Lieu{

public:
/* Constructor */
Exterieur();
Exterieur(std::string nom,std::size_t numero,std::string rue,std::size_t code_p,float prix,std::size_t capacite, std::size_t nb_ecran):Lieu(nom,numero,rue,code_p,prix,capacite,nb_ecran){};

/* Fonctions */

};

#endif