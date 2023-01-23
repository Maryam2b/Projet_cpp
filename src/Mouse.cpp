#include "Mouse.hh"



Mouse ::  Mouse(SDL_Renderer * renderer ){
    cursorTexture = IMG_LoadTexture(renderer,"../data/mouse.png");
      if( cursorTexture == NULL ) 
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", "mouse.png", IMG_GetError() );
    }
    mouseRect.x = 0;
    mouseRect.y = 0;
    mouseRect.w = 90;
    mouseRect.h = 90;
}


SDL_Rect Mouse :: update(){
    int x, y;
    SDL_GetMouseState(&x,&y);
    mouseRect.x = x;
    mouseRect.y = y; 

    return mouseRect;
}

void Mouse :: draw(SDL_Renderer * renderer, SDL_Rect mouseRect){
    SDL_RenderCopy(renderer, cursorTexture, NULL, &mouseRect);
}