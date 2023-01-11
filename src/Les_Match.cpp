#include "Les_Match.hh"


Les_Match :: Les_Match(std::ifstream& file){
    std::string line;
    std::string countryA;
    std::string countryB;
    int day;
    int month;
    int year;
    int time;
    bool i;
    while(getline(file, line))
    { 
        std::stringstream ss(line);
        ss >> countryA ;
        ss >> countryB ;
        ss >> day ;
        ss >> month ;
        ss >> year ;
        ss >> time ;
        ss >> i ;
        lesmatch.push_back(Match(countryA,countryB, day, month, year, time,i));
    }
    /*
    std::list<Match>::iterator it = lesmatch.begin();
    std::cout << it->getCountryB() << std::endl;
    file.close();*/
}

std::list<Match> Les_Match :: getLesMatch(){
    return lesmatch;
}

