#include <string>
#include "date.hh"

class Match{

public:
/* Constructor */
Match();

/* Fonctions */

/* setter */
void setDate_heure(int day, int month, int year, int time);
void setCountryA(std::string country);
void setCountryB(std::string country);
/* getter */
std::string getDate_heure();
std::string getCountryA();
std::string getCountryB();


/* Attributs */
private:
    struct Date date_heure;
    std::string countryA;
    std::string countryB;
};


