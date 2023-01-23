#include <iostream>
#include <SDL2/SDL.h>
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL.h"
#include "Mouse.hh"


class Application{
    public : 
        Application();
        void setButtonRect(int x, int y, int w, int h);
        SDL_Rect getButtonRect();
        void initialisation();
        void Renderer(Mouse mouse);
        // SDL_Texture* createTextureButton(std::ifstream& file);
        void destroyRenderer();
        void run();

    /* attribut */
    private : 
        SDL_Window * window;
        SDL_Renderer * renderer;
        SDL_Surface * image;
        SDL_Texture* imageTexture;
        SDL_Rect imgRect;
        SDL_Surface * pelouse;
        SDL_Texture* pelouseTexture;
        TTF_Font* police;
        SDL_Surface* TextSurface;
        SDL_Texture* textTexture;
        SDL_Rect textRect;
        SDL_Rect mouseRect;
        bool next_window ;
        bool second_window ;
        bool keep_window_open ;
        SDL_Rect buttonRect;
};

