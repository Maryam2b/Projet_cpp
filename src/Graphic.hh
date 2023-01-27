#ifndef GRAPHIC_H
#define GRAPHIC_H
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class Graphic{
    public :
        virtual void load(SDL_Renderer * renderer, const char * filepath) = 0;

    private : 
        //coordonnées de l'élément graphique
        // int x;
        // int y;

};

#endif /* GRAPHIC_H */
