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

class Renderer {
public:
	Renderer(SDL_Window* win);
	~Renderer();
	SDL_Renderer* getSDL() { return renderer; }
private:
	SDL_Renderer* renderer = nullptr;
};

#endif
