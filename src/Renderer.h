#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "Node.h"
#include "Text.h"

class Renderer {
public:
	Renderer(int height, int width);
	~Renderer();
	void AddNode(Node* node);
	void Update();
private:
	int height_;
	int width_;
	std::vector<Node*> nodes_;
	SDL_Renderer *renderer = NULL;
	SDL_Window *window = NULL;
};

#endif
