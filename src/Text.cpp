#include "Text.hh"


Text :: Text(std::string text,SDL_Color colors,int taille){
    s = text;
    color = colors;
    size = taille;
}

void Text :: load(SDL_Renderer * renderer, const char * filepath){
    if(TTF_Init()==-1) {
        printf("TTF_Init: %s\n", TTF_GetError());
        exit(2);
    }
    police = TTF_OpenFont(filepath,size);
    if(police != NULL) {
        // std::cout << "ok à l'ouverture de CELEBRATE_RETRO.ttf" << std::endl;
    }
    else{
        // std::cout << "foirage à l'ouverture de CELEBRATE_RETRO.ttf" << std::endl;
    }

    TextSurface = TTF_RenderText_Solid(police,s.c_str(), color);
    if (!TextSurface) {
        std::cout << "Failed to create surface from text\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
    }
    TextTexture = SDL_CreateTextureFromSurface(renderer, TextSurface);
    if (!TextTexture) {
        std::cout << "Failed to create texture from surface\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
    }
}

SDL_Surface * Text :: getTextSurface(){
    return TextSurface;
}

SDL_Texture * Text :: getTextTexture(){
    return TextTexture;
}

void Text :: draw(SDL_Renderer * renderer, SDL_Rect textRect){
    SDL_RenderCopy(renderer, TextTexture, NULL, &textRect);
}


void Text :: drawOnButton(SDL_Renderer * renderer, SDL_Rect sizeButton){
    textRect.w = TextSurface->w;
    textRect.h = TextSurface->h;
    textRect.x = sizeButton.x + (sizeButton.w - textRect.w)/ 2;
    textRect.y = sizeButton.y + (sizeButton.h - textRect.h) / 2;
    SDL_RenderCopy(renderer, TextTexture,NULL, &textRect);
}

void Text :: drawFanzoneButton(SDL_Renderer * renderer, int x, int y){
    textRect.w = TextSurface->w;
    textRect.h = TextSurface->h;
    textRect.x = x+40;
    textRect.y = y+40;    
    SDL_RenderCopy(renderer, TextTexture,NULL, &textRect);
}


std::string Text :: getS(){
    return s;
}
