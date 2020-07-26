#include "Node.h"
#include <iostream>

Node::Node(float x, float y): x(x), y(y), width_(0), height_(0) {}

Node::Node(float x, float y, int width, int height): x(x), y(y) {
	if (CheckLength(width) && CheckLength(height)) {
		width_ = width;
		height_ = height;
	} else {
		throw std::invalid_argument("Error: invalid length for width and height.");
	}
}

void Node::Move(float newX, float newY, float speed) {
	animations_.push_back(std::make_shared<Animation::MoveAnimation>(newX, newY, speed));
}

void Node::Move(float direction, float speed) {
	animations_.push_back(std::make_shared<Animation::MoveAnimation>(direction, speed));
}

void Node::ChangeSize(int width, int height) {
}

void Node::ClearAnimations() {
	std::deque<std::shared_ptr<Animation::Animation>> empty;
	std::swap(animations_, empty);
}

bool Node::CheckLength(float len) {
	if (len > 0)
		return true;
	return false;
}
