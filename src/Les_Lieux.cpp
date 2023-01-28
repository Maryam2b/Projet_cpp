#include "Les_Lieux.hh"


Les_Lieux :: Les_Lieux(std::ifstream& file){
    std::string line;
    std::string nom;
    std::size_t numero;
    std::string rue;
    std::size_t code_p;
    int prix;
    std::size_t capacite;
    std::size_t nb_ecran ;
    
   
    while(getline(file, line))
    { 
        std::stringstream ss(line);
        ss >> nom;
        ss >> numero ;
        ss >> rue ;
        ss >> code_p ;
        ss >> prix ;
        ss >> capacite ;
        ss >> nb_ecran ;
        leslieux.push_back(Lieu(nom,numero,rue,code_p,prix,capacite,nb_ecran));
    }
   
}

std::vector<Lieu> Les_Lieux :: getLesLieux(){
    return leslieux;
}

