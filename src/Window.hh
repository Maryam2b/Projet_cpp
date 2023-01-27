#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class Window{
    public :
        Window(int weight, int height);
        ~Window();
        SDL_Window * getWindow();
        SDL_Renderer * getRenderer();
        int getW();
        int getH();
    private : 
        SDL_Window * window;
        SDL_Renderer * renderer;
        int w;
        int h;

};
