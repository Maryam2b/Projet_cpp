// Let Catch provide main():
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include <iostream>
#include <fstream>

#include <list>
#include "MatchDeHuitiemes.hh"

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


// TEST_CASE("2: Constructeur Match(...)"){ OKK
//     MatchDeHuitiemes b("France","Maroc",11,11,2011,8);
//     b.setWinner(0);
//     REQUIRE(b.getCountryA() == "France");
//     REQUIRE(b.getCountryB() == "Maroc");
//     REQUIRE(b.getDate_heure() == "11/11/2011 à 8 heures");
//     REQUIRE(b.getWinner() == "France");
// }

TEST_CASE("3: le fichier","[huitiemes]")
{
}

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


