#include "CollisionManager.h"

void CollisionManager::Update() {
	for (auto it = collisions_.begin(); it != collisions_.end(); it++) {
		(it->second)();
	}
}

void CollisionManager::DetectCollisionsBetween(std::shared_ptr<Node> nodeA, std::shared_ptr<Node> node_b, std::string identifier) {
	collisions_[identifier] = NGCollisionDetector(nodeA, node_b);
}

void CollisionManager::DetectCollisionsBetween(std::shared_ptr<Node> nodeA, std::shared_ptr<Node> node_b, std::string identifier, std::function<void()> handlerFunction) {
	collisions_[identifier] = NGCollisionDetector(nodeA, node_b, handlerFunction);
}

void CollisionManager::DetectCollisionsWithin(NodeGroup& ng, std::string identifier) {
	collisions_[identifier] = NGCollisionDetector(ng);
}

void CollisionManager::DetectCollisionsWithin(NodeGroup& ng, std::string identifier, std::function<void()> handlerFunction) {
	collisions_[identifier] = NGCollisionDetector(ng, handlerFunction);
}

void CollisionManager::DetectCollisionsBetweenGroupAndNode(NodeGroup& ng, std::shared_ptr<Node> node, std::string identifier) {
	collisions_[identifier] = NGCollisionDetector(ng, node);
}

void CollisionManager::DetectCollisionsBetweenGroupAndNode(NodeGroup& ng, std::shared_ptr<Node> node, std::string identifier, std::function<void()> handler) {
	collisions_[identifier] = NGCollisionDetector(ng, node, handler);
}

void CollisionManager::DetectCollisionsBetweenGroups(NodeGroup& groupA, NodeGroup& group_b, std::string identifier) {
	collisions_[identifier] = NGCollisionDetector(groupA, group_b);
}

void CollisionManager::DetectCollisionsBetweenGroups(NodeGroup& groupA, NodeGroup& group_b, std::string identifier, std::function<void()> handler) {
	collisions_[identifier] = NGCollisionDetector(groupA, group_b, handler);
}

bool CollisionManager::FirstCollisionIsHappening(std::string identifier) {
	return collisions_[identifier].FirstCollisionIsHappening();
}
