# include "EventManager.h"

void EventManager::mousePress(SDL_MouseButtonEvent& b){
	switch (b.button) {
		case SDL_BUTTON_RIGHT:
			Movement::pixelAtXY(b.x, b.y);
			break;
	}
}

void EventManager::mouseMove(SDL_MouseMotionEvent& m) {
	std::cout << m.x << " " << m.y << std::endl;
}
