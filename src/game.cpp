#include <SDL.h>

#include "game.h"

game::game(const char *s)
{
    quit = 0;
    b = new box(s);
}

game::~game(void)
{
    delete(b);
}

void game::key(SDL_Event k)
{
    int down = ( k.key.state == SDL_PRESSED ) ? true : false;
    switch(k.key.keysym.sym)
    {
    case SDLK_LSHIFT:
        b->flip(0, down);
        break;
    case SDLK_RSHIFT:
        b->flip(1, down);
        break;
    case SDLK_SPACE:
        b->launch(down);
        break;
    default:
        break;
    }
}

void game::input(void)
{
    SDL_Event e;
    while(SDL_PollEvent(&e))
    {
        switch(e.type)
        {
        case SDL_QUIT:
            quit++;
            break;
        case SDL_KEYDOWN:
        case SDL_KEYUP:
            key(e);
            break;
        }
    }
}


void game::destroymarked(void)
{
    while ( !b->destroy.empty() )
    {
        b->world->DestroyBody(b->destroy.back());
        b->destroy.pop_back();
    }
}


int game::update(void)
{
    input();
    b->step();
    destroymarked();   

    if ( b->balls.size() == 0 )
    {
        b->newball(1.95f,1.f);
    }
//    cout << "Balls on the field: " << b->balls.size() << endl;

    return !quit;
}
