#ifndef COLLISION_DETECTOR_H
#define COLLISION_DETECTOR_H

#include <vector>
#include <memory>
#include "Node.h"
#include <functional>

class CollisionDetector {
public:
	bool isEnabled{true}; //allows collision detector to be enabled or disabled
	CollisionDetector() {} //this constructor is necessary for the CollisionManager
	//the two constructors below are nearly identical, except that the first one does not need a handler function (and none will be called once the two objects first collide), while the second one does
	//the constructors store non-owning raw pointers to the Nodes
	CollisionDetector(std::shared_ptr<Node> firstNode, std::shared_ptr<Node> secondNode): isEnabled(true), nodeOne(firstNode.get()), nodeTwo(secondNode.get()) {}

	template <typename T>
	CollisionDetector(std::shared_ptr<Node> firstNode, std::shared_ptr<Node> secondNode, T handlerFunction): isEnabled(true), nodeOne(firstNode.get()), nodeTwo(secondNode.get()), handlerFunction_(handlerFunction) {}

	bool IsColliding() { return isColliding_ && isEnabled; }
	operator bool() { return isColliding_ && isEnabled; }
	void operator()() { CheckForCollisions(); }
	bool FirstCollisionIsHappening() { return initCollide_ && isEnabled; }
	void CheckForCollisions();
	bool HasHandlerFunction() { return static_cast<bool>(handlerFunction_); }
	
private:
	//non-owning references to Nodes
	//the CollisionDetector object will check for collisions between these two Node objects
	//this object is not responsible for allocation and deallocation
	//if one of the Node objects are nullptr, then the CheckForCollisions method simply returns
	Node* nodeOne = nullptr;
	Node* nodeTwo = nullptr;
	//check if the two objects are intersecting
	bool isColliding_ = false;
	//check if the two objects have completed their initial encounter (e.g. if a sound should be played every time the two Nodes collide, this value can prevent it from repeating over and over again
	bool initCollide_ = false;
	//usage of std::function from https://en.cppreference.com/w/cpp/utility/functional/function
	//this is the optional handler function
	//The CollisionDetector object calls this lambda function once the two nodes have completed their initial collision (initCollide_ is true)
	std::function<void()> handlerFunction_;

};

#endif
