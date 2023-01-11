
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Interieur.hh"



Interieur :: Interieur(){
   superficie = 0;
}



void Interieur:: setSuperficie(std::size_t s){
    superficie = s;
}

std::size_t Interieur :: getSuperficie(){
    return superficie;
}
