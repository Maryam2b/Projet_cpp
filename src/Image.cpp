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

void Image :: drawOnWindow(SDL_Renderer * renderer, int w, int h){
    imageRect.w = image->w/4;
    imageRect.h = image->h/4;
    imageRect.x = (w-imageRect.h)/2  - 210;
    imageRect.y = (h-imageRect.w)/2; 
    SDL_RenderCopy(renderer, imageTexture,NULL, &imageRect);
}

void Image :: drawOnButton(SDL_Renderer * renderer, SDL_Rect sizeButton){
    imageRect.w = image->w/4;
    imageRect.h = image->h/4;
    imageRect.x = (sizeButton.x - imageRect.h) + 225;
    imageRect.y = (sizeButton.h - imageRect.h) + 70;
    SDL_RenderCopy(renderer, imageTexture,NULL, &imageRect);
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