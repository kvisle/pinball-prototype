#ifndef __VIDEO_H__
#define __VIDEO_H__

#include <SDL.h>

#include "game.h"

class video
{
    private:
        SDL_Surface *screen;

    public:
        video(int w, int h);
        ~video(void);

        void draw(game *g);

};

#endif /* __VIDEO_H__ */
