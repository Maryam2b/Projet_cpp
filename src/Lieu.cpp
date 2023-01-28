
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "Lieu.hh"

Lieu:: Lieu(){
    adresse.numero = 0;
    adresse.rue = " ";
    adresse.code_p = 0 ;
    prix= 0.0 ;
    capacite = 0;
    nb_ecran= 0;
}

Lieu :: Lieu(std::string nom, std::size_t numero ,std::string rue, std::size_t code_p, int prix,std::size_t capacite, std::size_t nb_ecran ){
    
    setNom(nom);
    setPrix(prix);
    setCapacite(capacite);
    setNb_ecran(nb_ecran);
    setAdresse(numero,rue,code_p);
}


void Lieu:: affiche_lieu(){

    std::cout<<"Le lieu "; std::cout<< getNom() ; 
    std::cout<<" est situé à :" ;
    std::cout<< getAdresse()<< std::endl;
    std::cout<< "Prix d'entrée :" ; std::cout<< getPrix() ; std::cout<<"€"<< std::endl;
    std::cout<< "De capacité : " ; std::cout<< getCapacite() ; std::cout<<" personnes"<< std::endl;
    std::cout<< "Nombre d'écrans : "; std::cout<< getNb_ecran()<< std::endl;
}




void Lieu::setNom(std::string n){
    nom = n;
}

void Lieu :: setPrix(int p){
    prix= p;
}

void Lieu :: setCapacite(std::size_t c){
    capacite= c;
}

void Lieu :: setNb_ecran(std::size_t nb){
    nb_ecran =nb;
}

void Lieu:: setAdresse(std::size_t num, std::string rue,std::size_t code_p){
    adresse.numero = num;
    adresse.rue = rue ;
    adresse.code_p = code_p;

}


std::string Lieu:: getNom(){
    return nom;
}

int Lieu :: getPrix(){
    return prix;
}
std::size_t Lieu :: getCapacite(){
    return capacite;
}
std::size_t Lieu :: getNb_ecran(){
    return nb_ecran;
}
std::string Lieu:: getAdresse(){
    
    return std::to_string(adresse.numero) + " " + adresse.rue + " " + std::to_string(adresse.code_p) + " Paris";
}

