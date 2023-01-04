#include <iostream>
#include <fstream>
#include <sstream>

#include "Les_Match.hh"

int main(){
    // std::list<Match> les_match;
    // std::ifstream file("huitiemes.txt");
    // std::string line;
    // std::string countryA;
    // std::string countryB;
    // int day;
    // int month;
    // int year;
    // int time;
    // bool i;
    // while(getline(file, line))
    // { 
    //     std::stringstream ss(line);
    //     ss >> countryA ;
    //     ss >> countryB ;
    //     ss >> day ;
    //     ss >> month ;
    //     ss >> year ;
    //     ss >> time ;
    //     ss >> i ;
    //     les_match.push_back(Match(countryA,countryB, day, month, year, time,i));
    // }

    // std::list<Match>::iterator it = les_match.begin();
    // std::cout << it->getCountryB() << std::endl;
    // file.close();

    std::ifstream file("../data/quarts.txt");
    Les_Match deuimilsix(file);
    std::list<Match> lesmatch = deuimilsix.getLesMatch();
    std::list<Match>::iterator it = lesmatch.begin();
    std::cout << it->getCountryB() << std::endl;
    file.close();

    return 0;
}