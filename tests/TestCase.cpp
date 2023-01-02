// Let Catch provide main():
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include <iostream>
#include <fstream>
#include "Match.hh"

using namespace std;


TEST_CASE("1: Match"){
    Match m;
    m.setCountryA("France");
    m.setCountryB("Maroc");
    m.setDate_heure(11,11,2011,8);
    REQUIRE(m.getCountryA() == "France");
    REQUIRE(m.getCountryB() == "Maroc");
    REQUIRE(m.getDate_heure() == "11/11/2011 à 8 heures");
}

// TEST_CASE("2: Molecules Normalize","[molecules]"){
//   Molecule m("H-O-H");
//   std::cout << m.normalize() << std::endl;
//   REQUIRE(m.normalize() == "H2O");

// }

// TEST_CASE("3: le fichier","[molecules]" )
// {
//   ifstream file("molecules.txt");
//   list<Molecule> les_molecules;
//   string s;
//   while( file >> s)
//     {
//       les_molecules.push_back(Molecule(s));
//     }
//   ifstream res("res_normalize.txt");
//   for(const auto& iter : les_molecules)
//     {
//       res >> s;
//       cout << iter.normalize() << std::endl;
//       REQUIRE(s==iter.normalize());
//     }
//   res.close();
//   file.close();

// }
// TEST_CASE("4: Reactions","Reaction"){
//   ifstream file("reactions.txt");
//   list<Reaction> lesReactions;
//   string s;
//   ifstream res("res_reaction.txt");
//   while(getline(file,s))
//     {
//       if(!s.empty())
//         lesReactions.push_back(Reaction(s));
//     }
//   for(const  auto& iter : lesReactions)
//     {
//       getline(res,s);
//       cout << iter.normalize() << endl;
//       REQUIRE(s==iter.normalize());
//     }
//   res.close();
//   file.close();
// }


