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

/*
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
}*/

template<typename T>
std::unique_ptr<T> GetUniquePtr(T *t) {
	return std::unique_ptr<T, void*(T*)>(t, [](T* t) { SDL_DelObject(t); });
}

enum TextureRender {
	kRenderNow,
	kRenderForever,
	kNoRender,
	kClear
};

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
	template<typename T>
	void CallOnAnimation(T animateFunction) {
		animationFunction_ = animateFunction;
	}
	
	void AnimationChange();

	//void Move(float newX, float newY);
	void Move(float newX, float newY, float speed);

	void Move(float direction, float speed);

	void ChangeSize(int width, int height);

	virtual Color GetColor() { return Color(0, 0, 0, 0); }

	void SetForm(int form);

	virtual void Clear();

	void ClearAnimations();

	bool IsAnimating() { return !animations_.empty(); }

	float GetSpeed() { if (IsAnimating()) return animations_.front()->GetSpeed(); else return 0; }

	void ChangeSpeed(float newSpeed) { if (IsAnimating()) animations_.front()->SetSpeed(-4.0); }

	float x;
	float y;
	std::string collisionBitMask{"Unknown Node Type"};

protected:
	bool rendererSetDimensions_{false};
	
	bool usesSurfaces_{true};

	bool usesTextures_{true};

	TextureRender status_{TextureRender::kRenderNow};
	
	int width_;
	
	int height_;
	
	bool isHidden_{false};

	//NOTE: the variable below is used to help transition to the new rendering system
	//delete after the transition is complete
	bool useNewExperiment{false};

	//TODO: allow Node descendants not to require surfaces and textures
	//fix the rendering system to do so
	//allow descendants to declare their own custom rendering processes
	//this will allow the Shape class to be used
	
	std::shared_ptr<SDL_Surface> surface_ = nullptr;
	
	std::shared_ptr<SDL_Texture> texture_ = nullptr;

	std::shared_ptr<SDL_Rect> rect_ = nullptr;

	int currentForm_ = 0;

	std::vector<std::string> sources_;

	std::vector<std::shared_ptr<SDL_Surface>> surfaces_;

	std::vector<std::shared_ptr<SDL_Texture>> textures_;

	std::deque<std::shared_ptr<Animation::Animation>> animations_;

	std::queue<std::shared_ptr<SDL_Surface>> newSurfaces_;

	virtual void ConstructRectangle();
	
	virtual void GenerateSurfacesFromSources() {}
	
	virtual void CreateSurface(int i) {}

	static bool CheckLength(float len);

	virtual void AssignRenderer(std::shared_ptr<SDL_Renderer> renderer) {}

	virtual void Render() {}

	std::function<void()> animationFunction_;

	std::vector<SDL_Point> points_;

	bool textureSurface_{true};
	

	//make this class a friend so that it can access the texture private member
	//this member should not be accessed from other classes or users, so keep it protected
	//limit its access to descendant and friend classes
	//TODO: figure out way to reduce number of friend classes
	friend class Renderer;
	
	friend class Layer;	
	
	friend class CollisionDetector;
};

#endif
