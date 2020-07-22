#include <iostream>
#include "Input.h"

void Input::Update() {
	SDL_PollEvent(&eventSDL_);
	if (eventSDL_.type == SDL_QUIT) {
		isRunning_ = false;
	}
	keyboard_.Update();
	mouse_.Update();
}

