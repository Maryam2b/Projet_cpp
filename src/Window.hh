#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class Window{
    public :
        Window();
        ~Window();
        SDL_Window * getWindow();
        SDL_Renderer * getRenderer();
    private : 
        SDL_Window * window;
        SDL_Renderer * renderer;

};
