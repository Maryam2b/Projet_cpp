#include "Graphic.hh"

class Image : public Graphic {
    private:
        SDL_Surface * image;
        SDL_Texture* imageTexture;
        SDL_Rect imageRect;
    public:
        void load(SDL_Renderer * renderer, const char * filepath);
        void draw(SDL_Renderer * renderer);
        void drawOnWindow(SDL_Renderer * renderer, int w, int h);
        void drawOnButton(SDL_Renderer * renderer, SDL_Rect sizeButton);
        void drawRectd(SDL_Renderer * renderer,SDL_Rect buttonRect);
        void drawRectg(SDL_Renderer * renderer,SDL_Rect buttonRect);
};