#ifndef NODE_H
#define NODE_H

#include <vector>
#include <unordered_map>
#include <deque>
#include <algorithm>
#include <stdexcept>
#include "SDL2_headers.h"
#include <memory>
#include <cmath>
#include "TextureManager.h"

//The class Node is an abstract class with multiple virtual functions
//it is needed to unite Sprite and Text classes under one class, so then a vector of Nodes (as pointers - abstract classes alone cannot be stored in vectors) are stored together in one vector

class Node {
public:
	Node();

	Node(float x_val, float y_val, int width_val, int height_val); //basic constructor

	Node(float x_val, float y_val); //basic constructor

	virtual void Render() = 0;

	virtual void Clear() = 0;

	//this function is defined in Node.cpp, but allow future descendants of Node to override it
	virtual void Update();

	//some basic variables setting the position of the Node
	float x;
	float y;
	int width;
	int height;

	//the velocity can also be used to change the Node's position
	std::vector<float> velocity{0, 0};

protected:
	bool isHidden_{false};

	virtual void ConstructRectangle() = 0;

	virtual void AssignRenderer(SDL_Renderer* renderer) = 0;
	
	static bool CheckLength(float len);

	//make this class a friend so that it can call ConstructRectangle() and AssignRenderer(SDL_Renderer* renderer)
	friend class Scene;
};

#endif
