#ifndef COLLISION_DETECTOR_H
#define COLLISION_DETECTOR_H

#include <vector>
#include <memory>
#include "Node.h"
#include <functional>

class CollisionDetector {
public:
	template <typename T>
	CollisionDetector(std::shared_ptr<Node> firstNode, std::shared_ptr<Node> secondNode, T handlerFunction): nodeOne(firstNode), nodeTwo(secondNode), handlerFunction_(handlerFunction) {}

	void CheckForCollisions();
	
private:
	std::shared_ptr<Node> nodeOne = nullptr;
	std::shared_ptr<Node> nodeTwo = nullptr;
	//usage of std::function from https://en.cppreference.com/w/cpp/utility/functional/function
	std::function<void()> handlerFunction_;

};

#endif
