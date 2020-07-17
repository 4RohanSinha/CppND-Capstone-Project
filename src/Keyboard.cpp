#include "Keyboard.h"
#include <iostream>

const std::unordered_map<KeyCharacter, Uint8, std::hash<std::underlying_type<KeyCharacter>::type>> Keyboard::keys_ = { 
	{KeyCharacter::keyLeftArr, SDL_SCANCODE_LEFT},
        {KeyCharacter::keyRightArr, SDL_SCANCODE_RIGHT},
        {KeyCharacter::keyUpArr, SDL_SCANCODE_UP},
	{KeyCharacter::keyDownArr, SDL_SCANCODE_DOWN},
	{KeyCharacter::keyA, SDL_SCANCODE_A},
	{KeyCharacter::keyB, SDL_SCANCODE_B},
	{KeyCharacter::keyC, SDL_SCANCODE_C},
	{KeyCharacter::keyD, SDL_SCANCODE_D},
	{KeyCharacter::keyE, SDL_SCANCODE_E},
	{KeyCharacter::keyF, SDL_SCANCODE_F},
	{KeyCharacter::keyG, SDL_SCANCODE_G},
	{KeyCharacter::keyH, SDL_SCANCODE_H},
	{KeyCharacter::keyI, SDL_SCANCODE_I},
	{KeyCharacter::keyJ, SDL_SCANCODE_J},
	{KeyCharacter::keyK, SDL_SCANCODE_K},
	{KeyCharacter::keyL, SDL_SCANCODE_L},
	{KeyCharacter::keyM, SDL_SCANCODE_M},
	{KeyCharacter::keyN, SDL_SCANCODE_N},
	{KeyCharacter::keyO, SDL_SCANCODE_O},
	{KeyCharacter::keyP, SDL_SCANCODE_P},
	{KeyCharacter::keyQ, SDL_SCANCODE_Q},
	{KeyCharacter::keyR, SDL_SCANCODE_R},
	{KeyCharacter::keyS, SDL_SCANCODE_S},
	{KeyCharacter::keyT, SDL_SCANCODE_T},
	{KeyCharacter::keyU, SDL_SCANCODE_U},
	{KeyCharacter::keyV, SDL_SCANCODE_V},
	{KeyCharacter::keyW, SDL_SCANCODE_W},
	{KeyCharacter::keyX, SDL_SCANCODE_X},
	{KeyCharacter::keyY, SDL_SCANCODE_Y},
	{KeyCharacter::keyZ, SDL_SCANCODE_Z},
	{KeyCharacter::key0, SDL_SCANCODE_0},
	{KeyCharacter::key1, SDL_SCANCODE_1},
	{KeyCharacter::key2, SDL_SCANCODE_2},
	{KeyCharacter::key3, SDL_SCANCODE_3},
	{KeyCharacter::key4, SDL_SCANCODE_4},
	{KeyCharacter::key5, SDL_SCANCODE_5},
	{KeyCharacter::key6, SDL_SCANCODE_6},
	{KeyCharacter::key7, SDL_SCANCODE_7},
	{KeyCharacter::key8, SDL_SCANCODE_8},
	{KeyCharacter::key9, SDL_SCANCODE_9}
};

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

std::vector<KeyCharacter> Keyboard::GetPressedKeys() {
	Update();
	std::vector<KeyCharacter> res;
	
	for (auto i: keys_) {
		if (keyStates_[i.second]) {
			res.push_back(i.first);
		}
	}
	return res;
}

bool Keyboard::GetStatusOfKey(KeyCharacter key) {
	return keyStates_[ConvertToSDL(key)];
}
