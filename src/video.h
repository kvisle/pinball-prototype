#ifndef __VIDEO_H__
#define __VIDEO_H__

#include <SDL.h>

class video
{
	private:
		SDL_Surface *screen;

	public:
		video(int w, int h);
		~video(void);

		void draw(void);

};

#endif /* __VIDEO_H__ */
