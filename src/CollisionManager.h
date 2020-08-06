#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H

#include <string>
#include <unordered_map>
#include "NodeGroup.h"
#include "CollisionDetector.h"
#include "NGCollisionDetector.h"

class CollisionManager {
public:
//Note: all collision detectors have a string identifier to reference them later on and get their status

	//adds collision detector to unordered_map between two nodes
	void DetectCollisionsBetween(std::shared_ptr<Node> nodeA, std::shared_ptr<Node> node_b, std::string identifier);

	//passes in handler function as well
	//usage/research of std::function from https://en.cppreference.com/w/cpp/utility/functional/function

	void DetectCollisionsBetween(std::shared_ptr<Node> nodeA, std::shared_ptr<Node> node_b, std::string identifier, std::function<void()> handlerFunction);

	//checks for collisions within the nodegroup and adds them to the unordered map
	void DetectCollisionsWithin(NodeGroup& ng, std::string identifier);

	//same as above but with handler function
	void DetectCollisionsWithin(NodeGroup& ng, std::string identifier, std::function<void()> handlerFunction);

	//adds collision detector between group and node
	void DetectCollisionsBetweenGroupAndNode(NodeGroup& ng, std::shared_ptr<Node> node, std::string identifier);

	//same as above but with handler function
	void DetectCollisionsBetweenGroupAndNode(NodeGroup& ng, std::shared_ptr<Node> node, std::string identifier, std::function<void()> handler);

	//adds collision detector between two groups
	void DetectCollisionsBetweenGroups(NodeGroup& groupA, NodeGroup& group_b, std::string identifier);
	
	//same as above but with handler function
	void DetectCollisionsBetweenGroups(NodeGroup& groupA, NodeGroup& group_b, std::string identifier, std::function<void()> handler);


	//overloads bracket operator to return status of collision given particular identifier
	NGCollisionDetector& operator[](std::string identifier) { return collisions_[identifier]; }

	//check if the two objects have completed their initial encounter
	bool FirstCollisionIsHappening(std::string identifier);

	//delete collision director
	void DeleteCollisionAt(std::string identifier) { collisions_.erase(identifier); }

	//temporarily disable collision (but could be enabled again)
	void DisableCollision(std::string identifier) { collisions_[identifier].isEnabled = false; }

	//enable collision
	void EnableCollision(std::string identifier) { collisions_[identifier].isEnabled = true; }

	//check for collisions in vector
	void Update();

private:
	std::unordered_map<std::string, NGCollisionDetector> collisions_;
};

#endif
