#include "Graphic.hh"

class Button: public Graphic {
    private:
        SDL_Surface* ButtonSurface;
        SDL_Texture* ButtonTexture;
        SDL_Rect buttonRect;
    public:
        Button(int x, int y, int w, int h);
        void load(SDL_Renderer * renderer, const char * filepath);
        void draw(SDL_Renderer * renderer);
        virtual ~Button(){}
        bool pressed(int x, int y);
        SDL_Rect getButtonRect();

};