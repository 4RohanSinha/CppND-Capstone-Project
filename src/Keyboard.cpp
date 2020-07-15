#include "Keyboard.h"

const std::unordered_map<KeyCharacter, Uint8, std::hash<std::underlying_type<KeyCharacter>::type>> Keyboard::keys_ = {{KeyCharacter::keyLeftArr, SDL_SCANCODE_LEFT},
                {KeyCharacter::keyRightArr, SDL_SCANCODE_RIGHT},
                {KeyCharacter::keyUpArr, SDL_SCANCODE_UP},
                {KeyCharacter::keyDownArr, SDL_SCANCODE_DOWN}};

Keyboard::Keyboard() {
	keyStates_ = SDL_GetKeyboardState(NULL);
}

Uint8 Keyboard::ConvertToSDL(KeyCharacter key) {
	//Source: http://www.cplusplus.com/reference/unordered_map/unordered_map/find/
	return keys_.find(key)->second;
}

void Keyboard::Update() {
	SDL_PumpEvents();
}

bool Keyboard::GetStatusOfKey(KeyCharacter key) {
	return keyStates_[ConvertToSDL(key)];
}
