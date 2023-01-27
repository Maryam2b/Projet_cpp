#ifndef MOUSE_H
#define MOUSE_H
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class Mouse{

    public : 
        SDL_Rect mouseRect;
        SDL_Texture * cursorTexture;
        Mouse(SDL_Renderer * renderer);

        SDL_Rect update(); 
        void draw(SDL_Renderer * renderer, SDL_Rect mouseRect);
};

#endif /* MOUSE_H */