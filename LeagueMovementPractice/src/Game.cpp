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

// Inits systems and creates window
void Game::run() {
	// Init
	SDL_Init(SDL_INIT_EVERYTHING);

	// Create Window
	SDL_DisplayMode DM;
	SDL_GetCurrentDisplayMode(0, &DM);
	auto width = DM.w;
	auto height = DM.h;
	_window = SDL_CreateWindow("LeageMovementPractice",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height-50, SDL_WINDOW_OPENGL);
	if (_window == nullptr) { // if window fails to create
		printf(SDL_GetError()); 
		Game::~Game();
	}

	// OPENGL Context
	SDL_GLContext glContext = SDL_GL_CreateContext(_window);
	if (glContext == nullptr) { // if failed to create context
		printf(SDL_GetError());
		Game::~Game();
	}
	
	// GLEW
	GLenum error = glewInit();
	if (error != GLEW_OK) {
		printf("Glew failed to initialize");
		Game::~Game();
	}

	// set sdl gl attributes
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	// set background on launch and for buffers
	glClearColor(0.0f,0.0f,1.0f,1.0);

	// Upon successful window creation listen for events
	SDL_Event event{};
	listen(event);
	
	// Upon application close
	SDL_DestroyWindow(_window);
	Game::~Game();
}

// Renders graphics
void Game::draw() {
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// TEMP CODE (immediate mode) <---- remove later when better system learned
	glDisableClientState(GL_COLOR_ARRAY);
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(0,0);
	glVertex2f(0,500);
	glVertex2f(500,500);
	glEnd();

	SDL_GL_SwapWindow(_window);
}

// listens and handles events / runs game loop
void Game::listen(SDL_Event event) {
	while (_gameState != GameState::EXIT) {

		// render graphics
		draw();

		if (SDL_PollEvent(&event)) { // if theres a pending event

			switch (event.type) {

				case SDL_QUIT : 
					_gameState = GameState::EXIT;
					break;

				case SDL_MOUSEMOTION:
					EventManager::mouseMove(event.motion);
					break;

				case SDL_MOUSEBUTTONDOWN:
					EventManager::mousePress(event.button);
					break;

			}

		}

	}

}
