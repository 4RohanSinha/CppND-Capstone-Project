#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>
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

class Window;

class Renderer {
public:
	Renderer() {}
	Renderer(SDL_Window* win);
	~Renderer();
	SDL_Renderer* getSDL() { return renderer; }
private:
	int height_;
	int width_;
	std::string windowTitle_;
	SDL_Renderer* renderer = nullptr;
	SDL_Window* window = nullptr;
};

#endif
