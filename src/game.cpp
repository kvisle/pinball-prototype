#include <SDL.h>

#include "game.h"

game::game(void)
{
	quit = 0;
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
		}
	}
}


int game::update(void)
{
	input();

	return !quit;
}
