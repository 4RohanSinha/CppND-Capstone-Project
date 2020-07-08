#ifndef NODE_H
#define NODE_H

#include <vector>
#include <thread>
#include <stdexcept>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>
#include <memory>
#include <cmath>

#define EPSILON 0.001

class Node {
public:
	Node(float x, float y, int width, int height); //basic constructor
	Node(float x, float y): x_(x), y_(y), width_(0), height_(0) {} //basic constructor

	float GetX() { return x_; }
	float GetY() { return y_; }
	int GetWidth() { return width_; }
	int GetHeight() { return height_; }
	void ConstructRectangle();
	//Rule of Five
	~Node(); //destructor
/*
	Node(Node const &source); //copy constructor
	Node& operator=(Node const &source); //copy assignment operator
	Node(Node &&source); //move constructor
	Node& operator=(Node &&source); //move assignment operator
*/	
	//virtual function to create surface
	//surface is used to create the texture that can then be rendered
	virtual void CreateSurface() = 0;

	void CreateTexture(SDL_Renderer * renderer); //create texture that the renderer will use

	void Move(float newX, float newY);

protected:
	float x_;
	float y_;
	int width_;
	int height_;
	bool isHidden_{false};
	SDL_Surface * surface_ = NULL;
	SDL_Texture * texture_ = NULL;
	//SDL_Rect * rect_;
	std::shared_ptr<SDL_Rect> rect_ = nullptr;
	std::vector<std::thread> threads_;
	static bool CheckLength(float len);
	void MotionAnimate(float newX, float newY);

	//make this class a friend so that it can access the texture private member
	//this member should not be accessed from other classes or users, so keep it protected
	//limit its access to descendant and friend classes
	friend class Renderer;
	
};

#endif
