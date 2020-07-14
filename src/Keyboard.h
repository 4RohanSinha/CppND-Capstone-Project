#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "Event.h"
#include <SDL2/SDL.h>
#include <vector>

class Keyboard {
public:
	void GetKeyboardInput();
private:
	std::unordered_map<KeyCharacter, bool> keys_;

};

#endif
