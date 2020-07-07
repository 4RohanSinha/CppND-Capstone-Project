#ifndef NODE_H
#define NODE_H

#include <stdexcept>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>

class Node {
public:
	Node(float x, float y, float width, float height); //basic constructor
	Node(float x, float y): x_(x), y_(y), width_(100), height_(100) {} //basic constructor

	float GetX() { return x_; }
	float GetY() { return y_; }
	float GetWidth() { return width_; }
	float GetHeight() { return height_; }

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

protected:
	float x_;
	float y_;
	float width_;
	float height_;
	SDL_Surface * surface_;
	SDL_Texture * texture_;
	SDL_Rect * rect_;

	static bool CheckLength(float len);
	//make this class a friend so that it can access the texture private member
	//this member should not be accessed from other classes or users, so keep it protected
	//limit its access to descendant and friend classes
	friend class Renderer;
	
};

#endif
