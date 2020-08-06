#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>
#include "Keyboard.h"
#include "Mouse.h"

class Input {
public:
	void Update();
	bool IsRunning() { return isRunning_; }
	std::vector<int> GetMouseCoordinates() { return mouse_.GetCoordinates(); }
	MouseButton GetMouseButton() { return mouse_.GetButtonClicked(); }
	std::vector<KeyCharacter> GetPressedKeys() { return keyboard_.GetPressedKeys(); }
	std::vector<KeyCharacter> GetReleasedKeys() { return keyboard_.GetReleasedKeys(); }
	KeyStatus GetStatusOfKey(KeyCharacter key) { return keyboard_.GetStatusOfKey(key); }
private:
	SDL_Event eventSDL_;
	bool isRunning_{true};
	Keyboard keyboard_;
	Mouse mouse_;
};

#endif
