#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>
#include "Event.h"
#include "Keyboard.h"

class Input {
public:
	Input();
	Event GetUserEvent();
	bool IsRunning() { return isRunning_; }
private:
	SDL_Event eventSDL_;
	bool isRunning_{true};
	std::unique_ptr<Keyboard> keyboard_;
};

#endif
