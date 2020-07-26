#include "NodeGroup.h"

void NodeGroup::AddNode(std::shared_ptr<Node> node) {
	nodes_.push_back(node);
}

void NodeGroup::DeleteNode(int ind) {
	nodes_.erase(nodes_.begin() + (ind - 1));
}

std::shared_ptr<Node> NodeGroup::operator[](int ind) {
	return nodes_[ind];
}

int NodeGroup::size() {
	return nodes_.size();
}
