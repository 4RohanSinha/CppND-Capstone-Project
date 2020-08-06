#include "Controller.h"
#include <iostream>

//private member function - update event handlers by having them listen to the input monitor
//the input monitor is passed by reference (see EventHandler.h)
void Controller::ListenUpdate() {
	for (auto& i: eventHandlers_)
		i->Listen(inputMonitor_);
}

//update the input monitor, which contains stack objects of classes Keyboard and Mouse
//then update the event handlers by calling the method above
void Controller::Update() {
	inputMonitor_.Update();
	ListenUpdate();
}

//method to handle key press for a given key
//a lambda function (std::function) also must be passed in that the event handler will call
void Controller::HandleKeyPressFor(KeyCharacter key, std::function<void()> handlerFunction) {
	//the event handler requires a vector of keys to listen to
	//there is only one key in this case
	std::vector<KeyCharacter> keyInput{key};
	//a unique_ptr is added to the vector
	//note that unique_ptrs have to be used because EventHandler is an abstract class
	//raw pointers are avoided to remove the need for explicit allocs and deallocs
	eventHandlers_.emplace_back(std::make_unique<KeyDownEventHandler>(handlerFunction, keyInput));
}

//allow the option to listen to multiple keys
void Controller::HandleKeyPressFor(std::initializer_list<KeyCharacter> keys, std::function<void()> handlerFunction) {
	//the event handler requires a vector of keys to listen to
	std::vector<KeyCharacter> keyInput = keys;
	//a unique_ptr is added to the vector
	//note that unique_ptrs have to be used because EventHandler is an abstract class
	//raw pointers are avoided to remove the need for explicit allocs and deallocs
	eventHandlers_.emplace_back(std::make_unique<KeyDownEventHandler>(handlerFunction, keyInput));
}

//the following methods are the same situation as the last two, except they are for when the key is released
void Controller::HandleKeyUpFor(KeyCharacter key, std::function<void()> handlerFunction) {
	std::vector<KeyCharacter> keyInput{key};
	eventHandlers_.emplace_back(std::make_unique<KeyUpEventHandler>(handlerFunction, keyInput));
}

void Controller::HandleKeyUpFor(std::initializer_list<KeyCharacter> keys, std::function<void()> handlerFunction) {
	std::vector<KeyCharacter> keyInput = keys;
	eventHandlers_.emplace_back(std::make_unique<KeyUpEventHandler>(handlerFunction, keyInput));
}

