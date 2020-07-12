#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <SDL2/SDL.h>
#include <memory>
#include "Node.h"
#include "Event.h"
#include "CollisionDetector.h"
#include "GameEventListener.h"

class Controller {
public:
	Controller(std::shared_ptr<std::vector<std::shared_ptr<Node>>> nodes);
	//these template functions can only be defined within the header files themselves
	template <typename T>
	void HandleCollisionsBetween(std::shared_ptr<Node> nodeOne, std::shared_ptr<Node> nodeTwo, T handlerFunction) {
		handlerFunction();
	}

	template <typename T>
	void HandleKeyPressFor(KeyCharacter key, T handlerFunction) {
		handlerFunction();
	}
private:
	std::unique_ptr<CollisionDetector> collideDetect = nullptr;
	std::unique_ptr<GameEventListener> gameEventController = nullptr;
	std::shared_ptr<std::vector<std::shared_ptr<Node>>> nodes_ = nullptr;
};

#endif
