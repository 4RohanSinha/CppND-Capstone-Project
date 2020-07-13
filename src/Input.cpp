#include "Input.h"

Event Input::GetUserEvent() {
	SDL_PollEvent(&eventSDL_);

	EventType eType;
	Event e = Event(EventType::kNone);
	KeyCharacter key = KeyCharacter::kNone;

	if (eventSDL_.type == SDL_QUIT) {
		eType = EventType::kQuit;
		e.SetEventType(eType);
		isRunning_ = false;
		return e;
	} else if (eventSDL_.type == SDL_KEYDOWN) {
		eType = EventType::kDownKey;
		switch (eventSDL_.key.keysym.sym) {
			case SDLK_LEFT:
				key = KeyCharacter::keyLeftArr;
				break;
			case SDLK_RIGHT:
				key = KeyCharacter::keyRightArr;
				break;
			case SDLK_UP:
				key = KeyCharacter::keyUpArr;
				break;
			case SDLK_DOWN:
				key = KeyCharacter::keyDownArr;
				break;
		}

	} else if (eventSDL_.type == SDL_KEYUP) {
		eType = EventType::kUpKey;
		switch (eventSDL_.key.keysym.sym) {
			case SDLK_LEFT:
				key = KeyCharacter::keyLeftArr;
				break;
			case SDLK_RIGHT:
				key = KeyCharacter::keyRightArr;
				break;
			case SDLK_UP:
				key = KeyCharacter::keyUpArr;
				break;
			case SDLK_DOWN:
				key = KeyCharacter::keyDownArr;
				break;
		}



	} else if (eventSDL_.type == SDL_FINGERDOWN) {
		eType = EventType::kTapDown;
	} else if (eventSDL_.type == SDL_FINGERUP) {
		eType = EventType::kTapUp;
	} else if (eventSDL_.type == SDL_FINGERMOTION) {
		eType = EventType::kSwipe;
	}

	e.SetEventType(eType);
	e.SetKeyCharacter(key);
	return e;
}
