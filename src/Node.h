#ifndef NODE_H
#define NODE_H

#include <vector>
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
#include "Animation.h"
#include "MoveAnimation.h"

//Using SDL2 with smart pointers
//research for using SDL2 and smart pointers combined is from: https://blog.galowicz.de/2016/02/21/automatic_resource_release_with_sdl/

static void SDL_DelObject(SDL_Window* window) {SDL_DestroyWindow(window);}
static void SDL_DelObject(SDL_Renderer* renderer) {SDL_DestroyRenderer(renderer);}
static void SDL_DelObject(SDL_Texture* texture) {SDL_DestroyTexture(texture);}
static void SDL_DelObject(SDL_Surface* surface) {SDL_FreeSurface(surface);}
static void SDL_DelObject(TTF_Font* ttfFont) { if (ttfFont != NULL && ttfFont != nullptr) TTF_CloseFont(ttfFont); }

template <typename T>
std::shared_ptr<T> GetSharedPtr(T *t) {
	//TODO: see if function pointer can be passed in instead
	return std::shared_ptr<T>(t, [](T* t) { SDL_DelObject(t); });
}
enum TextureRender {
	kRenderNow,
	kRenderForever,
	kNoRender
};

class Node {
public:
	Node(float x, float y, int width, int height); //basic constructor
	Node(float x, float y); //basic constructor

	float GetX() { return x_; }
	float GetY() { return y_; }
	int GetWidth() { return width_; }
	int GetHeight() { return height_; }
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
	
	virtual void AnimationChange() = 0;
	void Move(float newX, float newY);

	void ChangeSize(int width, int height);

	void Clear();

	bool IsAnimating() { return !animations_.empty(); }

protected:
	bool rendererSetDimensions_{false};
	TextureRender status_{TextureRender::kRenderNow};
	float x_;
	float y_;
	int width_;
	int height_;
	bool isHidden_{false};
	std::shared_ptr<SDL_Surface> surface_ = nullptr;
	std::shared_ptr<SDL_Texture> texture_ = nullptr;
	std::shared_ptr<SDL_Rect> rect_ = nullptr;
	std::queue<std::shared_ptr<Animation>> animations_;

	void ConstructRectangle();
	virtual void CreateSurface() = 0;
	void CreateTexture(std::shared_ptr<SDL_Renderer> renderer); //create texture that the renderer will use

	static bool CheckLength(float len);

	//make this class a friend so that it can access the texture private member
	//this member should not be accessed from other classes or users, so keep it protected
	//limit its access to descendant and friend classes
	friend class Renderer;
	friend class Layer;	
};

#endif
