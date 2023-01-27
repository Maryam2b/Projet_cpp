#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>

#ifndef LIEU_HH
#define LIEU_HH
#include "Lieu.hh"

class Les_Lieux{

public:
/* Constructor */

Les_Lieux(std::ifstream& file);

/* Fonctions */

/* setter */

/* getter */

std::list<Lieu> getLesLieux();


/* Attributs */
private:
    std::list<Lieu> leslieux;
};
#endif

