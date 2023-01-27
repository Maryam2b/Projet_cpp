#include "Window.hh"


Window :: Window(){
//* Initialise la librairie SDL2 *//
        if(SDL_Init(SDL_INIT_VIDEO) < 0)
        {
            std::cout << "Failed to initialize the SDL2 library\n";
            std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        }

//* Créer la fenêtre *//
        window = SDL_CreateWindow("My Fanzone",
                                SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED,
                                1120, 640,
                                0);

        if(!window)
        {
            std::cout << "Failed to create window\n";
            std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        }        

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer == NULL) {
            std::cout << "Failed to create renderer\n";
            std::cout << "SDL Error: " << SDL_GetError() << "\n";
        }
}

Window :: ~Window(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}


SDL_Window * Window :: getWindow(){
    return window;
}

SDL_Renderer * Window :: getRenderer(){
    return renderer;
}
