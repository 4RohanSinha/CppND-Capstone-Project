#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>
#include "Event.h"

class Input {
public:
	Event GetUserEvent();
	bool IsRunning() { return isRunning_; }
private:
	SDL_Event eventSDL_;
	bool isRunning_{true};
};

#endif
