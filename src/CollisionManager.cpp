#include "CollisionManager.h"

void CollisionManager::Update() {
	for (auto it = collisions_.begin(); it != collisions_.end(); it++) {
		auto curCollisionHandler = it->second;
		curCollisionHandler();
	}
}

void CollisionManager::DetectCollisionsBetweenGroupAndNode(NodeGroup& ng, std::shared_ptr<Node> node) {

}

void CollisionManager::DetectCollisionsBetweenGroups(NodeGroup& groupA, NodeGroup& group_b) {

}
