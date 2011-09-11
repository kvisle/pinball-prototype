#include <SDL.h>

#include <cstdio>

#include "video.h"
#include "timer.h"
#include "game.h"

int main(int argc, char *argv[])
{
    video v(600, 900);
    timer t(60);
    game g("pinball.json");

    while(g.update())
    {
        v.draw(&g);
        t.sync();
    }


    return 0;
    (void)argc;
    (void)argv;
}
