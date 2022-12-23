# include "Game.h"
# include "STDIO.h"

Game::Game() {
	window = nullptr;
}

Game::~Game() {

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
	window = SDL_CreateWindow("LeageMovementPractice",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height-50, SDL_WINDOW_OPENGL);
	if (window == nullptr) printf(SDL_GetError()); // if window fails to create
	
	//Upon successful window creation listen for events
	SDL_Event event{};
	listen(event);
	
	// Upon application close
	SDL_DestroyWindow(window);
	SDL_Quit();
}

// listens and handles events
void Game::listen(SDL_Event event) {
	while (true) {

		if (SDL_PollEvent(&event)) { // if theres a pending event
			// needs to be in if statement so app can close
			if (event.type == SDL_QUIT) break;

			switch (event.type) {
				// add events to be caught here
			}

		}

	}

}
