#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <string>
#include <list>
#include <map>
#include "Window.hh"
#include "Image.hh"
#include "Text.hh"
#include "Button.hh"
#include "Music.hh"
#include "Mouse.hh"
#include "Les_Match.hh"


using namespace std;

//La classe Button


int main(int argc, char *argv[]){
    size_t w= 1120;
    size_t h= 640;
    Window wind(w,h);
    SDL_Renderer * renderer = wind.getRenderer();
    SDL_Window * window = wind.getWindow();
    w = wind.getW();
    h = wind.getH();

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

    // Image d'affichage fanzone //
    Image pelouse;
    pelouse.load(renderer,"../data/images/pelouse.jpg");
    ////

    // TEST MUISIQUE //
    Music music_accueil("../data/sounds/shakira.mp3");
    music_accueil.playMusic();

    // Libération de la musique

    /////

    // Écriture d'accueil //
    SDL_Color color={255,255,255,255};
    Text textAccueil("My fanzone", color, 120);
    textAccueil.load(renderer,"../data/fonts/CELEBRATE_RETRO.ttf");
    SDL_Surface * TextSurface = textAccueil.getTextSurface();
    SDL_Texture * TextTexture = textAccueil.getTextTexture();
    SDL_Rect textRect;
    int textWidth, textHeight;
    SDL_QueryTexture(TextTexture, NULL, NULL, &textWidth, &textHeight);
    textRect.x = (w - textWidth) / 2;
    textRect.y = (h - textHeight) / 2;
    textRect.w = TextSurface->w;
    textRect.h = TextSurface->h;
    ////

    // Écriture match de huitièmes //
    Text TextHuitieme("Quel match de huitiemes souhaitez vous voir ?", color,300);
    TextHuitieme.load(renderer,"../data/fonts/Imperfecta_Regular.ttf");
    SDL_Rect TextHuit;
    TextHuit.x = (w - textWidth) / 2;
    TextHuit.y = (h - textHeight) / 13;
    TextHuit.w = TextSurface->w;
    TextHuit.h = TextSurface->h/4;
    ////

    // Bouttons de huitièmes //
    int y = 110;
    std::vector<Button> lesbouttonsHuit;
    std::vector<SDL_Rect> Rect_bouttons;

    for(int i = 0;i<4;i++){
        Button boutton((w-textWidth)/2, y, 600, 120);
        boutton.load(renderer, "../data/images/button.png");
        lesbouttonsHuit.push_back(boutton);
        Rect_bouttons.push_back(boutton.getButtonRect());
        y+=h/5 ;
    }

    Button nextd(w-100,h-100, 70, 70);
    nextd.load(renderer, "../data/images/nextd.png");
    Button nextg(30,h-100, 70, 70);
    nextg.load(renderer, "../data/images/nextg.png");
    ////

    // Flags stocker dans une map //
    std::map<std::string, Image> imageMap;
    std::string flags[] = {"Allemagne", "Angleterre", "Argentine","Australie","Bresil","Equateur","Espagne","France","Ghana","Italie","Mexique","Pays-Bas","Portugal","Suede","Suisse","Ukraine"};
    for(int i = 0; i<16; i++){
        // std::cout << flags[i] << std::endl;
        std::string s = "../data/flags/" + flags[i] + ".jpg";
        Image flag;
        flag.load(renderer,s.c_str());
        imageMap.insert(std::make_pair(flags[i], flag));
    }
    ////

    // Récupère les matchs // 
    std::ifstream file("../data/txt/huitiemes.txt");
    Les_Match huitiemes(file);
    std::vector<Match> lesmatch = huitiemes.getLesMatch();
    std::string s ;
    ////

    // Affichage des matchs sur boutons // 
    std::vector<Text> lesmatch_Affiche ;
    for(std::vector<Match>::iterator it = lesmatch.begin(); it != lesmatch.end(); it ++){
        s = it->Affichage();
        // std::cout << s << std::endl;
        Text unMatch(s,color,300);
        unMatch.load(renderer,"../data/fonts/Playa-Light.ttf");
        lesmatch_Affiche.push_back(unMatch);
    }
    // for(int it = 0; it < lesmatch_Affiche.size(); it ++){
    //     std::cout << lesmatch_Affiche[it].getS() << std::endl;
    // }
    /////
    file.close();

    // Affichage text fanzone //    
    Text TextFanzone("Voici les fanzones disponibles pour ce match : ", color,300);
    TextFanzone.load(renderer,"../data/fonts/Playa-Light.ttf");
    SDL_Rect Textf;
    Textf.x = (w - textWidth) / 2;
    Textf.y = (h - textHeight) / 13;
    Textf.w = TextSurface->w;
    Textf.h = TextSurface->h/4;
    /////

    // Image d'affichage fanzone //
    Image exterieur;
    exterieur.load(renderer,"../data/images/exterieur.jpg");
    ////
    
    SDL_UpdateWindowSurface(window);
    bool keep_window_open = true;
    bool next_window = false;
    int i = 0;
    bool pageOneMatch = false;
    bool pageTwoMatch = false;
    bool choixfanzones = false;
    // bool window_restaurant = false;
    // bool window_bar = false;
    // bool window_salle = false;
    bool window_exterieur = false;
    int iter;


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
                    if (e.key.keysym.sym == SDLK_SPACE ){
                        if(i==0){
                            next_window = true;
                            pageOneMatch = true;
                            i++;
                        }
                        else if(i==1){
                            window_exterieur = true;
                            choixfanzones = false;
                        }
                    }

                    if (e.key.keysym.sym == SDLK_ESCAPE)
                        keep_window_open = false;
                    break;
                case SDL_MOUSEBUTTONDOWN: // Lorsqu'on clique avec la souris //
                    int x,y;
                    if (SDL_GetMouseState(&x, &y) & SDL_BUTTON(SDL_BUTTON_LEFT)&& next_window){
                        for(int it = 0; it < lesbouttonsHuit.size(); it ++){
                            if(lesbouttonsHuit[it].pressed(x,y)&& pageOneMatch == true){
                                std::cout << "bouton cliqué" << std::endl;
                                next_window = false;
                                choixfanzones = true;
                                iter = it;
                            }
                            else if(lesbouttonsHuit[it].pressed(x,y)&& pageTwoMatch == true){
                                std::cout << "bouton cliqué" << std::endl;
                                next_window = false;
                                choixfanzones = true; 
                                iter = it+3;
                          
                            }
                            else if(nextd.pressed(x,y)){
                                pageOneMatch = false;
                                pageTwoMatch = true;
                            }
                            else if(nextg.pressed(x,y)){
                                pageOneMatch = true;
                                pageTwoMatch = false;
                            }
                        }
                    }
                    // if (/*SDL_GetMouseState(&x, &y) & SDL_BUTTON(SDL_BUTTON_LEFT) &&*/ choixfanzones==true){
                    //     switch(e.type){   
                    //         case SDL_KEYDOWN:
                    //             if(e.key.keysym.sym == SDLK_SPACE){
                    //                 window_exterieur = true;
                    //                 choixfanzones = false;
                    //             }
                    //         break;
                    //     }
                    // }
                    break;
                }
            }

        SDL_RenderClear(renderer);
        if(next_window){
            if(pageOneMatch == true){
                image_next_window.draw(renderer);
                TextHuitieme.draw(renderer,TextHuit);
                for(int it = 0; it < lesbouttonsHuit.size(); it ++){
                    lesbouttonsHuit[it].draw(renderer);
                }
                for(int i = 0; i <lesmatch_Affiche.size(); i++){
                    if(i<4){
                        // std::cout << lesmatch[0].getCountryA() << std::endl;
                        // std::string g = lesmatch[0].getCountryA();
                        imageMap[lesmatch[i].getCountryA()].drawRectg(renderer,Rect_bouttons[i]);
                        imageMap[lesmatch[i].getCountryB()].drawRectd(renderer,Rect_bouttons[i]);
                        lesmatch_Affiche[i].drawOnButton(renderer,Rect_bouttons[i]);
                    }
                }
                // imageMap["Paysbas"].drawRectd(renderer,Rect_bouttons[0]);
                // imageMap["france"].drawRectg(renderer,lesbouttonsHuit[0].getButtonRect());
                // imageMap["france"].drawRectd(renderer,Rect_bouttons[0]);
                nextd.draw(renderer);
            }


            else if(pageTwoMatch == true){
                image_next_window.draw(renderer);
                TextHuitieme.draw(renderer,TextHuit);
                for(int it = 0; it < lesbouttonsHuit.size(); it ++){
                    lesbouttonsHuit[it].draw(renderer);          
                }
                int j = 0;
                for(int i = 0; i < lesmatch_Affiche.size(); i++){
                    if(i>=4){
                        imageMap[lesmatch[i].getCountryA()].drawRectg(renderer,Rect_bouttons[j]);
                        imageMap[lesmatch[i].getCountryB()].drawRectd(renderer,Rect_bouttons[j]);
                        lesmatch_Affiche[i].drawOnButton(renderer,Rect_bouttons[j]);
                        j++;
                    }
                }
            nextg.draw(renderer);
            }
        }   

        else if(choixfanzones){
            pelouse.draw(renderer);
            TextFanzone.draw(renderer,Textf);
            Text TextGagnant("Voici les fanzones disponibles pour ce match : ", color,300);
            TextFanzone.load(renderer,"../data/fonts/Playa-Light.ttf");
            std::cout << "Le gagnant est "<< lesmatch[iter].getWinner()<< std::endl;
        }       
        else if(window_exterieur){
            exterieur.draw(renderer);
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