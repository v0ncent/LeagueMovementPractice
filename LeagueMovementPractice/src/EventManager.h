# pragma once

// define for legacy systems
# ifndef EVENT_MANAGER
# define EVENT_MANAGER

# include <SDL/SDL.h>
# include <GLEW/glew.h>
# include "Movement.h"
# include <iostream>

class EventManager {
public:
	static void mousePress(SDL_MouseButtonEvent& b);
	static void mouseMove(SDL_MouseMotionEvent& m);

private:

};

# endif

