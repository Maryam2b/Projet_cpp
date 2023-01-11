#include <iostream>
#include <fstream>
#include <sstream>


#include "Restaurant.hh"
#include "Bar.hh"
#include "Les_Match.hh"
#include "Salle.hh"

int main(){
    

    std::ifstream file("../data/quarts.txt");
    Les_Match deuxmilsix(file);
    std::list<Match> lesmatch = deuxmilsix.getLesMatch();
    std::list<Match>::iterator it = lesmatch.begin();
    std::cout << it->getCountryB() << std::endl;
    file.close();

    

    Lieu leslieux( "Lafac", 10, "rue de mozart", 75012, 0, 20,2);
    leslieux.affiche_lieu();

    Bar bar( "Lafac", 10, "rue de mozart", 75012, 0, 20,2,2,true); // le deuxieme 2 est la superficie
    
    bar.affiche_lieu();
    Restaurant resto( "Lafac", 10, "rue de mozart", 75012, 0, 20,2,2);
    resto.affiche_lieu();

    Salle salle( "Lafac", 10, "rue de mozart", 75012, 0, 20,2,2);
    salle.affiche_lieu();
    


    return 0;
}