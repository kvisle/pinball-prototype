AM_CFLAGS = -Wall 
bin_PROGRAMS = coder
coder_SOURCES = main.cpp video.cpp

coder_LDADD = -L../lib/lib_json -ljsoncpp \
              -L../lib/Box2D -lbox2d \
			 $(OPENAL_LIBS) \
			 $(GL_LIBS) \
             $(SDL_LIBS)

EXTRA_DIST = video.h

coder_CXXFLAGS = -Wall -Wextra -g \
				-I../include \
                -I../lib/ \
				$(OPENAL_CFLAGS) \
				$(GL_CFLAGS) \
				$(SDL_CFLAGS) 
