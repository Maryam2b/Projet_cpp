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


void Image :: drawRectd(SDL_Renderer * renderer,SDL_Rect buttonRect){
    imageRect.w = image->w/3;
    imageRect.h = image->h/3;
    imageRect.x = buttonRect.x + buttonRect.w - image->w + 130;
    imageRect.y = buttonRect.y + 30 ;
    SDL_RenderCopy(renderer, imageTexture, NULL, &imageRect);
}

void Image :: drawRectg(SDL_Renderer * renderer,SDL_Rect buttonRect){
    imageRect.w = image->w/3;
    imageRect.h = image->h/3;
    imageRect.x = buttonRect.x - image->w  + 280;
    imageRect.y = buttonRect.y + 30 ;
    SDL_RenderCopy(renderer, imageTexture, NULL, &imageRect);
}