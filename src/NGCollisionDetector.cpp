#include "NGCollisionDetector.h"

NGCollisionDetector::NGCollisionDetector(std::shared_ptr<Node> nodeA, std::shared_ptr<Node> node_b) {
	collisions_.push_back(CollisionDetector(nodeA, node_b));
}

NGCollisionDetector::NGCollisionDetector(std::shared_ptr<Node> nodeA, std::shared_ptr<Node> node_b, std::function<void()> handler) {
	collisions_.push_back(CollisionDetector(nodeA, node_b, handler));
}

NGCollisionDetector::NGCollisionDetector(NodeGroup& group) {
	for (int i = 0; i < group.size(); i++) {
		for (int j = i+1; j < group.size(); j++) {
			collisions_.push_back(CollisionDetector(group[i], group[j]));
		}
	}
}

NGCollisionDetector::NGCollisionDetector(NodeGroup& group, std::function<void()> handler) {
	for (int i = 0; i < group.size(); i++) {
		for (int j = i+1; j < group.size(); j++) {
			collisions_.push_back(CollisionDetector(group[i], group[j], handler));
		}
	}
}

NGCollisionDetector::NGCollisionDetector(NodeGroup& groupA, NodeGroup& group_b) {
	for (int i = 0; i < groupA.size(); i++) {
		for (int j = 0; j < group_b.size(); j++) {
			collisions_.push_back(CollisionDetector(groupA[i], group_b[j]));
		}
	}
}

NGCollisionDetector::NGCollisionDetector(NodeGroup& groupA, NodeGroup& group_b, std::function<void()> handler) {
	for (int i = 0; i < groupA.size(); i++) {
		for (int j = 0; j < group_b.size(); j++) {
			collisions_.push_back(CollisionDetector(groupA[i], group_b[j], handler));
		}
	}
}

NGCollisionDetector::NGCollisionDetector(NodeGroup& groupA, std::shared_ptr<Node> node) {
	for (int i = 0; i < groupA.size(); i++) {
		collisions_.push_back(CollisionDetector(groupA[i], node));
	}
}

NGCollisionDetector::NGCollisionDetector(NodeGroup& groupA, std::shared_ptr<Node> node, std::function<void()> handler) {
	for (int i = 0; i < groupA.size(); i++) {
		collisions_.push_back(CollisionDetector(groupA[i], node, handler));
	}
}

NGCollisionDetector::operator bool() {
	bool res = false;
	for (auto& i: collisions_) {
		res = (res || (static_cast<bool>(i)));
	}
	return res && isEnabled;
}

bool NGCollisionDetector::FirstCollisionIsHappening() {
	bool res = false;
	for (auto& i: collisions_)
		res = (res || i.FirstCollisionIsHappening());
	return res && isEnabled;
}

void NGCollisionDetector::CheckForCollisions() {
	//iterate through each collision object
	//use reference to avoid making a copy and change the object directly, not a copy
	//the CollisionDetector class has overloaded the () operator to check for collisions
	for (auto& i: collisions_)
		i();
}

bool NGCollisionDetector::HasHandlerFunction() {
	//all constructors require that either all collision detectors have handlers or none of them have handlers
	//therefore, checking the first one is enough
	return collisions_[0].HasHandlerFunction(); 
}


