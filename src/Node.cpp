#include "Node.h"
#include <iostream>

Node::Node(float x, float y): x_(x), y_(y), width_(0), height_(0) {
	rendererSetDimensions_ = true;
}

Node::Node(float x, float y, int width, int height): x_(x), y_(y) {
	if (CheckLength(width) && CheckLength(height)) {
		width_ = width;
		height_ = height;
	} else {
		throw std::invalid_argument("Error: invalid length for width and height.");
	}
}
//Rule of Five


//Node destructor
Node::~Node() {
}
/*
//TODO: Complete the other methods for Rule of Five
//Node copy constructor
Node::Node(Node const &source) {}

//Node copy assignment operator
Node& Node::operator=(Node const &source) {}

//Node move constructor
Node::Node(Node &&source) {}

//Node move assignment operator
Node& Node::operator=(Node &&source) {}
*/

void Node::AnimationChange() {
	if (animationFunction_)
		animationFunction_();
}

void Node::ConstructRectangle() {
	if (rect_ != NULL && rect_ != nullptr)
		rect_.reset();
	rect_ = std::make_shared<SDL_Rect>();
	rect_->x = x_;
	rect_->y = y_;
	rect_->w = width_;
	rect_->h = height_;
}

void Node::Move(float newX, float newY, float speed) {
	animations_.push_back(std::make_shared<Animation::MoveAnimation>(newX, newY, speed));
}

void Node::Move(float direction, float speed) {
	animations_.push_back(std::make_shared<Animation::MoveAnimation>(direction, speed));
}

void Node::ChangeSize(int width, int height) {
}

void Node::Clear() {
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
