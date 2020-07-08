#include "Renderer.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

Renderer::Renderer(int height, int width): height_(height), width_(width) {
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	SDL_CreateWindowAndRenderer(width_, height_, 0, &window, &renderer);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

void Renderer::AddNode(Node* node) {
	node->CreateTexture(renderer);
	SDL_QueryTexture(node->texture_, NULL, NULL, &node->width_, &node->height_);
	node->ConstructRectangle();
	nodes_.push_back(node);
}

void Renderer::Update() {
	for (auto i: nodes_) {
		
		if (i->isHidden_ == false) {
			ClearNode(i);
			i->ConstructRectangle();
			i->CreateSurface();
			i->CreateTexture(renderer);
			for (int k = 0; k < 25; k++)
				SDL_RenderCopy(renderer, i->texture_, NULL, (i->rect_).get());
		}
	}
	SDL_RenderPresent(renderer);
}

void Renderer::Clear() {
	SDL_RenderClear(renderer);
}

void Renderer::ClearNode(Node* node) {
	for (int i = 0; i < nodes_.size(); i++) {
		if (node == nodes_[i]) {
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
			SDL_RenderFillRect(renderer, (node->rect_).get());
			break;
		}
	}
}

void Renderer::HideNode(Node* node) {
	ClearNode(node);
	node->isHidden_ = true;
}

void Renderer::ShowNode(Node* node) {
	node->isHidden_ = false;
}

Renderer::~Renderer() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TTF_Quit();
	SDL_Quit();
}
