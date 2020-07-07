#include "Renderer.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>

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
	nodes_.push_back(node);
}

void Renderer::Update() {
	for (auto i: nodes_) {
		SDL_RenderCopy(renderer, i->texture_, NULL, i->rect_);
	}
	SDL_RenderPresent(renderer);
}

Renderer::~Renderer() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TTF_Quit();
	SDL_Quit();
}
