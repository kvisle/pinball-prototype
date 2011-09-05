#include "video.h"

video::video(int w, int h)
{
    screen = SDL_SetVideoMode(w, h, 24, SDL_OPENGL);
}

video::~video(void)
{
    SDL_Quit();
}

void video::draw(void)
{

}
