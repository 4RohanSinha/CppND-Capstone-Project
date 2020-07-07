#include "Node.h"
#include <iostream>


Node::Node(float x, float y, float width, float height): x_(x), y_(y) {
	if (CheckLength(width) && CheckLength(height)) {
		width_ = width;
		height_ = height;
		rect_ = new SDL_Rect;
		rect_->x = x_;
		rect_->y = y_;
		rect_->w = width_;
		rect_->h = height_;
	} else {
		throw std::invalid_argument("Error: invalid length for width and height.");
	}
}
//Rule of Five


//Node destructor
Node::~Node() {
	if (surface_ != nullptr && surface_ != NULL)
		SDL_FreeSurface(surface_);
	if (texture_ != nullptr && texture_ != NULL)
		SDL_DestroyTexture(texture_);
	if (rect_ != nullptr && rect_ != NULL)
		delete rect_;
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
void Node::CreateTexture(SDL_Renderer * renderer) {
	if (renderer == nullptr || renderer == NULL)
		throw std::invalid_argument("Fatal Error: Node::CreateTexture(): renderer is a nullptr");
	
	if (surface_ == nullptr || surface_ == NULL)
		CreateSurface();
	
	texture_ = SDL_CreateTextureFromSurface(renderer, surface_);
}

bool Node::CheckLength(float len) {
	if (len > 0)
		return true;
	return false;
}
