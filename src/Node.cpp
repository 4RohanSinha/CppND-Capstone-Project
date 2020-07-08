#include "Node.h"
#include <iostream>

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
	if (surface_ != nullptr && surface_ != NULL)
		SDL_FreeSurface(surface_);
	if (texture_ != nullptr && texture_ != NULL)
		SDL_DestroyTexture(texture_);
	if (rect_ != nullptr && rect_ != NULL)
		rect_.reset();
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
	//rect_ = new SDL_Rect;
	if (rect_ != NULL && rect_ != nullptr)
		rect_.reset();
	rect_ = std::make_shared<SDL_Rect>();
	rect_->x = x_;
	rect_->y = y_;
	rect_->w = width_;
	rect_->h = height_;
}

void Node::CreateTexture(SDL_Renderer * renderer) {
	if (renderer == nullptr || renderer == NULL)
		throw std::invalid_argument("Fatal Error: Node::CreateTexture(): renderer is a nullptr");
	
	if (surface_ == nullptr || surface_ == NULL)
		CreateSurface();
	
	texture_ = SDL_CreateTextureFromSurface(renderer, surface_);
}

void Node::Move(float newX, float newY) {
	std::thread mover(&Node::MotionAnimate, this, newX, newY);
	mover.detach();
	threads_.emplace_back(std::move(mover));
}

void Node::MotionAnimate(float newX, float newY) {
	float slope = (y_ - newY)/(x_ - newX);
	float intercept = y_ - (slope*x_);

	//SDL_Event e;
	while (abs(x_ - newX) > 0.001) {
		//SDL_PollEvent(&e);
		//if (e.type == SDL_QUIT) return;
		y_ = (slope*x_) + intercept;
		SDL_Delay(30);
		if (newX > x_)
			x_ += 2;
		else if (newX == x_)
			return;
		else
			x_ -= 2;
	}
}

bool Node::CheckLength(float len) {
	if (len > 0)
		return true;
	return false;
}
