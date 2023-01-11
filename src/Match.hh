#include <string>
#include "date.hh"
#include <list>


class Match{

public:
/* Constructor */
Match();
Match(std::string countryA, std::string countryB, int day, int month, int year, int time, bool i);

/* Fonctions */

/* setter */
void setDate_heure(int day, int month, int year, int time);
void setCountryA(std::string country);
void setCountryB(std::string country);
void setWinner(bool i);

/* getter */
std::string getDate_heure();
std::string getCountryA();
std::string getCountryB();
std::string getWinner();


/* Attributs */
private:
    struct Date date_heure;
    std::string countryA;
    std::string countryB;
    bool i;
    std::string winner;
};


