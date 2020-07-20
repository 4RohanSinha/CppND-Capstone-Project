#include "Keyboard.h"
#include <algorithm>
#include <iterator>
#include <iostream>

//dictionary connecting the KeyCharacter enum to the Uint8 keyboard values
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
	{KeyCharacter::key9, SDL_SCANCODE_9},
	{KeyCharacter::keyReturn, SDL_SCANCODE_RETURN2},
	{KeyCharacter::keyTab, SDL_SCANCODE_TAB},
	{KeyCharacter::keySlash, SDL_SCANCODE_SLASH},
	{KeyCharacter::keyComma, SDL_SCANCODE_COMMA},
	{KeyCharacter::keyPeriod, SDL_SCANCODE_PERIOD}
};

//constructor
//creates a key for each value in the dictionary above
Keyboard::Keyboard() {
	keyStates_ = SDL_GetKeyboardState(NULL);
	for (auto i: keys_) {
		keyStatuses_[i.first] = KeyStatus::keyNone;
	}
}

//convert the enum to Uint8 format used in SDL2
Uint8 Keyboard::ConvertToSDL(KeyCharacter key) {
	//Source: http://www.cplusplus.com/reference/unordered_map/unordered_map/find/
	return keys_.find(key)->second;
}

//update the dictionary
void Keyboard::Update() {
	SDL_PumpEvents();
	UpdateKeyStatus();
}

//the following describes how the unordered_map keeps track of keys
//first: a key is pressed -> the unordered_map is updated, and the KeyStatus::keyPressed is stored to indicate that the key has been pressed
//if it has been released -> during the iteration in which it occurs, its status will change to KeyStatus::keyReleased
//then in the next iteration it will be changed to keyNone to indicate that the key is no longer active

//return vector of keys that are pressed
std::vector<KeyCharacter> Keyboard::GetPressedKeys() {
	return LookForKeyStatus(KeyStatus::keyPressed);
}

//return vector of keys that were pressed but now are released
std::vector<KeyCharacter> Keyboard::GetReleasedKeys() {
	return LookForKeyStatus(KeyStatus::keyReleased);
}

//return the status of a particular key
KeyStatus Keyboard::GetStatusOfKey(KeyCharacter key) {
	return keyStatuses_[key];
}

//update the unordered map as described above
void Keyboard::UpdateKeyStatus() {
	for (auto& i: keyStatuses_) {
		if (keyStates_[ConvertToSDL(i.first)]) {
			keyStatuses_[i.first] = KeyStatus::keyPressed;
			return;
		} else if (!keyStates_[ConvertToSDL(i.first)] && keyStatuses_[i.first] == KeyStatus::keyPressed) {
			keyStatuses_[i.first] = KeyStatus::keyReleased;
			return;
		} else if (keyStatuses_[i.first] == KeyStatus::keyReleased) {
			keyStatuses_[i.first] = KeyStatus::keyNone;
			return;
		}
	}
}

//this function is a private method designed to look for keys with a particular key status (KeyStatus::keyPressed for example)
//it is used in the Keyboard::GetPressedKeys() and Keyboard::GetReleasedKeys()
std::vector<KeyCharacter> Keyboard::LookForKeyStatus(KeyStatus status) {
	std::vector<KeyCharacter> res;
	for (auto& i: keyStatuses_) {
		if (keyStatuses_[i.first] == status) {
			res.push_back(i.first);
		}
	}

	return res;
}
