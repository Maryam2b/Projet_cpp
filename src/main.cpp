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
#include "Les_Lieux.hh"



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
    Image espace;
    espace.load(renderer,"../data/images/espace.png");
    ////

    // Image next_window //
    Image image_next_window;
    image_next_window.load(renderer,"../data/images/supporters_flou.png");
    ////

    // Image d'affichage fanzone //
    Image pelouse;
    pelouse.load(renderer,"../data/images/pelouse.jpg");
    ////

    // TEST MUSIQUE //
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

    // Écriture match titre //
    Text TextHuitieme("Quel match de huitiemes souhaitez-vous voir ?", color,35);
    TextHuitieme.load(renderer,"../data/fonts/Playa-Light.ttf");
    Text TextQuarts("Quel match de quarts souhaitez-vous voir ?", color,35);
    TextQuarts.load(renderer,"../data/fonts/Playa-Light.ttf");
    Text TextDemi("Quel match de demis souhaitez-vous voir ?", color,35);
    TextDemi.load(renderer,"../data/fonts/Playa-Light.ttf");
    Text TextFinal("Voici le match final", color,25);
    TextFinal.load(renderer,"../data/fonts/Playa-Light.ttf");
    SDL_Rect TextHuit;
    TextHuit.x = (w - textWidth) / 3;
    TextHuit.y = (h - textHeight) / 13;
    TextHuit.w = TextHuitieme.getTextSurface()->w;
    TextHuit.h = TextHuitieme.getTextSurface()->h;
    ////

    // Bouttons de huitièmes et quarts //
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

    // Bouttons de demis //
    y = 200;
    std::vector<Button> lesbouttonsDemi;
    std::vector<SDL_Rect> Rect_bouttons_demi;
    for(int i = 0;i<2;i++){
        Button boutton((w-textWidth)/2, y, 600, 120);
        boutton.load(renderer, "../data/images/button.png");
        lesbouttonsDemi.push_back(boutton);
        Rect_bouttons_demi.push_back(boutton.getButtonRect());
        y+=h/3 ;
    }

    // Bouttons de final //
    y = 300;
    std::vector<Button> lebouttonFinal;
    std::vector<SDL_Rect> Rect_boutton_final;
    for(int i = 0;i<1;i++){
        Button boutton((w-textWidth)/2, y, 600, 120);
        boutton.load(renderer, "../data/images/button.png");
        lebouttonFinal.push_back(boutton);
        Rect_boutton_final.push_back(boutton.getButtonRect());
    }



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

    // Récupère les matchs de quarts// 
    std::ifstream fileQuarts("../data/txt/quarts.txt");
    Les_Match quarts(fileQuarts);
    std::vector<Match> lesmatchQuarts = quarts.getLesMatch();
    ////

    // Récupère les matchs de demi// 
    std::ifstream fileDemi("../data/txt/demi.txt");
    Les_Match demis(fileDemi);
    std::vector<Match> lesmatchDemis = demis.getLesMatch();
    ////

    // Récupère les matchs final// 
    std::ifstream fileFinal("../data/txt/finale.txt");
    Les_Match final(fileFinal);
    std::vector<Match> lematchFinal = final.getLesMatch();
    ////

    // Affichage des matchs sur boutons // 
    std::vector<Text> lesmatch_Affiche ;
    for(std::vector<Match>::iterator it = lesmatch.begin(); it != lesmatch.end(); it ++){
        s = it->Affichage();
        // std::cout << s << std::endl;
        Text unMatch(s,color,30);
        unMatch.load(renderer,"../data/fonts/Playa-Light.ttf");
        lesmatch_Affiche.push_back(unMatch);
    }
    // for(int it = 0; it < lesmatch_Affiche.size(); it ++){
    //     std::cout << lesmatch_Affiche[it].getS() << std::endl;
    // }
    /////

    // Affichage des matchs quarts sur boutons // 
    std::vector<Text> lesmatch_Affiche_quarts ;
    for(std::vector<Match>::iterator it = lesmatchQuarts.begin(); it != lesmatchQuarts.end(); it ++){
        s = it->Affichage();
        // std::cout << s << std::endl;
        Text unMatch(s,color,30);
        unMatch.load(renderer,"../data/fonts/Playa-Light.ttf");
        lesmatch_Affiche_quarts.push_back(unMatch);
    }
    /////

    // Affichage des matchs de demis sur boutons // 
    std::vector<Text> lesmatch_Affiche_demis ;
    for(std::vector<Match>::iterator it = lesmatchDemis.begin(); it != lesmatchDemis.end(); it ++){
        s = it->Affichage();
        // std::cout << s << std::endl;
        Text unMatch(s,color,30);
        unMatch.load(renderer,"../data/fonts/Playa-Light.ttf");
        lesmatch_Affiche_demis.push_back(unMatch);
    }
    /////

    // Affichage du match final sur boutons // 
    std::vector<Text> lesmatch_Affiche_final ;
    for(std::vector<Match>::iterator it = lematchFinal.begin(); it != lematchFinal.end(); it ++){
        s = it->Affichage();
        std::cout << s << std::endl;
        Text unMatch(s,color,30);
        unMatch.load(renderer,"../data/fonts/Playa-Light.ttf");
        lesmatch_Affiche_final.push_back(unMatch);
    }
    /////

    file.close();



    // Panneaux de fanzones //
    std::vector<Button> lesbouttonsPanneaux;
    std::vector<SDL_Rect> Rect_bouttonsPanneaux;
    int x = 3;
    for(int i = 0;i<3;i++){
        Button panneaux(x, h/4, w/3, h - 150);
        panneaux.load(renderer, "../data/images/panneau.png");
        lesbouttonsPanneaux.push_back(panneaux);
        // std::cout << panneaux.getButtonRect().y << std::endl;
        Rect_bouttonsPanneaux.push_back(panneaux.getButtonRect());
        x+=w/3;
    }
    ////

    SDL_Color couleurBleu={0,128,255,0};
    SDL_Color colorNoire={0,0,0,0};
    // Textes + image panneaux resto //
    std::ifstream fileResto("../data/txt/resto.txt");
    Les_Lieux restaurants(fileResto);
    std::vector<Lieu> restos = restaurants.getLesLieux();
    Image imageResto;
    imageResto.load(renderer,"../data/images/resto.jpg");
    Image imageRestoFlou;
    imageRestoFlou.load(renderer,"../data/images/resto_flou.jpg");


    std::vector<Text> lesnomsRestos ;
    for(int it = 0; it < restos.size(); it ++){
        Text unResto(restos[it].getNom(),couleurBleu,30);
        unResto.load(renderer,"../data/fonts/Imperfecta_Regular.ttf");
        lesnomsRestos.push_back(unResto);
    }

    std::vector<Text> lesadressesRestos ;
    for(int it = 0; it < restos.size(); it ++){
        Text unResto("Adresse : "+restos[it].getAdresse(),colorNoire,18);
        unResto.load(renderer,"../data/fonts/Aceh-Light.ttf");
        lesadressesRestos.push_back(unResto);
    }

    std::vector<Text> lescapacitesRestos ;
    for(int it = 0; it < restos.size(); it ++){
        Text unResto("Capacite humaine : "+std::to_string(restos[it].getCapacite()),colorNoire,18);
        unResto.load(renderer,"../data/fonts/Aceh-Light.ttf");
        lescapacitesRestos.push_back(unResto);
    }

    std::vector<Text> nbEcransRestos ;
    for(int it = 0; it < restos.size(); it ++){
        Text unResto("Nombre d'ecran : "+std::to_string(restos[it].getNb_ecran()),colorNoire,18);
        unResto.load(renderer,"../data/fonts/Aceh-Light.ttf");
        nbEcransRestos.push_back(unResto);
    }

    std::vector<Text> nbPrixRestos ;
    for(int it = 0; it < restos.size(); it ++){
        Text unResto("Prix d'entree : "+std::to_string(restos[it].getPrix()) + " euros",colorNoire,18);
        unResto.load(renderer,"../data/fonts/Aceh-Light.ttf");
        nbPrixRestos.push_back(unResto);
    }
    ////

    // Textes + image panneaux salles //
    std::ifstream fileSalles("../data/txt/resto.txt");
    Les_Lieux salless(fileSalles);
    std::vector<Lieu> salles = salless.getLesLieux();
    Image imageSalle;
    imageSalle.load(renderer,"../data/images/salles.jpg");
    Image imageSalleFlou;
    imageSalleFlou.load(renderer,"../data/images/salles_flou.jpg");

    std::vector<Text> lesnomsSalles ;
    for(int it = 0; it < salles.size(); it ++){
        Text salle(salles[it].getNom(),couleurBleu,30);
        salle.load(renderer,"../data/fonts/Imperfecta_Regular.ttf");
        lesnomsSalles.push_back(salle);
    }

    std::vector<Text> lesadressesSalles ;
    for(int it = 0; it < salles.size(); it ++){
        Text salle("Adresse : "+salles[it].getAdresse(),colorNoire,18);
        salle.load(renderer,"../data/fonts/Aceh-Light.ttf");
        lesadressesSalles.push_back(salle);
    }

    std::vector<Text> lescapacitesSalles ;
    for(int it = 0; it < salles.size(); it ++){
        Text salle("Capacite humaine : "+std::to_string(salles[it].getCapacite()),colorNoire,18);
        salle.load(renderer,"../data/fonts/Aceh-Light.ttf");
        lescapacitesSalles.push_back(salle);
    }

    std::vector<Text> nbEcransSalles ;
    for(int it = 0; it < salles.size(); it ++){
        Text salle("Nombre d'ecran : "+std::to_string(salles[it].getNb_ecran()),colorNoire,18);
        salle.load(renderer,"../data/fonts/Aceh-Light.ttf");
        nbEcransSalles.push_back(salle);
    }

    std::vector<Text> nbPrixSalles ;
    for(int it = 0; it < salles.size(); it ++){
        Text salle("Prix d'entree : "+std::to_string(salles[it].getPrix()) + " euros",colorNoire,18);
        salle.load(renderer,"../data/fonts/Aceh-Light.ttf");
        nbPrixSalles.push_back(salle);
    }
    ////
    // Textes + image panneaux bar //
    std::ifstream fileBar("../data/txt/bar.txt");
    Les_Lieux barss(fileBar);
    std::vector<Lieu> bars = barss.getLesLieux();
    Image imageBar;
    imageBar.load(renderer,"../data/images/bar.jpg");
    Image imageBarFlou;
    imageBarFlou.load(renderer,"../data/images/bar_flou.jpg");

    std::vector<Text> lesnomsBars ;
    for(int it = 0; it < bars.size(); it ++){
        Text bar(bars[it].getNom(),couleurBleu,30);
        bar.load(renderer,"../data/fonts/Imperfecta_Regular.ttf");
        lesnomsBars.push_back(bar);
    }

    std::vector<Text> lesadressesBars ;
    for(int it = 0; it < bars.size(); it ++){
        Text bar("Adresse : "+bars[it].getAdresse(),colorNoire,18);
        bar.load(renderer,"../data/fonts/Aceh-Light.ttf");
        lesadressesBars.push_back(bar);
    }

    std::vector<Text> lescapacitesBars ;
    for(int it = 0; it < bars.size(); it ++){
        Text bar("Capacite humaine : "+std::to_string(bars[it].getCapacite()),colorNoire,18);
        bar.load(renderer,"../data/fonts/Aceh-Light.ttf");
        lescapacitesBars.push_back(bar);
    }

    std::vector<Text> nbEcransBars ;
    for(int it = 0; it < bars.size(); it ++){
        Text bar("Nombre d'ecran : "+std::to_string(bars[it].getNb_ecran()),colorNoire,18);
        bar.load(renderer,"../data/fonts/Aceh-Light.ttf");
        nbEcransBars.push_back(bar);
    }

    std::vector<Text> nbPrixBars ;
    for(int it = 0; it < bars.size(); it ++){
        Text bar("Prix d'entree : "+std::to_string(bars[it].getPrix()) + " euros",colorNoire,18);
        bar.load(renderer,"../data/fonts/Aceh-Light.ttf");
        nbPrixBars.push_back(bar);
    }
    ////


    SDL_UpdateWindowSurface(window);
    bool keep_window_open = true;
    bool next_window = false;
    bool pageOneMatch = false;
    bool pageTwoMatch = false;
    bool choixfanzones = false;
    bool window_resto = false;
    bool window_bar = false;
    bool window_salle = false;
    int iter;
    int tour = 0;
    int tab[3];
    srand(time(NULL));
    for(int j=0;j<lesbouttonsPanneaux.size();j++){
        tab[j]=rand()%lesbouttonsPanneaux.size();
    }

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
                        next_window = true;
                        pageOneMatch = true;
                    }
                    if (e.key.keysym.sym == SDLK_ESCAPE)
                        keep_window_open = false;
                    break;
                case SDL_MOUSEBUTTONDOWN: // Lorsqu'on clique avec la souris //
                    int x,y;
                    if(tour==0 && next_window){
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
                    }
                    else if(tour == 1 && next_window){
                        if (SDL_GetMouseState(&x, &y) & SDL_BUTTON(SDL_BUTTON_LEFT)&& next_window){
                            for(int it = 0; it < lesbouttonsHuit.size(); it ++){
                                if(lesbouttonsHuit[it].pressed(x,y) && next_window){
                                    std::cout << "bouton cliqué" << std::endl;
                                    next_window = false;
                                    choixfanzones = true;
                                    iter = it;
                                }
                            }
                            for(int j=0;j<lesbouttonsPanneaux.size();j++){
                                tab[j]=rand()%lesbouttonsPanneaux.size();
                            }
                        }
                    }
                    else if(tour == 2 && next_window){
                        if (SDL_GetMouseState(&x, &y) & SDL_BUTTON(SDL_BUTTON_LEFT)&& next_window){
                            for(int it = 0; it < lesbouttonsDemi.size(); it ++){
                                if(lesbouttonsDemi[it].pressed(x,y) && next_window){
                                    std::cout << "bouton cliqué" << std::endl;
                                    next_window = false;
                                    choixfanzones = true;
                                    iter = it;
                                }
                            }
                            for(int j=0;j<lesbouttonsPanneaux.size();j++){
                                tab[j]=rand()%lesbouttonsPanneaux.size();
                            }
                        }
                    }               
                    else if(tour == 3 && next_window){
                        if (SDL_GetMouseState(&x, &y) & SDL_BUTTON(SDL_BUTTON_LEFT)&& next_window){
                            if(lebouttonFinal[0].pressed(x,y) && next_window){
                                std::cout << "bouton cliqué" << std::endl;
                                next_window = false;
                                choixfanzones = true;
                                iter = 0;
                            }
                                  srand(time(NULL));
                            for(int j=0;j<lesbouttonsPanneaux.size();j++){
                                tab[j]=rand()%lesbouttonsPanneaux.size();
                            }
                        }

                    }      

                    else if (SDL_GetMouseState(&x, &y) & SDL_BUTTON(SDL_BUTTON_LEFT)&& choixfanzones){
                        for(int it = 0; it < lesbouttonsPanneaux.size(); it ++){
                            if(lesbouttonsPanneaux[it].pressed(x,y)){
                                next_window=false;
                                if(it==0){
                                    window_resto = true;
                                    window_bar = false;
                                    window_salle = false;
                                }
                                else if(it==1){
                                    window_resto = false;
                                    window_salle = true;
                                    window_bar = false;
                                }
                                else{
                                    window_resto = false;
                                    window_bar = true;
                                    window_salle = false;
                                }
                                choixfanzones=false;
                                
                            }
                        }
                    }
                    else if (SDL_GetMouseState(&x, &y) & SDL_BUTTON(SDL_BUTTON_LEFT)&& (window_bar || window_resto || window_salle)){
                        if(nextd.pressed(x,y)){
                            next_window = true;
                            window_resto = false;
                            window_bar = false;
                            window_salle = false;
                            tour++;
                            // std::cout << tour << std::endl;
                        }
                    }
                    break;
                }
            }

        SDL_RenderClear(renderer);
        if(next_window && tour == 0){
            if(pageOneMatch == true){
                image_next_window.draw(renderer);
                TextHuitieme.draw(renderer,TextHuit);
                for(int it = 0; it < lesbouttonsHuit.size(); it ++){
                    lesbouttonsHuit[it].draw(renderer);
                }
                for(int i = 0; i < lesmatch_Affiche.size(); i++){
                    if(i<4){
                        // std::cout << lesmatch[0].getCountryA() << std::endl;
                        // std::string g = lesmatch[0].getCountryA();
                        imageMap[lesmatch[i].getCountryA()].drawRectg(renderer,Rect_bouttons[i]);
                        imageMap[lesmatch[i].getCountryB()].drawRectd(renderer,Rect_bouttons[i]);
                        lesmatch_Affiche[i].drawOnButton(renderer,Rect_bouttons[i]);
                    }
                }
                nextd.draw(renderer);
            }
            else if(pageTwoMatch == true){
                image_next_window.draw(renderer);
                TextHuitieme.draw(renderer,TextHuit);
                for(int it = 0; it < lesbouttonsHuit.size(); it ++){
                    lesbouttonsHuit[it].draw(renderer);          
                }
                for(int i = 0; i < lesmatch_Affiche.size(); i++){
                    if(i>3){
                        imageMap[lesmatch[i].getCountryA()].drawRectg(renderer,Rect_bouttons[i-4]);
                        imageMap[lesmatch[i].getCountryB()].drawRectd(renderer,Rect_bouttons[i-4]);
                        lesmatch_Affiche[i].drawOnButton(renderer,Rect_bouttons[i-4]);
                    }
                }
                nextg.draw(renderer);
            }
        }   

        else if(next_window && tour==1){
            image_next_window.draw(renderer);
            TextQuarts.draw(renderer,TextHuit);
            for(int it = 0; it < lesbouttonsHuit.size(); it ++){
                lesbouttonsHuit[it].draw(renderer);
            }
            for(int i = 0; i < lesmatch_Affiche_quarts.size(); i++){
                // std::cout << lesmatch[0].getCountryA() << std::endl;
                imageMap[lesmatchQuarts[i].getCountryA()].drawRectg(renderer,Rect_bouttons[i]);
                imageMap[lesmatchQuarts[i].getCountryB()].drawRectd(renderer,Rect_bouttons[i]);
                lesmatch_Affiche_quarts[i].drawOnButton(renderer,Rect_bouttons[i]);
            }
        } 

        else if(next_window && tour==2){
            image_next_window.draw(renderer);
            TextDemi.draw(renderer,TextHuit);
            for(int it = 0; it < lesbouttonsDemi.size(); it ++){
                lesbouttonsDemi[it].draw(renderer);
            }
            for(int i = 0; i < lesmatch_Affiche_demis.size(); i++){
                // std::cout << lesmatch[0].getCountryA() << std::endl;
                imageMap[lesmatchDemis[i].getCountryA()].drawRectg(renderer,Rect_bouttons_demi[i]);
                imageMap[lesmatchDemis[i].getCountryB()].drawRectd(renderer,Rect_bouttons_demi[i]);
                lesmatch_Affiche_demis[i].drawOnButton(renderer,Rect_bouttons_demi[i]);
            }
        }

        else if(next_window && tour==3){
            image_next_window.draw(renderer);
            TextFinal.draw(renderer,TextHuit);
            for(int it = 0; it < lebouttonFinal.size(); it ++){
                lebouttonFinal[it].draw(renderer);
            }            
            for(int i = 0; i < lesmatch_Affiche_final.size(); i++){
                // std::cout << lematchFinal[0].getCountryA() << std::endl;
                imageMap[lematchFinal[i].getCountryA()].drawRectg(renderer,Rect_boutton_final[i]);
                imageMap[lematchFinal[i].getCountryB()].drawRectd(renderer,Rect_boutton_final[i]);
                lesmatch_Affiche_final[i].drawOnButton(renderer,Rect_boutton_final[i]);
            }
        }     

        else if(choixfanzones){
            image_next_window.draw(renderer);        
            // TextFanzone.draw(renderer,Textf);
            std::string s = "Voici les fanzones disponibles pour le match ";
            std::string match;
            if(tour==0){
                match = lesmatch[iter].Affichage();
            }
            else if(tour==1){
                match = lesmatchQuarts[iter].Affichage();       
            }
            else if(tour==2){
                match = lesmatchDemis[iter].Affichage();
            }
            else if(tour==3){
                match = lematchFinal[iter].Affichage();
            }
            Text TextFanzone(s, color,30);
            Text TextFanzone2(match, color,30);
            TextFanzone.load(renderer,"../data/fonts/Playa-Light.ttf");
            TextFanzone2.load(renderer,"../data/fonts/Playa-Light.ttf");
            SDL_Rect Textf;
            Textf.x = (w - textWidth) / 2;
            Textf.y = (h - textHeight) / 13;
            Textf.w = TextFanzone.getTextSurface()->w;
            Textf.h = TextFanzone.getTextSurface()->h;
            TextFanzone.draw(renderer,Textf);
            
            int text2Width;
            int text2Height;
            SDL_QueryTexture(TextFanzone2.getTextTexture(), NULL, NULL, &text2Width, &text2Height);
            Textf.x = (w - text2Width) / 2;
            Textf.y = ((h - text2Height) / 13) +20;
            Textf.w = TextFanzone2.getTextSurface()->w;
            Textf.h = TextFanzone2.getTextSurface()->h;
            TextFanzone2.draw(renderer,Textf);
            // std::cout << "Le gagnant est "<< lesmatch[iter].getWinner()<< std::endl;

             for(int it = 0; it < lesbouttonsPanneaux.size(); it ++){
                if(it==0){
                    lesbouttonsPanneaux[it].draw(renderer);
                    lesnomsRestos[tab[it]].drawFanzoneButton(renderer,Rect_bouttonsPanneaux[it].x, Rect_bouttonsPanneaux[it].y);
                    lesadressesRestos[tab[it]].drawFanzoneButton(renderer,Rect_bouttonsPanneaux[it].x, Rect_bouttonsPanneaux[it].y+40);
                    lescapacitesRestos[tab[it]].drawFanzoneButton(renderer,Rect_bouttonsPanneaux[it].x, Rect_bouttonsPanneaux[it].y+70);
                    nbEcransRestos[tab[it]].drawFanzoneButton(renderer,Rect_bouttonsPanneaux[it].x, Rect_bouttonsPanneaux[it].y+100);
                    nbPrixRestos[tab[it]].drawFanzoneButton(renderer,Rect_bouttonsPanneaux[it].x, Rect_bouttonsPanneaux[it].y+130);
                    imageResto.drawOnButton(renderer,Rect_bouttonsPanneaux[it]);
                }
                else if(it==1){
                    lesbouttonsPanneaux[it].draw(renderer);
                    lesnomsSalles[tab[it]].drawFanzoneButton(renderer,Rect_bouttonsPanneaux[it].x, Rect_bouttonsPanneaux[it].y);
                    lesadressesSalles[tab[it]].drawFanzoneButton(renderer,Rect_bouttonsPanneaux[it].x, Rect_bouttonsPanneaux[it].y+40);
                    lescapacitesSalles[tab[it]].drawFanzoneButton(renderer,Rect_bouttonsPanneaux[it].x, Rect_bouttonsPanneaux[it].y+70);
                    nbEcransSalles[tab[it]].drawFanzoneButton(renderer,Rect_bouttonsPanneaux[it].x, Rect_bouttonsPanneaux[it].y+100);
                    nbPrixSalles[tab[it]].drawFanzoneButton(renderer,Rect_bouttonsPanneaux[it].x, Rect_bouttonsPanneaux[it].y+130);
                    imageSalle.drawOnButton(renderer,Rect_bouttonsPanneaux[it]);

                }
                else if(it==2){
                    lesbouttonsPanneaux[it].draw(renderer);
                    lesnomsBars[tab[it]].drawFanzoneButton(renderer,Rect_bouttonsPanneaux[it].x, Rect_bouttonsPanneaux[it].y);
                    lesadressesBars[tab[it]].drawFanzoneButton(renderer,Rect_bouttonsPanneaux[it].x, Rect_bouttonsPanneaux[it].y+40);
                    lescapacitesBars[tab[it]].drawFanzoneButton(renderer,Rect_bouttonsPanneaux[it].x, Rect_bouttonsPanneaux[it].y+70);
                    nbEcransBars[tab[it]].drawFanzoneButton(renderer,Rect_bouttonsPanneaux[it].x, Rect_bouttonsPanneaux[it].y+100);
                    nbPrixBars[tab[it]].drawFanzoneButton(renderer,Rect_bouttonsPanneaux[it].x, Rect_bouttonsPanneaux[it].y+130);
                    imageBar.drawOnButton(renderer,Rect_bouttonsPanneaux[it]);
                }
            }
            // lesresto[0].drawFanzoneButton(renderer,200,200);
            // lesresto[i].drawOnButton(renderer,Rect_bouttonsPanneaux[0]);  
        }    

        else if(window_resto || window_salle || window_bar){
            SDL_Rect textGagnant;
            if(tour==0){
                Text gagnant("Le gagnant du match est : " + lesmatch[iter].getWinner() + " !",color, 40);
                SDL_Surface * TextSurface = gagnant.getTextSurface();
                SDL_Texture * TextTexture = gagnant.getTextTexture();
                int textWidth, textHeight;
                SDL_QueryTexture(TextTexture, NULL, NULL, &textWidth, &textHeight);
                textGagnant.x = (w - textWidth) / 2;
                textGagnant.y = (h - textHeight) / 2;
                textGagnant.w = TextSurface->w;
                textGagnant.h = TextSurface->h;
                gagnant.load(renderer, "../data/fonts/Playa-Light.ttf");
                gagnant.draw(renderer,textGagnant);
                if(window_resto){
                    imageRestoFlou.draw(renderer);
                    gagnant.draw(renderer,textGagnant);
                    nextd.draw(renderer);
                }
                else if(window_salle){
                    imageSalleFlou.draw(renderer);
                    gagnant.draw(renderer,textGagnant);
                    nextd.draw(renderer);
                }
                else if(window_bar){
                    imageBarFlou.draw(renderer);
                    gagnant.draw(renderer,textGagnant);
                    nextd.draw(renderer);
                }
            }

            else if(tour==1){
                Text gagnant("Le gagnant du match est : " + lesmatchQuarts[iter].getWinner() + " !",color, 40);
                SDL_Surface * TextSurface = gagnant.getTextSurface();
                SDL_Texture * TextTexture = gagnant.getTextTexture();
                int textWidth, textHeight;
                SDL_QueryTexture(TextTexture, NULL, NULL, &textWidth, &textHeight);
                textGagnant.x = (w - textWidth) / 2;
                textGagnant.y = (h - textHeight) / 2;
                textGagnant.w = TextSurface->w;
                textGagnant.h = TextSurface->h;
                gagnant.load(renderer, "../data/fonts/Playa-Light.ttf");  
                if(window_resto){
                    imageRestoFlou.draw(renderer);
                    gagnant.draw(renderer,textGagnant);
                    nextd.draw(renderer);
                }
                else if(window_salle){
                    imageSalleFlou.draw(renderer);
                    gagnant.draw(renderer,textGagnant);
                    nextd.draw(renderer);
                }
                else if(window_bar){
                    imageBarFlou.draw(renderer);
                    gagnant.draw(renderer,textGagnant);
                    nextd.draw(renderer);
                }     
            }

            else if(tour==2){
                Text gagnant("Le gagnant du match est : " + lesmatchDemis[iter].getWinner() + " !",color, 40);
                SDL_Surface * TextSurface = gagnant.getTextSurface();
                SDL_Texture * TextTexture = gagnant.getTextTexture();
                int textWidth, textHeight;
                SDL_QueryTexture(TextTexture, NULL, NULL, &textWidth, &textHeight);
                textGagnant.x = (w - textWidth) / 2;
                textGagnant.y = (h - textHeight) / 2;
                textGagnant.w = TextSurface->w;
                textGagnant.h = TextSurface->h;
                gagnant.load(renderer, "../data/fonts/Playa-Light.ttf");
                if(window_resto){
                    imageRestoFlou.draw(renderer);
                    gagnant.draw(renderer,textGagnant);
                    nextd.draw(renderer);
                }
                else if(window_salle){
                    imageSalleFlou.draw(renderer);
                    gagnant.draw(renderer,textGagnant);
                    nextd.draw(renderer);
                }
                else if(window_bar){
                    imageBarFlou.draw(renderer);
                    gagnant.draw(renderer,textGagnant);
                    nextd.draw(renderer);
                }
            }

            else if(tour==3){
                Text gagnant("Le gagnant du match est : " + lematchFinal[iter].getWinner() + " !",color, 40);
                SDL_Surface * TextSurface = gagnant.getTextSurface();
                SDL_Texture * TextTexture = gagnant.getTextTexture();
                int textWidth, textHeight;
                SDL_QueryTexture(TextTexture, NULL, NULL, &textWidth, &textHeight);
                textGagnant.x = (w - textWidth) / 2;
                textGagnant.y = (h - textHeight) / 2;
                textGagnant.w = TextSurface->w;
                textGagnant.h = TextSurface->h;
                gagnant.load(renderer, "../data/fonts/Playa-Light.ttf");
                if(window_resto){
                    imageRestoFlou.draw(renderer);
                    gagnant.draw(renderer,textGagnant);
                    nextd.draw(renderer);
                }
                else if(window_salle){
                    imageSalleFlou.draw(renderer);
                    gagnant.draw(renderer,textGagnant);
                    nextd.draw(renderer);
                }
                else if(window_bar){
                    imageBarFlou.draw(renderer);
                    gagnant.draw(renderer,textGagnant);
                    nextd.draw(renderer);
                }
            }
        }

        else if(tour == 0){
            imageAccueil.draw(renderer);
            espace.drawOnWindow(renderer, w,h);
            textAccueil.draw(renderer,textRect);
        }
        else if(tour == 4){
            imageAccueil.draw(renderer);
            Text merci("A bientot !",color, 40);
            merci.load(renderer, "../data/fonts/CELEBRATE_RETRO.ttf");
            merci.draw(renderer,textRect);
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