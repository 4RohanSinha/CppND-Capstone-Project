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

//TODO: allow for simultaneous events to be handled - e.g. click and key press at the same time
class Controller {
public:
	Controller() {}

	void Update();
	
	//these template functions can only be defined within the header files themselves
	template <typename T>
	void HandleCollisionsBetween(std::shared_ptr<Node> nodeOne, std::shared_ptr<Node> nodeTwo, T handlerFunction) {
		collideDetect_.emplace_back(CollisionDetector(nodeOne, nodeTwo, handlerFunction));
	}

	template <typename T>
	void HandleKeyPressFor(KeyCharacter key, T handlerFunction) {
		std::set<KeyCharacter> keyInput{key};
		eventHandlers_.emplace_back(std::make_unique<KeyDownEventHandler>(handlerFunction, keyInput));
	}

	template <typename T>
	void HandleKeyPressFor(std::initializer_list<KeyCharacter> keys, T handlerFunction) {
		std::set<KeyCharacter> keyInput = keys;
		eventHandlers_.emplace_back(std::make_unique<KeyDownEventHandler>(handlerFunction, keyInput));
	}

	template <typename T>
	void HandleKeyUpFor(KeyCharacter key, T handlerFunction) {
		std::set<KeyCharacter> keyInput{key};
		eventHandlers_.emplace_back(std::make_unique<KeyUpEventHandler>(handlerFunction, keyInput));
	}

	template <typename T>
	void HandleKeyUpFor(std::initializer_list<KeyCharacter> keys, T handlerFunction) {
		std::set<KeyCharacter> keyInput = keys;
		eventHandlers_.emplace_back(std::make_unique<KeyUpEventHandler>(handlerFunction, keyInput));
	}


	bool IsRunning() { return inputMonitor_.IsRunning(); }

private:
	std::vector<CollisionDetector> collideDetect_;
	//EventHandler is an abstract class
	//cannot store a vector of regular objects, but unique pointers to an abstract class can be stored
	std::vector<std::unique_ptr<EventHandler>> eventHandlers_;
	Input inputMonitor_;
	void CollisionUpdate();
	void ListenUpdate();
};

#endif
