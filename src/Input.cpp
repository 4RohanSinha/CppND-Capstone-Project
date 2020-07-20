#include <iostream>
#include "Input.h"

Input::Input() {
	keyboard_ = std::make_unique<Keyboard>();
	mouse_ = std::make_unique<Mouse>();
}

void Input::Update() {
	SDL_PollEvent(&eventSDL_);
	if (eventSDL_.type == SDL_QUIT) {
		isRunning_ = false;
	}
	keyboard_->Update();
	mouse_->Update();
}

//TODO: get rid of the following method
//also, see if static methods can be replaced
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
		switch(eventSDL_.key.keysym.sym) {
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
			case SDLK_0:
				key = KeyCharacter::key0;
				break;
			case SDLK_1:
				key = KeyCharacter::key1;
				break;
			case SDLK_2:
				key = KeyCharacter::key2;
				break;
			case SDLK_3:
				key = KeyCharacter::key3;
				break;
			case SDLK_4:
				key = KeyCharacter::key4;
				break;
			case SDLK_5:
				key = KeyCharacter::key5;
				break;
			case SDLK_6:
				key = KeyCharacter::key6;
				break;
			case SDLK_7:
				key = KeyCharacter::key7;
				break;
			case SDLK_8:
				key = KeyCharacter::key8;
				break;
			case SDLK_9:
				key = KeyCharacter::key9;
				break;
			case SDLK_a:
				key = KeyCharacter::keyA;
				break;
			case SDLK_b:
				key = KeyCharacter::keyB;
				break;
			case SDLK_c:
				key = KeyCharacter::keyC;
				break;
			case SDLK_d:
				key = KeyCharacter::keyD;
				break;
			case SDLK_e:
				key = KeyCharacter::keyE;
				break;
			case SDLK_f:
				key = KeyCharacter::keyF;
				break;
			case SDLK_g:
				key = KeyCharacter::keyG;
				break;
			case SDLK_h:
				key = KeyCharacter::keyH;
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
			case SDLK_0:
				key = KeyCharacter::key0;
				break;
			case SDLK_1:
				key = KeyCharacter::key1;
				break;
			case SDLK_2:
				key = KeyCharacter::key2;
				break;
			case SDLK_3:
				key = KeyCharacter::key3;
				break;
			case SDLK_4:
				key = KeyCharacter::key4;
				break;
			case SDLK_5:
				key = KeyCharacter::key5;
				break;
			case SDLK_6:
				key = KeyCharacter::key6;
				break;
			case SDLK_7:
				key = KeyCharacter::key7;
				break;
			case SDLK_8:
				key = KeyCharacter::key8;
				break;
			case SDLK_9:
				key = KeyCharacter::key9;
				break;
			case SDLK_a:
				key = KeyCharacter::keyA;
				break;
			case SDLK_b:
				key = KeyCharacter::keyB;
				break;
			case SDLK_c:
				key = KeyCharacter::keyC;
				break;
			case SDLK_d:
				key = KeyCharacter::keyD;
				break;
			case SDLK_e:
				key = KeyCharacter::keyE;
				break;
			case SDLK_f:
				key = KeyCharacter::keyF;
				break;
			case SDLK_g:
				key = KeyCharacter::keyG;
				break;
			case SDLK_h:
				key = KeyCharacter::keyH;
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
