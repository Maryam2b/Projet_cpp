#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

class Music{

public:
    Music(const char * filepath);
    void playMusic();
    ~Music();

private:
    Mix_Music * music;
};


