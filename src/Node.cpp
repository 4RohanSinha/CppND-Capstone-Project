#include "Node.h"
#include <iostream>

Node::Node(float x, float y): x_(x), y_(y), width_(0), height_(0) {
	rendererSetDimensions_ = true;
	queue_ = std::make_shared<MessageQueue<PointMessage>>();
}

Node::Node(float x, float y, int width, int height): x_(x), y_(y) {
	queue_ = std::make_shared<MessageQueue<PointMessage>>();
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
	moveAnimates_.push(std::make_shared<MoveAnimation>(0, 0, newX, newY));
}

void Node::ChangeSize(int width, int height) {
}

void Node::Clear() {
}

void Node::MotionAnimate(float newX, float newY) {
	std::cout << std::this_thread::get_id() << " " << newX << " " << newY << " acquiring lock" << std::endl;
	std::lock_guard<std::mutex> lock(mtx_);
	float slope = (y_ - newY)/(x_ - newX);
	float intercept = y_ - (slope*x_);

	SDL_Event e;
	while (abs(x_ - newX) > 0.001) {
		isAnimating_ = true;
		SDL_PollEvent(&e);
		if (e.type == SDL_QUIT) return;
		y_ = (slope*x_) + intercept;
		SDL_Delay(30);
		ChangeElement();
		if (newX > x_)
			x_ += 2;
		else if (newX == x_)
			return;
		else
			x_ -= 2;
	}
	isAnimating_ = false;
	status_ = TextureRender::kRenderNow;
}

bool Node::CheckLength(float len) {
	if (len > 0)
		return true;
	return false;
}
