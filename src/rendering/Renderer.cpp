#include "Node.h"
#include "Renderer.h"
#include "Layer.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

//TODO: add title as argument to constructor function
Renderer::Renderer(int height, int width, std::string windowTitle): height_(height), width_(width), windowTitle_(windowTitle) {
	TTF_Init();
	IMG_Init(IMG_INIT_PNG);
	window = integration::create_unique(SDL_CreateWindow(windowTitle_.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width_, height_, 0));
	renderer = integration::create_shared(SDL_CreateRenderer(window.get(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC));
	SDL_SetRenderDrawColor(renderer.get(), 0, 0, 0, 0);
	SDL_RenderClear(renderer.get());
	SDL_RenderPresent(renderer.get());
}

void Renderer::AddNode(std::shared_ptr<Node> node) {
	if (layers_.size() > 0) {
		layers_[layers_.size() - 1].AddNode(node);
	}
}

int Renderer::GetNumberOfLayers() {
	int cnt = 0;
	for (auto i: layers_) {
		if (i.HasNodes())
			cnt++;
	}
	return cnt;
}

void Renderer::AddLayers(int n) {
	for (int i = 0; i < n; i++)
		layers_.push_back(Layer(renderer));
}

void Renderer::AddToLayer(int layer, std::shared_ptr<Node> node) {
	if (layer - 1 >= layers_.size())
		for (int i = layers_.size(); i < layer-1; i++)
			layers_.push_back(Layer(renderer));
	layers_[layer-1].AddNode(node);
}

void Renderer::Update() {
	for (auto i: layers_) {
		if (i.HasNodes())
			i.Update();
			
	}
}

void Renderer::Clear() {
	SDL_RenderClear(renderer.get());
}

void Renderer::ClearNode(std::shared_ptr<Node> node) {
	if (node == nullptr || renderer == nullptr)
		return;
	SDL_SetRenderTarget(renderer.get(), (node->texture_).get());
	SDL_RenderFillRect(renderer.get(), (node->rect_).get());
}

void Renderer::HideNode(std::shared_ptr<Node> node) {
	ClearNode(node);
	node->isHidden_ = true;
}

void Renderer::ShowNode(std::shared_ptr<Node> node) {
	node->isHidden_ = false;
}

Renderer::~Renderer() {
	TTF_Quit();
	Mix_Quit();
	IMG_Quit();
	SDL_QuitSubSystem(SDL_INIT_EVERYTHING);
	SDL_Quit();
}
