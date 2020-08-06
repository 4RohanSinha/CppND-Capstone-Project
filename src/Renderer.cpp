#include "Renderer.h"
#include "Node.h"
#include <iostream>

Renderer::Renderer(SDL_Window* win) {
	renderer = (SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC));
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

Renderer::~Renderer() {
	SDL_DestroyRenderer(renderer);
}

Renderer::Renderer(Renderer&& source) {
	renderer = source.renderer;
	source.renderer = nullptr;
}

Renderer& Renderer::operator=(Renderer&& source) {
	if (this == &source)
		return *this;

	if (renderer != nullptr)
		SDL_DestroyRenderer(renderer);

	renderer = source.renderer;
	source.renderer = nullptr;
	return *this;
}

