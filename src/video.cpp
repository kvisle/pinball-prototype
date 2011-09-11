#include <GL/gl.h>

#include "game.h"
#include "video.h"

video::video(int w, int h)
{
//    screen = SDL_SetVideoMode(w, h, 24, SDL_OPENGL);
    screen = SDL_SetVideoMode(w,h,32,SDL_OPENGL);
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(  0, 2,
            -3,   0,
            -10.0,  10.0);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_TEXTURE_2D);
    glClearColor(0, 0, 0, 1.0);
}

video::~video(void)
{
    SDL_Quit();
}

void video::draw(game *g)
{
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    g->b->world->DrawDebugData();

    SDL_GL_SwapBuffers();
}
