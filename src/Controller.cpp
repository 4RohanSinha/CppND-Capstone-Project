#include "Controller.h"

Controller::Controller(std::shared_ptr<std::vector<std::shared_ptr<Node>>> nodes) {
	nodes_ = nodes;
	collideDetect = std::make_unique<CollisionDetector>(nodes_);
}
