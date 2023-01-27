#include <fstream>
#include <sstream>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <list>
#include "Window.hh"
#include "Image.hh"
#include "Text.hh"
#include "Button.hh"
#include "Mouse.hh"
#include "Les_Match.hh"


using namespace std;

//La classe Button


int main(int argc, char *argv[]){
    Window wind;
    SDL_Renderer * renderer = wind.getRenderer();
    SDL_Window * window = wind.getWindow();

    // Souris customisée // 
    Mouse mouse(renderer);
    SDL_Rect mouseRect;
    SDL_ShowCursor(false);
    ////

    // Image d'accueil //
    Image imageAccueil;
    imageAccueil.load(renderer,"../data/images/supporters.jpg");
    ////

    // Image next_window //
    Image image_next_window;
    image_next_window.load(renderer,"../data/images/supporters_flou.png");
    ////

    // Écriture d'accueil //
    SDL_Color color={255,255,255,255};
    Text textAccueil("My fanzone", color, 120);
    textAccueil.load(renderer,"../data/fonts/CELEBRATE_RETRO.ttf");
    SDL_Surface * TextSurface = textAccueil.getTextSurface();
    SDL_Rect textRect;
    textRect.x = (160 + TextSurface->w)/2;
    textRect.y = (600 + TextSurface->h)/2;
    textRect.w = TextSurface->w;
    textRect.h = TextSurface->h;
    ////

    // Écriture match de huitièmes //
    Text TextHuitieme("Quel match de huitiemes souhaitez vous voir ?", color,300);
    TextHuitieme.load(renderer,"../data/fonts/Imperfecta_Regular.ttf");
    SDL_Rect TextHuit;
    TextHuit.x = 390;
    TextHuit.y = 10;
    TextHuit.w = TextSurface->w;
    TextHuit.h = TextSurface->h/2;
    ////

    // Bouttons de huitièmes //
    int y = 110;
    std::list<Button> lesbouttonsHuit;
    std::vector<SDL_Rect> Rect_bouttons;

    for(int i = 0;i<4;i++){
        Button boutton(350, y, 700, 120);
        boutton.load(renderer, "../data/images/button.png");
        lesbouttonsHuit.push_back(boutton);
        Rect_bouttons.push_back(boutton.getButtonRect());
        y+=180;
    }

    Button nextd(1250,700, 70, 70);
    nextd.load(renderer, "../data/images/nextd.png");
    Button nextg(30,700, 70, 70);
    nextg.load(renderer, "../data/images/nextg.png");
   ////


    // Récupère les matchs // 
    std::ifstream file("../data/txt/huitiemes.txt");
    Les_Match huitiemes(file);
    std::list<Match> lesmatch = huitiemes.getLesMatch();
    std::string s ;
    ////

    // Affichage des matchs sur boutons // 
    std::vector<Text> lesmatch_Affiche ;
    for(std::list<Match>::iterator it = lesmatch.begin(); it != lesmatch.end(); it ++){
        s = it->Affichage();
        // std::cout << s << std::endl;
        Text unMatch(s,color,300);
        unMatch.load(renderer,"../data/fonts/Imperfecta_Regular.ttf");
        lesmatch_Affiche.push_back(unMatch);
    }
    // for(int it = 0; it < lesmatch_Affiche.size(); it ++){
    //     std::cout << lesmatch_Affiche[it].getS() << std::endl;
    // }
    /////
    file.close();


    SDL_UpdateWindowSurface(window);
    bool keep_window_open = true;
    bool pageOneMatch = false;
    bool pageTwoMatch = false;

    while(keep_window_open)
    {   
        mouseRect = mouse.update();
        SDL_Event e;
        while(SDL_PollEvent(&e) > 0)
        {
        mouseRect = mouse.update();
            switch(e.type)
            {
                case SDL_QUIT:
                    keep_window_open = false;
                    break;
                case SDL_KEYDOWN: // Lorsqu'on clique sur une touche du clavier //
                    if (e.key.keysym.sym == SDLK_SPACE)
                        pageOneMatch = true;
                    if (e.key.keysym.sym == SDLK_ESCAPE)
                        keep_window_open = false;
                    break;
                case SDL_MOUSEBUTTONDOWN: // Lorsqu'on clique avec la souris //
                    int x,y;
                    if (SDL_GetMouseState(&x, &y) & SDL_BUTTON(SDL_BUTTON_LEFT)){
                        for(std::list<Button>::iterator it = lesbouttonsHuit.begin(); it != lesbouttonsHuit.end(); it ++){
                            if(it->pressed(x,y)){
                                std::cout << "bouton cliqué" << std::endl;
                            }
                            if(nextd.pressed(x,y)){
                                pageOneMatch = false;
                                pageTwoMatch = true;
                            }
                            if(nextg.pressed(x,y)){
                                pageOneMatch = true;
                                pageTwoMatch = false;
                            }
                        }

                    }
                    break;
                }
            }

        SDL_RenderClear(renderer);
        if(pageOneMatch == true){
            image_next_window.draw(renderer);
            TextHuitieme.draw(renderer,TextHuit);
            for(std::list<Button>::iterator it = lesbouttonsHuit.begin(); it != lesbouttonsHuit.end(); it ++){
                it->draw(renderer);
            }
            for(int i = 0; i <lesmatch_Affiche.size(); i++){
                if(i<4){
                    lesmatch_Affiche[i].drawOnButton(renderer,Rect_bouttons[i]);
                }
            }
            nextd.draw(renderer);
        }


        else if(pageTwoMatch == true){
            image_next_window.draw(renderer);
            TextHuitieme.draw(renderer,TextHuit);
            for(std::list<Button>::iterator it = lesbouttonsHuit.begin(); it != lesbouttonsHuit.end(); it ++){
                it->draw(renderer);          
            }
            int j = 0;
            for(int i = 0; i < lesmatch_Affiche.size(); i++){
                if(i>=4){
                    lesmatch_Affiche[i].drawOnButton(renderer,Rect_bouttons[j]);
                    j++;
                }
            }
            nextg.draw(renderer);
        }
        else{
            imageAccueil.draw(renderer);
            textAccueil.draw(renderer,textRect);
        }
        mouse.draw(renderer,mouseRect);
        SDL_RenderPresent(renderer);

    }

    
////---------------DES TESTS---------------////
    // std::ifstream file("../data/quarts.txt");
    // Les_Match deuxmilsix(file);
    // std::list<Match> lesmatch = deuxmilsix.getLesMatch();
    // std::list<Match>::iterator it = lesmatch.begin();
    // std::cout << it->getCountryB() << std::endl;
    // file.close();

    

    // Lieu leslieux( "Lafac", 10, "rue de mozart", 75012, 0, 20,2);
    // leslieux.affiche_lieu();

    // Bar bar( "Lafac", 10, "rue de mozart", 75012, 0, 20,2,2,true); // le deuxieme 2 est la superficie
    
    // bar.affiche_lieu();
    // Restaurant resto( "Lafac", 10, "rue de mozart", 75012, 0, 20,2,2);
    // resto.affiche_lieu();

    // Salle salle( "Lafac", 10, "rue de mozart", 75012, 0, 20,2,2);
    // salle.affiche_lieu();
    


    return 0;
}