#include <SDL2/SDL.h>
#include "Controller.h"

void Controller::ListenForUserInput() {
	SDL_PollEvent(&event);
	EventType eType;
	std::shared_ptr<Event> e = nullptr;
	if (event.type == SDL_QUIT) {
		eType = EventType::kQuit;
		isRunning_ = false;
	}

	else if (event.type == SDL_KEYDOWN) {
		eType = EventType::kDownKey;
	}
	
	else if (event.type == SDL_KEYUP) {
		eType = EventType::kUpKey;
	}
	
	else if (event.type == SDL_FINGERDOWN) {
		eType = EventType::kTapDown;
	}
	
	else if (event.type == SDL_FINGERUP) {
		eType = EventType::kTapUp;
	}

	else if (event.type == SDL_FINGERMOTION) {
		eType = EventType::kTapDown;
	}


}

std::shared_ptr<Event> Controller::ReceiveNextEvent() {
	std::shared_ptr<Event> nextEvent = events_.front();
	events_.pop();
	return nextEvent;
}
