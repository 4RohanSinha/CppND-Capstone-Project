#ifndef COLLISION_DETECTOR
#define COLLISION_DETECTOR

#include <vector>
#include <memory>
#include <thread>
#include <mutex>
#include "Node.h"
#include "Event.h"

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
	std::shared_ptr<std::vector<std::shared_ptr<Node>>> nodes_ = nullptr;

};

#endif
