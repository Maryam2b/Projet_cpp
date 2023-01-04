#include "Lieu.hh"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>



Lieu:: Lieu(){
    superficie = 0;
    prix= 0.0 ;
    capacite = 0;
    nb_ecran= 0;
}

Lieu :: Lieu(std::size_t superficie, float prix,std::size_t capacite, std::size_t nb_ecran ){
    setSuperficie(superficie);
    setPrix(prix);
    setCapacite(capacite);
    setNb_ecran(nb_ecran);
}










void Lieu:: setSuperficie(std::size_t s){
    superficie = s;
}

void Lieu :: setPrix(float p){
    prix= p;
}

void Lieu :: setCapacite(std::size_t c){
    capacite= c;
}

void Lieu :: setNb_ecran(std::size_t nb){
    nb_ecran =nb;
}


std::size_t Lieu :: getSuperficie(){
    return superficie;
}

float Lieu :: getPrix(){
    return prix;
}
std::size_t Lieu :: getCapacite(){
    return capacite;
}
std::size_t Lieu :: getNb_ecran(){
    return nb_ecran;
}