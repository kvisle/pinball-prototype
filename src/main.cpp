#include <SDL.h>

#include <cstdio>

#include "video.h"
#include "timer.h"
#include "game.h"

int main(int argc, char *argv[])
{
	video v(640, 480);
	timer t(60);
	game g;

	while(g.update())
	{
		v.draw();
		t.sync();
	}


	return 0;
	(void)argc;
	(void)argv;
}
