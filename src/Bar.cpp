
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Bar.hh"



Bar:: Bar(){

   repas = false ;
}


void Bar:: setRepas(bool r){
    repas = r;
}


bool Bar:: getRepas(){
	return repas; 
}