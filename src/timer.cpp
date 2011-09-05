#include <SDL.h>

#include "timer.h"

timer::timer(int f)
{
    fps = f;
    time = SDL_GetTicks();
}

void timer::sync(void)
{
    int t = (1000/fps)-(SDL_GetTicks()-time);
    if ( t > 0 && t < 1000 ) SDL_Delay(t);
    time = SDL_GetTicks();
}

