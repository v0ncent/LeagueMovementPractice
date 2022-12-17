# pragma once
# include <SDL/SDL.h>
# include <GLEW/glew.h>
class Game{
public:
	Game();
	~Game();
	void run();
private:
	SDL_Window* window;
	void listen(SDL_Event event);
};