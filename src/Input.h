#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>
#include "Event.h"
#include "Keyboard.h"
#include "Mouse.h"

class Input {
public:
	Input();
	Event GetUserEvent();
	void Update();
	bool IsRunning() { return isRunning_; }
	std::vector<int> GetMouseCoordinates() { return mouse_->GetCoordinates(); }
	MouseButton GetMouseButton() { return mouse_->GetButtonClicked(); }
	std::vector<KeyCharacter> GetPressedKeys() { return keyboard_->GetPressedKeys(); }
	bool GetStatusOfKey(KeyCharacter key) { return keyboard_->GetStatusOfKey(key); }
private:
	SDL_Event eventSDL_;
	bool isRunning_{true};
	bool updateMouse_{false};
	std::unique_ptr<Keyboard> keyboard_;
	std::unique_ptr<Mouse> mouse_;
};

#endif
