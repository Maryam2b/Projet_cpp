#include "Button.hh"


Button::Button(int x, int y, int w, int h)
{
    buttonRect.x = x;
    buttonRect.y = y;
    buttonRect.w = w;
    buttonRect.h = h;
}

void Button :: load(SDL_Renderer * renderer, const char * filepath){
    ButtonSurface = IMG_Load(filepath);
    ButtonTexture = SDL_CreateTextureFromSurface(renderer, ButtonSurface);
}


void Button :: draw(SDL_Renderer * renderer){
    SDL_RenderCopy(renderer, ButtonTexture, NULL, &buttonRect);
}


bool Button :: pressed(int x, int y) {
    if (x >= buttonRect.x-5 && x <= buttonRect.x-5  + buttonRect.w-5  && y >= buttonRect.y-5 && y <= buttonRect.y-5  + buttonRect.h-5 ) {
        return true;
    }
    return false;
}

SDL_Rect Button :: getButtonRect(){
    return buttonRect;
}

// void Button::update(){
//     int x, int y;
//     if (SDL_GetMouseState(&x, &y) & SDL_BUTTON(SDL_BUTTON_LEFT)){
//         if(x>= buttonRect.x && x <= buttonRect.x + buttonRect.w && y >= buttonRect.y && y <= buttonRect.y + buttonRect.h){
//             second_window = true;
//             next_window = false;
//         }
// }
