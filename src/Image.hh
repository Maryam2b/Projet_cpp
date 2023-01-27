#include "Graphic.hh"

class Image : public Graphic {
    private:
        SDL_Surface * image;
        SDL_Texture* imageTexture;
    public:
        void load(SDL_Renderer * renderer, const char * filepath);
        void draw(SDL_Renderer * renderer);

};