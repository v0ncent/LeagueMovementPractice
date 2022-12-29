# include "Game.h"
# include "STDIO.h"
# include <iostream>

Game::Game() {
	_window = nullptr;
	_gameState = GameState::START;
}

Game::~Game() {
	printf("Shutting Down.");
	SDL_Quit();
}

// Inits SDL and creates window
void Game::run() {
	//Init
	SDL_Init(SDL_INIT_EVERYTHING);

	//Create Window
	SDL_DisplayMode DM;
	SDL_GetCurrentDisplayMode(0, &DM);
	auto width = DM.w;
	auto height = DM.h;
	_window = SDL_CreateWindow("LeageMovementPractice",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height-50, SDL_WINDOW_OPENGL);
	if (_window == nullptr) { // if window fails to create
		printf(SDL_GetError()); 
		Game::~Game();
	}

	//OPENGL Context

	
	//Upon successful window creation listen for events
	SDL_Event event{};
	listen(event);
	
	// Upon application close
	SDL_DestroyWindow(_window);
	Game::~Game();
}

// listens and handles events / runs game loop
void Game::listen(SDL_Event event) {
	while (_gameState != GameState::EXIT) {

		if (SDL_PollEvent(&event)) { // if theres a pending event

			switch (event.type) {

				case SDL_QUIT : _gameState = GameState::EXIT;
					break;

				case SDL_MOUSEMOTION:
					std::cout << event.motion.x << " " << event.motion.y << std::endl;
					break;

			}

		}

	}

}
