#include "Image.hh"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

void Image :: load(SDL_Renderer * renderer, const char * filepath){
    image = IMG_Load(filepath);
    if (image == NULL) {
        std::cout << "Impossible de charger l'image 'pelouse.jpg'\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
    }

    imageTexture = SDL_CreateTextureFromSurface(renderer, image);
    if (!imageTexture) {
        std::cout << "Failed to create texture from surface\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
    }   

        //load image from image_path
        //display image on the screen using renderer
}

void Image :: draw(SDL_Renderer * renderer){
    SDL_RenderCopy(renderer, imageTexture, NULL, NULL);
}