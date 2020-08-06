#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "SDL2_headers.h"
#include <unordered_map>
#include <vector>
#include <set>


//enum containing all the keys that this class will recognize
//note that this may not include all the keys, but these are the main keys that will be needed for the project
enum class KeyCharacter {
        keyA, keyB, keyC, keyD, keyE, keyF, keyG, keyH, keyI, keyJ, keyK, keyL, keyM,
        keyN, keyO, keyP, keyQ, keyR, keyS, keyT, keyU, keyV, keyW, keyX, keyY, keyZ,
        keyShift, keyCtrl, keyLeftArr, keyRightArr, keyUpArr, keyDownArr,
        key0, key1, key2, key3, key4, key5, key6, key7, key8, key9, keyEnter, keyTab, 
	keySlash, keyBackslash, keyComma, keyPeriod, keyBackspace, keyEquals, keyEsc, 
	keyLeftCtrl, keyRightCtrl, keyLeftShift, keyRightShift, keySemicolon, kNone, kAll
};

//an enum of a key status - a key can be pressed, just released, or inactive
//the keyReleased value is used in KeyUp events
enum class KeyStatus {
	keyPressed,
	keyReleased,
	keyNone
};

//part of using enum class KeyCharacter as key in unordered_map
//solution from https://stackoverflow.com/questions/18837857/cant-use-enum-class-as-unordered-map-key
struct HashKey {
	std::size_t operator()(KeyCharacter key) const { return static_cast<std::size_t>(key); }
};

//this class is responsible for managing the keyboard
class Keyboard {
public:
	//constructor creates all the keys in the unordered_map mapping characters to statuses and assigns the value KeyStatus::kNone to all of them.
	Keyboard();

	//this method updates the status of the keys
	//it is called by the Input class, so it is not needed by the user
	void Update();

	//returns the KeyStatus at the KeyCharacter key in the unordered_map
	KeyStatus GetStatusOfKey(KeyCharacter key);

	//returns a vector containing all the currently pressed keys
	std::vector<KeyCharacter> GetPressedKeys();

	//returns a vector containing all the keys that were just released
	std::vector<KeyCharacter> GetReleasedKeys();
private:
	
	//information for using enum class as unordered map key: https://stackoverflow.com/questions/18837857/cant-use-enum-class-as-unordered-map-key
	//this static unordered_map maps the enum above to the SDL Uint8 values
	static std::unordered_map<KeyCharacter, Uint8, HashKey> keys_;
	//this unordered_map is responsible for mapping each key to the status
	std::unordered_map<KeyCharacter, KeyStatus, HashKey> keyStatuses_;
	
	//this member variable is an array containing the states of the keys
	//it does not need to be freed
	//see https://stackoverflow.com/questions/26779561/keypress-using-in-sdl2-correctly
	//it cannot be used for the keyboard class alone because it does not contain information about keys being released
	const Uint8* keyStates_;
	
	//this member function is private. it is called by the Update() method
	void UpdateKeyStatus();
	
	//this private member function is used by the UpdateKeyStatus and other member functions to convert KeyCharacter objects back to SDL's format
	//this method looks for a particular key status within keyStauses_
	//it is called by GetPressedKeys & GetReleasedKeys because they perform the same function, but look for different key statuses within the unordered_map

	std::vector<KeyCharacter> LookForKeyStatus(KeyStatus status);

};

#endif
