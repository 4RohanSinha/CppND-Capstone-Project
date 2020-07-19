#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <SDL2/SDL.h>
#include <memory>
#include "Node.h"
#include "Event.h"
#include "CollisionDetector.h"
#include "GameEventListener.h"
#include "Input.h"

class Controller {
public:
	Controller(std::shared_ptr<std::vector<std::shared_ptr<Node>>> nodes);

	void Update();
	
	//these template functions can only be defined within the header files themselves
	template <typename T>
	void HandleCollisionsBetween(std::shared_ptr<Node> nodeOne, std::shared_ptr<Node> nodeTwo, T handlerFunction) {
		collideDetect.push_back(std::make_shared<CollisionDetector>(nodeOne, nodeTwo, handlerFunction));
	}

	template <typename T>
	void HandleKeyPressFor(KeyCharacter key, T handlerFunction) {
		Event e = Event(EventType::kDownKey);
		e.SetKeyCharacter(key);
		inputListeners.push_back(std::make_shared<GameEventListener>(e, handlerFunction, inputMonitor_));
	}

	template <typename T>
	void HandleKeyUpFor(KeyCharacter key, T handlerFunction) {
		Event e = Event(EventType::kUpKey);
		e.SetKeyCharacter(key);
		inputListeners.push_back(std::make_shared<GameEventListener>(e, handlerFunction, inputMonitor_));
	}

	bool IsRunning() { return inputMonitor_->IsRunning(); }

private:
	//See if unique_ptr can be used or if pointers can be removed altogether
	std::vector<std::shared_ptr<CollisionDetector>> collideDetect;
	std::vector<std::shared_ptr<GameEventListener>> inputListeners;
	std::shared_ptr<std::vector<std::shared_ptr<Node>>> nodes_ = nullptr;
	std::shared_ptr<Input> inputMonitor_ = std::make_shared<Input>();
	void CollisionUpdate();
	void ListenUpdate();
	std::vector<std::future<void>> updateThreads_;
};

#endif
