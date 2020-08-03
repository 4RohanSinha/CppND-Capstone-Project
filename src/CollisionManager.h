#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H

#include <string>
#include <unordered_map>
#include "NodeGroup.h"
#include "CollisionDetector.h"

class CollisionManager {
public:
	void DetectCollisionsBetween(std::shared_ptr<Node> nodeA, std::shared_ptr<Node> node_b, std::string identifier) { collisions_[identifier] = CollisionDetector(nodeA, node_b); }

	void DetectCollisionsBetweenGroupAndNode(NodeGroup& ng, std::shared_ptr<Node> node);

	void DetectCollisionsBetweenGroups(NodeGroup& groupA, NodeGroup& group_b);

	template <typename T>
	void DetectCollisionsBetween(std::shared_ptr<Node> nodeA, std::shared_ptr<Node> node_b, std::string identifier, T handlerFunction) { collisions_[identifier] = CollisionDetector(nodeA, node_b, handlerFunction); }

	CollisionDetector operator[](std::string identifier) { return collisions_[identifier];  }

	bool FirstCollisionIsHappening(std::string identifier) { return collisions_[identifier].FirstCollisionIsHappening(); }

	void DeleteCollisionAt(std::string identifier) { collisions_.erase(identifier); }

	void DisableCollision(std::string identifier) { collisions_[identifier].isEnabled = false; }

	void EnableCollision(std::string identifier) { collisions_[identifier].isEnabled = true; }

	void Update();

private:
	std::unordered_map<std::string, CollisionDetector> collisions_;
};

#endif
