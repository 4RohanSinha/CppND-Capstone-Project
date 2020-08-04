#ifndef NG_COLLISION_DETECTOR_H
#define NG_COLLISION_DETECTOR_H

#include "CollisionDetector.h"
#include "NodeGroup.h"

//relies on the CollisionDetector class
//uses a vector of CollisionDetector objects to check for collisions between/within NodeGroups as well
class NGCollisionDetector {
public:
	bool isEnabled{true};
	NGCollisionDetector() {}
	NGCollisionDetector(std::shared_ptr<Node> nodeA, std::shared_ptr<Node> node_b);
	NGCollisionDetector(std::shared_ptr<Node> nodeA, std::shared_ptr<Node> node_b, std::function<void()> handler);
	NGCollisionDetector(NodeGroup& group);
	NGCollisionDetector(NodeGroup& group, std::function<void()> handler);
	NGCollisionDetector(NodeGroup& groupA, NodeGroup& group_b);
	NGCollisionDetector(NodeGroup& groupA, NodeGroup& group_b, std::function<void()> handler);
	NGCollisionDetector(NodeGroup& groupA, std::shared_ptr<Node> node);
	NGCollisionDetector(NodeGroup& groupA, std::shared_ptr<Node> node, std::function<void()> handler);
	operator bool();
	void operator()() { CheckForCollisions(); }
	bool FirstCollisionIsHappening();
	void CheckForCollisions();
	bool HasHandlerFunction();
	
private:
	std::vector<CollisionDetector> collisions_;	
};

#endif
