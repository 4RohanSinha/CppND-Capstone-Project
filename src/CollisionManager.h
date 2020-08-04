#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H

#include <string>
#include <unordered_map>
#include "NodeGroup.h"
#include "CollisionDetector.h"
#include "NGCollisionDetector.h"

class CollisionManager {
public:
	void DetectCollisionsBetween(std::shared_ptr<Node> nodeA, std::shared_ptr<Node> node_b, std::string identifier);

	void DetectCollisionsBetween(std::shared_ptr<Node> nodeA, std::shared_ptr<Node> node_b, std::string identifier, std::function<void()> handlerFunction);

	void DetectCollisionsBetweenGroupAndNode(NodeGroup& ng, std::shared_ptr<Node> node, std::string identifier);

	void DetectCollisionsBetweenGroupAndNode(NodeGroup& ng, std::shared_ptr<Node> node, std::string identifier, std::function<void()> handler);

	void DetectCollisionsBetweenGroups(NodeGroup& groupA, NodeGroup& group_b, std::string identifier);
	
	void DetectCollisionsBetweenGroups(NodeGroup& groupA, NodeGroup& group_b, std::string identifier, std::function<void()> handler);


	NGCollisionDetector& operator[](std::string identifier) { return collisions_[identifier]; }

	bool FirstCollisionIsHappening(std::string identifier);

	void DeleteCollisionAt(std::string identifier) { collisions_.erase(identifier); }

	void DisableCollision(std::string identifier) { collisions_[identifier].isEnabled = false; }

	void EnableCollision(std::string identifier) { collisions_[identifier].isEnabled = true; }

	void Update();

private:
	std::unordered_map<std::string, NGCollisionDetector> collisions_;
};

#endif
