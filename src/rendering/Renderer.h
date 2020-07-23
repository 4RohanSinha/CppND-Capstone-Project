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
#include "Layer.h"
#include "Integrate.h"

class Renderer {
public:
	Renderer(): height_(200), width_(400) {}
	Renderer(int height, int width, std::string windowTitle);
	void AddLayers(int n);
	void AddToLayer(int layer, std::shared_ptr<Node> node);
	void AddNode(std::shared_ptr<Node> node);
	void Update();
	void Clear();
	void ClearNode(std::shared_ptr<Node> node);
	void HideNode(std::shared_ptr<Node> node);
	void ShowNode(std::shared_ptr<Node> node);
	int GetNumberOfLayers();
	~Renderer();
private:
	int height_;
	int width_;
	std::string windowTitle_;
	std::vector<Layer> layers_;
	std::shared_ptr<SDL_Renderer> renderer = nullptr;
	integration::unique_ptr_sdl<SDL_Window> window = nullptr;
};

#endif
