#include "Node.h"
#include "Physics.h"
#include <iostream>

Node::Node() {
	physics = std::make_unique<Physics>(this);
}

Node::Node(float x, float y): x(x), y(y), width_(0), height_(0) {
	physics = std::make_unique<Physics>(this);
}

Node::Node(float x, float y, int width, int height): x(x), y(y) {
	physics = std::make_unique<Physics>(this);
	if (CheckLength(width) && CheckLength(height)) {
		width_ = width;
		height_ = height;
	} else {
		throw std::invalid_argument("Error: invalid length for width and height.");
	}
}

bool Node::CheckLength(float len) {
	if (len > 0)
		return true;
	return false;
}
