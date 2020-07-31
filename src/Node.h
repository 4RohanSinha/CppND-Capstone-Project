#ifndef NODE_H
#define NODE_H

#include <vector>
#include <unordered_map>
#include <deque>
#include <algorithm>
#include <stdexcept>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>
#include <memory>
#include <cmath>
#include "Physics.h"
#include "TextureManager.h"
#include "Color.h"

class Physics;

class Node {
public:
	Node();

	Node(float x, float y, int width, int height); //basic constructor

	Node(float x, float y); //basic constructor

	virtual void Draw() {}

	float GetX() { return x; }

	float GetY() { return y; }
	
	int GetWidth() { return width_; }
	
	int GetHeight() { return height_; }

	virtual void Render() {}

	//TODO: get rid of the Animation/MoveAnimation classes
	//replace with dx and dy variables to control movement velocity

	virtual Color GetColor() { return Color(0, 0, 0, 0); }

	void SetForm(int form);

	virtual void Clear() {}

	float x;
	
	float y;
	
	int width_;

	int height_;
	
	std::string collisionBitMask{"Unknown Node Type"};

	std::unique_ptr<Physics> physics;
	std::vector<float> velocity{0, 0};

protected:
	float speed{2.0};
	float angle;
	
	bool isHidden_{false};

	virtual void ConstructRectangle() {}

	virtual void AssignRenderer(SDL_Renderer* renderer) {}
	
	static bool CheckLength(float len);

	std::vector<SDL_Point> points_;

	bool textureSurface_{true};
	

	//make this class a friend so that it can access the texture private member
	//this member should not be accessed from other classes or users, so keep it protected
	//limit its access to descendant and friend classes
	//TODO: figure out way to reduce number of friend classes
	friend class Renderer;
	
	friend class Layer;	
	
	friend class CollisionDetector;

	friend class Scene;
};

#endif
