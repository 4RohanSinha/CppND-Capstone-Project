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
	Renderer(): height_(200), width_(400) {}
	Renderer(int height, int width);
	~Renderer();
	void AddNode(Node* node);
	void Update();
	void Clear();
	void ClearNode(Node* node);
	void HideNode(Node* node);
	void ShowNode(Node* node);
private:
	int height_;
	int width_;
	std::vector<Node*> nodes_;
	SDL_Renderer *renderer = NULL;
	SDL_Window *window = NULL;
};

#endif
