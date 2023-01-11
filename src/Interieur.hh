#include <string>
#ifndef LIEU_HH
#define LIEU_HH
#include "Lieu.hh"


class Interieur: public Lieu{

public:
/* Constructor */
Interieur();
Interieur(std::string nom,std::size_t numero,std::string rue,std::size_t code_p,float prix,std::size_t capacite, std::size_t nb_ecran, std::size_t s):Lieu(nom,numero,rue,code_p,prix,capacite,nb_ecran){setSuperficie(s);}

/* Fonctions */

void setSuperficie(std::size_t s);
std::size_t getSuperficie();


/* Attributs */
private:
	std::size_t superficie;
    
};

#endif