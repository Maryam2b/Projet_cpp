#include "Music.hh"
#include <iostream>

Music :: Music(const char * filepath){
    // Initialisation de SDL_mixer
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

    // Chargement de la musique
    music = Mix_LoadMUS(filepath);
    if (music == NULL) {
        std::cout << "Erreur de chargement de la musique : %s\n" << std::endl;
    }
}

void Music :: playMusic(){
    Mix_PlayMusic(music, -1);
}

Music :: ~Music(){
    Mix_FreeMusic(music);
    Mix_CloseAudio();
}
