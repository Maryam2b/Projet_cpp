#include <iostream>
#include <fstream>
#include <sstream>

#include <list>
#include "Match.hh"

int main(){
    std::list<Match> les_match;
    std::ifstream file("huitiemes.txt");
    std::string line;
    std::string countryA;
    std::string countryB;
    int day;
    int month;
    int year;
    int time;
    bool win;
    while(getline(file, line))
    { 
        std::stringstream ss(line);
        ss >> countryA ;
        ss >> countryB ;
        ss >> day ;
        ss >> month ;
        ss >> year ;
        ss >> time ;
        ss >> win ;
        les_match.push_back(Match(countryA,countryB, day, month, year, time));
    }

    std::list<Match>::iterator it = les_match.begin();
    std::cout << it->getCountryA() << std::endl;
    file.close();

    return 0;
}