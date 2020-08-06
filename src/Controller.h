#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <SDL2/SDL.h>
#include <memory>
#include <initializer_list>
#include <functional>
#include "Node.h"
#include "CollisionDetector.h"
#include "EventHandler.h"
#include "Input.h"

class Controller {
public:
	void Update();
	
	//functions overloaded to give the option of providing one or multiple keys
	//handler functions should be passed in for the event handlers to execute once the event that they are listening for has occurred
	void HandleKeyPressFor(KeyCharacter key, std::function<void()> handlerFunction);

	void HandleKeyPressFor(std::initializer_list<KeyCharacter> keys, std::function<void()> handlerFunction);
	
	void HandleKeyUpFor(KeyCharacter key, std::function<void()> handlerFunction);
	
	void HandleKeyUpFor(std::initializer_list<KeyCharacter> key, std::function<void()> handlerFunction);

	//this function returns if the program is still running - used in the game loop
	bool IsRunning() { return inputMonitor_.IsRunning(); }

private:
	//EventHandler is an abstract class
	//cannot store a vector of regular objects, but unique pointers to an abstract class can be stored
	std::vector<std::unique_ptr<EventHandler>> eventHandlers_;
	
	//input monitor - contains Mouse and Keyboard classes, which contain mouse and keyboard info from SDL libraries
	Input inputMonitor_;

	//private member function to update event handlers in vector above
	void ListenUpdate();
};

#endif
