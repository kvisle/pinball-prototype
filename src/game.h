#ifndef __GAME_H__
#define __GAME_H__

#include <SDL.h>

#include "box.h"

class game
{
    private:
        void input(void);
        void destroymarked(void);

        int quit;

        void key(SDL_Event k);

    public:
        box *b;
        game(const char *s);
        ~game(void);
        int update(void);

};

#endif /* __GAME_H__ */
