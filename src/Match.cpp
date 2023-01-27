#include "Match.hh"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>



Match :: Match(){
    date_heure.day = 0;
    date_heure.month = 0;
    date_heure.year = 0;
    date_heure.time = 0;
    countryA = "";
    countryB = "";
    i = false;
    winner = "";
}

Match :: Match(std::string countryA, std::string countryB, int day, int month, int year, int time, bool i){ // rajouter le bool
    setDate_heure(day, month, year, time);
    setCountryA(countryA);
    setCountryB(countryB);
    setWinner(i);
}

std::string Match :: Affichage(){
    return countryA + " - " + countryB;
}

void Match :: setDate_heure(int day, int month, int year, int time){
    date_heure.day = day; 
    date_heure.month = month;
    date_heure.year = year;
    date_heure.time = time;
}

void Match :: setCountryA(std::string country){
    countryA = country;
}

void Match :: setCountryB(std::string country){
    countryB = country;
}

void Match :: setWinner(bool i){
    if(i){
        winner = countryB;
    }
    else{
        winner = countryA;
    }
}


std::string Match :: getDate_heure(){
    return std::to_string(date_heure.day) + "/" + std::to_string(date_heure.month) + "/" + std::to_string(date_heure.year) + " à " + std::to_string(date_heure.time) + " heures";
}

std::string Match :: getCountryA(){
    return countryA;
}

std::string Match :: getCountryB(){
    return countryB;
}

std::string Match :: getWinner(){
   return winner;
}
