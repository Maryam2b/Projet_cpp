#include "Application.hh"
// #include "Button.hh"


    Application :: Application(){
        window = NULL;
        renderer = NULL;
    }

    void Application :: setButtonRect(int x, int y, int w, int h){
        buttonRect.x = x;
        buttonRect.y = y;
        buttonRect.w = w;
        buttonRect.h = h;
    }

    SDL_Rect Application :: getButtonRect(){
        return buttonRect;
    }

    void Application :: initialisation(){

        next_window = false;
        second_window = false;
        keep_window_open = true;
        SDL_ShowCursor(false);

        //* Initialise la librairie SDL2 *//
        if(SDL_Init(SDL_INIT_VIDEO) < 0)
        {
            std::cout << "Failed to initialize the SDL2 library\n";
            std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        }

        window = SDL_CreateWindow("My Fanzone",
                                SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED,
                                1400, 800,
                                0);

        if(!window)
        {
            std::cout << "Failed to create window\n";
            std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        }

        //* Crée un renderer *//
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer == NULL) {
            std::cout << "Failed to create renderer\n";
            std::cout << "SDL Error: " << SDL_GetError() << "\n";
        }



        //* Charger les images de fond *//
        image = IMG_Load("../data/images/supporters.jpg");
        if (image == NULL) {
            std::cout << "Impossible de charger l'image 'supporters.jpg'\n" << std::endl;
            std::cout << "SDL Error: " << SDL_GetError() << "\n";
        }

        float aspect = (float)image->w / (float)image->h;
        imgRect.w = 1800;
        imgRect.h = (int)(400/aspect);

        imageTexture = SDL_CreateTextureFromSurface(renderer, image);
        if (!imageTexture) {
            std::cout << "Failed to create texture from surface\n";
            std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        }

        //* Charge image de fond *//
        image_matchs = IMG_Load("../data/images/matchs.png");
        float aspect2 = (float)image_matchs->w / (float)image_matchs->h;
        imgmatchsRect.w = 1800;
        imgmatchsRect.h = (int)(400/aspect2);
        image_matchsTexture = SDL_CreateTextureFromSurface(renderer, image_matchs);

        pelouse = IMG_Load("../data/images/pelouse.jpg");
        if (pelouse == NULL) {
            std::cout << "Impossible de charger l'image 'pelouse.jpg'\n";
            std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        }
        // SDL_FreeSurface(image);

        pelouseTexture = SDL_CreateTextureFromSurface(renderer, pelouse);
        if (!pelouseTexture) {
            std::cout << "Failed to create texture from surface\n";
            std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        }   



        //* Écriture du texte *// 
        if(TTF_Init()==-1) {
            printf("TTF_Init: %s\n", TTF_GetError());
            exit(2);
        }
        police = TTF_OpenFont("../data/fonts/CELEBRATE_RETRO.ttf",120);

        if(police != NULL) {
            std::cout << "ok à l'ouverture de CELEBRATE_RETRO.ttf" << std::endl;
        }
        else{
            std::cout << "foirage à l'ouverture de CELEBRATE_RETRO.ttf" << std::endl;
        }

        SDL_Color color={255,255,255,255};
        std::string textText="My Fanzone";
        TextSurface = TTF_RenderText_Solid(police,textText.c_str(), color);
        if (!TextSurface) {
            std::cout << "Failed to create surface from text\n";
            std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        }

        textTexture = SDL_CreateTextureFromSurface(renderer, TextSurface);
        if (!textTexture) {
            std::cout << "Failed to create texture from surface\n";
            std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        }
        textRect.x = (160 + TextSurface->w)/2;
        textRect.y = (600 + TextSurface->h)/2;
        textRect.w = TextSurface->w;
        textRect.h = TextSurface->h;
    }


void Application :: Renderer(Mouse mouse){
        if(next_window){

        //* pour le boutton *//
        SDL_Surface * buttonSurface = IMG_Load("../data/images/button.png");
        SDL_Texture * buttonTexture = SDL_CreateTextureFromSurface(renderer, buttonSurface);
        setButtonRect(500, 400, 500, 200);
            SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer, image_matchsTexture, NULL, NULL);
            SDL_RenderCopy(renderer, buttonTexture, NULL, &buttonRect);
            mouse.draw(renderer,mouseRect);
            SDL_RenderPresent(renderer);
        }
        
        else if(second_window){
            SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer, pelouseTexture, NULL, NULL);
            // SDL_RenderCopy(renderer, neymarTexture, NULL, &neymarRect);
            mouse.draw(renderer,mouseRect);
            SDL_RenderPresent(renderer);
        }

        else {
            //* Clear the window *//
            SDL_RenderClear(renderer);
            //* Copy the texture to the window *//
            imgRect.x = (1400-imgRect.w)/2;
            imgRect.y = (800-imgRect.h)/2;
            SDL_RenderCopy(renderer, imageTexture, NULL, NULL);
            SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
            //* Update the window *//
            mouse.draw(renderer,mouseRect);
            SDL_RenderPresent(renderer);
        }
}

void Application :: destroyRenderer(){
    //* Libérer les resources *//
    SDL_FreeSurface(TextSurface);
    SDL_DestroyTexture(textTexture);
    SDL_DestroyTexture(imageTexture);
    TTF_CloseFont(police);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Application :: run(){
    Mouse mouse(renderer);
    SDL_ShowCursor(false);
    SDL_UpdateWindowSurface(window);
    while(keep_window_open)
    {
        SDL_Event e;
        mouseRect = mouse.update();
        while(SDL_PollEvent(&e) > 0)
        {
            switch(e.type)
            {
                case SDL_QUIT:
                    keep_window_open = false;
                    break;
                case SDL_KEYDOWN: //* Lorsqu'on clique sur une touche du clavier *//
                    if (e.key.keysym.sym == SDLK_SPACE)
                    next_window = true;
                    if (e.key.keysym.sym == SDLK_ESCAPE)
                    keep_window_open = false;
                    break;
                case SDL_MOUSEBUTTONDOWN: //* Lorsqu'on clique avec la souris *//
                    int x,y;

                    if (SDL_GetMouseState(&x, &y) & SDL_BUTTON(SDL_BUTTON_LEFT)){
                        if(x>= buttonRect.x && x <= buttonRect.x + buttonRect.w && y >= buttonRect.y && y <= buttonRect.y + buttonRect.h){
                            second_window = true;
                            next_window = false;
                        }
                    }
                    break;
                }
                 Renderer(mouse);
            }
    }
    destroyRenderer();
}

