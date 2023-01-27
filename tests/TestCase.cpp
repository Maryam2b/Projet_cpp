// Let Catch provide main():
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include <iostream>
#include <fstream>
#include <fstream>
#include <sstream>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <list>
#include "Window.hh"
#include "Image.hh"
#include "Text.hh"
#include "Button.hh"
#include "Mouse.hh"
#include "Les_Match.hh"


using namespace std;


// TEST_CASE("1: Constructeur Match()"){ OKK
//     Match a;
//     a.setCountryA("France");
//     a.setCountryB("Maroc");
//     a.setDate_heure(11,11,2011,8);
//     a.setWinner(0);
//     REQUIRE(a.getCountryA() == "France");
//     REQUIRE(a.getCountryB() == "Maroc");
//     REQUIRE(a.getDate_heure() == "11/11/2011 à 8 heures");
//     REQUIRE(a.getWinner() == "France");
// }


TEST_CASE("2: Constructeur Match(...)"){ 
    Match b("France","Maroc",11,11,2011,8,0);
    REQUIRE(b.getCountryA() == "France");
    REQUIRE(b.getCountryB() == "Maroc");
    REQUIRE(b.getDate_heure() == "11/11/2011 à 8 heures");
    REQUIRE(b.getWinner() == "France");
}

TEST_CASE("3: le fichier","[huitiemes]")
{
}

TEST_CASE("4: Les Match","Les_Match"){
    std::ifstream file("../data/quarts.txt");
    Les_Match deuimilsix(file);
    std::list<Match> lesmatch = deuimilsix.getLesMatch();
    std::list<Match>::iterator it = lesmatch.begin();
    std::cout << it->getCountryB() << std::endl;
    file.close();
}

// TEST_CASE("4: Classe Text","Text"){
    
// }


