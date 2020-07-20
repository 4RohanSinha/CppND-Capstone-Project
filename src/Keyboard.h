#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <SDL2/SDL.h>
#include <unordered_map>
#include <vector>

enum KeyCharacter {
        keyA, keyB, keyC, keyD, keyE, keyF, keyG, keyH, keyI, keyJ, keyK, keyL, keyM,
        keyN, keyO, keyP, keyQ, keyR, keyS, keyT, keyU, keyV, keyW, keyX, keyY, keyZ,
        keyShift, keyCtrl, keyLeftArr, keyRightArr, keyUpArr, keyDownArr,
        key0, key1, key2, key3, key4, key5, key6, key7, key8, key9, keyReturn, keyTab, keySlash, keyComma, keyPeriod, kNone, kAll
};

enum class KeyStatus {
	keyPressed,
	keyReleased,
	keyNone
};

class Keyboard {
public:
	Keyboard();
	void Update();
	KeyStatus GetStatusOfKey(KeyCharacter key);
	static Uint8 ConvertToSDL(KeyCharacter key);
	std::vector<KeyCharacter> GetPressedKeys();
	std::vector<KeyCharacter> GetReleasedKeys();
private:
	
	//information for std::hash from https://en.cppreference.com/w/cpp/utility/hash
	//more info from https://www.reddit.com/r/cpp_questions/comments/3ayy9d/hash_for_enum_class/
	static const std::unordered_map<KeyCharacter, Uint8, std::hash<std::underlying_type<KeyCharacter>::type>> keys_;
	std::unordered_map<KeyCharacter, KeyStatus, std::hash<std::underlying_type<KeyCharacter>::type>> keyStatuses_;
	const unsigned char* keyStates_;
	void UpdateKeyStatus();
	std::vector<KeyCharacter> LookForKeyStatus(KeyStatus status);

};

#endif
