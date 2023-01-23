#ifndef MOUSE_H
#define MOUSE_H
#include <iostream>
#include <SDL2/SDL.h>
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL.h"

class Mouse{

    public : 
        SDL_Rect mouseRect;
        SDL_Texture * cursorTexture;
        Mouse(SDL_Renderer * renderer);

        SDL_Rect update(); 
        void draw(SDL_Renderer * renderer, SDL_Rect mouseRect);
};

#endif /* MOUSE_H */