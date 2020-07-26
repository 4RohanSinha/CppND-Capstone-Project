#ifndef NODE_H
#define NODE_H

#include <vector>
#include <unordered_map>
#include <queue>
#include <deque>
#include <algorithm>
#include <mutex>
#include <thread>
#include <future>
#include <stdexcept>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>
#include <memory>
#include <cmath>
#include "animation/Animation.h"
#include "animation/MoveAnimation.h"
#include "TextureManager.h"
#include "Color.h"

class Node {
public:
	Node() {}

	Node(float x, float y, int width, int height); //basic constructor

	Node(float x, float y); //basic constructor

	virtual void Draw() {}

	float GetX() { return x; }

	float GetY() { return y; }
	
	int GetWidth() { return width_; }
	
	int GetHeight() { return height_; }

	virtual void Render() {}

	//TODO: get rid of two methods below and the Animation/MoveAnimation classes
	//replace with dx and dy variables to control movement velocity
	void Move(float newX, float newY, float speed);

	void Move(float direction, float speed);

	void ChangeSize(int width, int height);

	virtual Color GetColor() { return Color(0, 0, 0, 0); }

	void SetForm(int form);

	virtual void Clear() {}

	void ClearAnimations();

	bool IsAnimating() { return !animations_.empty(); }

	float GetSpeed() { if (IsAnimating()) return animations_.front()->GetSpeed(); else return 0; }

	void ChangeSpeed(float newSpeed) { if (IsAnimating()) animations_.front()->SetSpeed(-4.0); }

	float x;
	
	float y;
	
	std::string collisionBitMask{"Unknown Node Type"};

protected:
	int width_;
	
	int height_;
	
	bool isHidden_{false};

	std::deque<std::shared_ptr<Animation::Animation>> animations_;

	virtual void ConstructRectangle() {}

	virtual void AssignRenderer(std::shared_ptr<SDL_Renderer> renderer) {}
	
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
