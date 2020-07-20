#include "TextureManager.h"

TextureManager::TextureManager(std::shared_ptr<SDL_Renderer> renderer, std::shared_ptr<SurfaceManager> surfaceManager) {
	renderer_ = renderer;
	for (int i = 0; i < surfaceManager->size(); i++) {
		AddSource((*surfaceManager)[i]);	
	}
}

void TextureManager::AddSource(std::string imgName) {
	textures_.push_back(std::make_shared<Texture>(imgName, renderer_));
}

void TextureManager::AddSource(std::shared_ptr<Surface> surface) {
	textures_.push_back(std::make_shared<Texture>(surface, renderer_));
}

void TextureManager::AddTexture(std::shared_ptr<Texture> texture) {
	textures_.push_back(texture);
}

std::shared_ptr<Texture> TextureManager::operator[](int i) const {
	return textures_[i];
}
