#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "Event.h"
#include <SDL2/SDL.h>
#include <vector>

class Keyboard {
public:
	Keyboard();
	void Update();
	bool GetStatusOfKey(KeyCharacter key);
	static Uint8 ConvertToSDL(KeyCharacter key);
	std::vector<KeyCharacter> GetPressedKeys();
private:
	
	//information for std::hash from https://en.cppreference.com/w/cpp/utility/hash
	//more info from https://www.reddit.com/r/cpp_questions/comments/3ayy9d/hash_for_enum_class/
	static const std::unordered_map<KeyCharacter, Uint8, std::hash<std::underlying_type<KeyCharacter>::type>> keys_;
	const unsigned char* keyStates_;

};

#endif
