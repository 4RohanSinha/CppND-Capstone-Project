#include "Node.h"
#include <iostream>

Node::Node() {
}

//width=0 and height=0 tells the renderer to automatically set the dimensions with SDL_QueryTexture
Node::Node(float x_val, float y_val): x(x_val), y(y_val), width(0), height(0) {
}

//specifically set width and height - the renderer will not call SDL_QueryTexture
Node::Node(float x_val, float y_val, int width_val, int height_val): x(x_val), y(y_val) {
	if (CheckLength(width_val) && CheckLength(height_val)) {
		width = width_val;
		height = height_val;
	} else {
		throw std::invalid_argument("Error: invalid length for width and height.");
	}
}

//just makes sure that the width/height of a Node is nonnegative
bool Node::CheckLength(float len) {
	if (len > 0)
		return true;
	return false;
}

//this method is called by the renderer, in addition to Node::Render
//it allows for a Node object to be moved by manipulating velocity
void Node::Update() {
	x += velocity[0];
	y += velocity[1];
}
