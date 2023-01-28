#include "Window.hh"


Window :: Window(int weight, int height){
//* Initialise la librairie SDL2 *//
    w = weight;
    h = height;
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Failed to initialize the SDL2 library\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
    }

///// Changer la dimension de votre fenêtre //// 
    // std::cout << "Souhaitez vous changer la dimension de votre fenêtre ? 'OUI ou NON'" << std::endl;
    // std::string choix;
    // std::cin >> choix;

    // if(choix == "OUI"){
    //     std::cout << "Saissisez les dimension w et h souhaitez : " << std::endl;
    //     std::cin >> w;
    //     std::cin >> h;
    // }

//* Créer la fenêtre *//
    window = SDL_CreateWindow("My Fanzone",
                            SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED,
                            w, h,
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


int Window :: getW(){
    return w;
}
int Window :: getH(){
    return h;
}