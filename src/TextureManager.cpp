#include <iostream>
#include "TextureManager.h"


TextureManager::TextureManager(SDL_Renderer* renderer, SurfaceManager surfaceManager) {
	for (int i = 0; i < surfaceManager.size(); i++) {
		AddSource(surfaceManager[i], renderer);	
	}
}

void TextureManager::AddSource(std::string imgName, SDL_Renderer* renderer) {
	textures_.push_back(Texture(imgName, renderer));
}

void TextureManager::AddSource(Surface surface, SDL_Renderer* renderer) {
	Texture texture(surface, renderer);
	textures_.push_back(Texture(surface, renderer));
}

void TextureManager::AddTexture(Texture texture) {
	textures_.emplace_back(std::move(texture));
}

Texture& TextureManager::operator[](int i) {
	return textures_[i];
}
