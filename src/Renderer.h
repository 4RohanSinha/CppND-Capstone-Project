#ifndef RENDERER_H
#define RENDERER_H

#include "SDL2_headers.h"
#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include <thread>
#include <future>
#include "Node.h"
#include "Text.h"
#include "Sprite.h"
#include "Integrate.h"

class Renderer {
public:
	Renderer(SDL_Window* win);
	~Renderer();
	//Because there cannot be multiple windows at a time in this project (see Window.h), the Window copy constructor has been deleted.
	//Therefore, if multiple windows cannot exist at once, multiple renderers should not exist at once either. (Each window has one renderer).
	//However, a renderer could be moved
	Renderer(const Renderer& source) = delete;
	Renderer& operator=(const Renderer& source) = delete;
	Renderer(Renderer&& source);
	Renderer& operator=(Renderer&& source);
	SDL_Renderer* getSDL() { return renderer; }
private:
	SDL_Renderer* renderer = nullptr;
};

#endif
