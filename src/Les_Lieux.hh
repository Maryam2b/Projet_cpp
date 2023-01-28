#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

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

std::vector<Lieu> getLesLieux();


/* Attributs */
private:
    std::vector<Lieu> leslieux;
};
#endif

