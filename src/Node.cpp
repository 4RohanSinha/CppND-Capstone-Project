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

void Node::ConstructRectangle() {
	if (rect_ != NULL && rect_ != nullptr)
		rect_.reset();
	rect_ = std::make_shared<SDL_Rect>();
	rect_->x = x_;
	rect_->y = y_;
	rect_->w = width_;
	rect_->h = height_;
}

void Node::CreateTexture(std::shared_ptr<SDL_Renderer> renderer) {
	if (renderer == nullptr || renderer == NULL)
		throw std::invalid_argument("Fatal Error: Node::CreateTexture(): renderer is a nullptr");
	
	CreateSurface();
	
	texture_ = GetSharedPtr(SDL_CreateTextureFromSurface(renderer.get(), surface_.get()));
}

void Node::Move(float newX, float newY) {
	animations_.push(std::make_shared<MoveAnimation>(newX, newY));
}

void Node::ChangeSize(int width, int height) {
}

void Node::Clear() {
}

bool Node::CheckLength(float len) {
	if (len > 0)
		return true;
	return false;
}
