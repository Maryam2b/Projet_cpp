#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Match.hh"

class Les_Match{

public:
/* Constructor */
// Les_Match();
Les_Match(std::ifstream& file);

/* Fonctions */

/* setter */

/* getter */

std::list<Match> getLesMatch();


/* Attributs */
private:
    std::list<Match> lesmatch;
};


