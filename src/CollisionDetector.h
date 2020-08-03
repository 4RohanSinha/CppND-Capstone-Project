#ifndef COLLISION_DETECTOR_H
#define COLLISION_DETECTOR_H

#include <vector>
#include <memory>
#include "Node.h"
#include <functional>

class CollisionDetector {
public:
	bool isEnabled{true};
	CollisionDetector() {}
	CollisionDetector(std::shared_ptr<Node> firstNode, std::shared_ptr<Node> secondNode): isEnabled(true), nodeOne(firstNode), nodeTwo(secondNode) {}

	template <typename T>
	CollisionDetector(std::shared_ptr<Node> firstNode, std::shared_ptr<Node> secondNode, T handlerFunction): isEnabled(true), nodeOne(firstNode), nodeTwo(secondNode), handlerFunction_(handlerFunction) {}

	//void ForbidObjectsFromIntersecting();
	operator bool() { return isColliding_ && isEnabled; }
	void operator()() { CheckForCollisions(); }
	bool FirstCollisionIsHappening() { return initCollide_ && isEnabled; }
	void CheckForCollisions();
	bool HasHandlerFunction() { return static_cast<bool>(handlerFunction_); }
	
private:
	std::shared_ptr<Node> nodeOne = nullptr;
	std::shared_ptr<Node> nodeTwo = nullptr;
	bool isColliding_ = false;
	bool initCollide_ = false;
	//usage of std::function from https://en.cppreference.com/w/cpp/utility/functional/function
	std::function<void()> handlerFunction_;

};

#endif
