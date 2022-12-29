# pragma once

// define for legacy systems
#ifndef GAME
#define GAME

# include <SDL/SDL.h>
# include <GLEW/glew.h>

// game state enum
enum class GameState{START,EXIT};

// game object
class Game{
public:
	Game();
	~Game();
	void run();
private:
	SDL_Window* _window;
	GameState _gameState;

	void listen(SDL_Event event);
	void draw();
};

#endif