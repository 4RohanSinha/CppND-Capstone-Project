#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <SDL2/SDL.h>
#include <memory>
#include <initializer_list>
#include "Node.h"
#include "Event.h"
#include "CollisionDetector.h"
#include "GameEventListener.h"
#include "EventHandler.h"
#include "Input.h"

class Controller {
public:
	Controller() {}

	void Update();
	
	//these template functions can only be defined within the header files themselves
	template <typename T>
	void HandleCollisionsBetween(std::shared_ptr<Node> nodeOne, std::shared_ptr<Node> nodeTwo, T handlerFunction) {
		collideDetect.emplace_back(std::make_unique<CollisionDetector>(nodeOne, nodeTwo, handlerFunction));
	}

	template <typename T>
	void HandleKeyPressFor(KeyCharacter key, T handlerFunction) {
		std::set<KeyCharacter> keyInput{key};
		eventHandlers_.emplace_back(std::make_unique<KeyDownEventHandler>(inputMonitor_, handlerFunction, keyInput));
	}

	template <typename T>
	void HandleKeyPressFor(std::initializer_list<KeyCharacter> keys, T handlerFunction) {
		std::set<KeyCharacter> keyInput = keys;
		eventHandlers_.emplace_back(std::make_unique<KeyDownEventHandler>(inputMonitor_, handlerFunction, keyInput));
	}

	template <typename T>
	void HandleKeyUpFor(KeyCharacter key, T handlerFunction) {
		std::set<KeyCharacter> keyInput{key};
		eventHandlers_.emplace_back(std::make_unique<KeyUpEventHandler>(inputMonitor_, handlerFunction, keyInput));
		
	}

	template <typename T>
	void HandleKeyUpFor(std::initializer_list<KeyCharacter> keys, T handlerFunction) {
		std::set<KeyCharacter> keyInput = keys;
		eventHandlers_.emplace_back(std::make_unique<KeyUpEventHandler>(inputMonitor_, handlerFunction, keyInput));
	}

	bool IsRunning() { return inputMonitor_->IsRunning(); }

private:
	//See if unique_ptr can be used or if pointers can be removed altogether
	std::vector<std::unique_ptr<CollisionDetector>> collideDetect;
	std::vector<std::unique_ptr<EventHandler>> eventHandlers_;
	std::shared_ptr<Input> inputMonitor_ = std::make_shared<Input>();
	void CollisionUpdate();
	void ListenUpdate();
	std::vector<std::future<void>> updateThreads_;
};

#endif
