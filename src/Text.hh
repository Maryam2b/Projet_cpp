#include "Graphic.hh"

class Text: public Graphic {
    private:
        TTF_Font* police;
        std::string s;
        SDL_Color color;
        SDL_Surface* TextSurface;
        SDL_Texture* TextTexture;
        int size;
        SDL_Rect textRect;
    public: 
        Text(){}
        Text(std::string text,SDL_Color colors,int taille);
        void load(SDL_Renderer * renderer, const char * filepath);
        SDL_Surface * getTextSurface();
        SDL_Texture * getTextTexture();
        void draw(SDL_Renderer * renderer, SDL_Rect textRect);
        void drawOnButton(SDL_Renderer * renderer, SDL_Rect sizeButton);
        void drawFanzoneButton(SDL_Renderer * renderer, int x, int y);

        std::string getS();
        virtual ~Text(){}

};