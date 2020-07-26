#include <iostream>
#include "TextureManager.h"


TextureManager::TextureManager(std::shared_ptr<SDL_Renderer> renderer, SurfaceManager surfaceManager) {
	renderer_ = renderer;
	for (int i = 0; i < surfaceManager.size(); i++) {
		AddSource(surfaceManager[i]);	
	}
}

void TextureManager::AddSource(std::string imgName) {
	textures_.push_back(Texture(imgName, renderer_));
}

void TextureManager::AddSource(Surface surface) {
	textures_.push_back(Texture(surface, renderer_));
}

void TextureManager::AddTexture(Texture texture) {
	textures_.emplace_back(std::move(texture));
}

Texture& TextureManager::operator[](int i) {
	return textures_[i];
}
