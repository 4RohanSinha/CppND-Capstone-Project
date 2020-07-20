#include "SpriteManager.h"

SpriteManager::SpriteManager(std::shared_ptr<SDL_Renderer> renderer): renderer_(renderer) {
	textureManager_ = std::make_unique<TextureManager>(renderer_);
	rendererAssigned_ = true;
}

void SpriteManager::AssignRenderer(std::shared_ptr<SDL_Renderer> renderer) {
	renderer_ = renderer;
	rendererAssigned_ = true;
	textureManager_ = std::make_unique<TextureManager>(renderer_);
	for (int i = 0; i < imageSources_.size(); i++)
		textureManager_->AddSource(imageSources_[i]);
}

void SpriteManager::AddImageSource(std::string imageSource) {
	if (textureManager_ == nullptr)
		throw std::runtime_error("Error: texture manager not assigned because the renderer is nullptr. Cannot continue.");
	textureManager_->AddSource(imageSource);
}

std::shared_ptr<Texture> SpriteManager::GetCurrentTexture() {
	if (textureManager_ == nullptr)
		throw std::runtime_error("Error: texture manager not assigned because the renderer is nullptr. Cannot continue.");
	return (*textureManager_)[currentForm_];
}

std::unordered_map<std::string, std::shared_ptr<Texture>> SpriteManager::operator[](int i) const {
	if (textureManager_ == nullptr)
		throw std::runtime_error("Error: texture manager not assigned because the renderer is nullptr. Cannot continue.");
	if (i >= textureManager_->size())
		throw std::invalid_argument("Error: SpriteManager[] operator: i is out of bounds.");
	return {{imageSources_[i], (*textureManager_)[i]}};
}

void SpriteManager::ShowNextImage() {
	if (textureManager_ == nullptr)
		throw std::runtime_error("Error: texture manager not assigned because the renderer is nullptr. Cannot continue.");
	currentForm_++;
	if (currentForm_ >= textureManager_->size()) {
		currentForm_ = 0;
	}
}

void SpriteManager::ChangeByIndex(int index) {
	if (textureManager_ == nullptr)
		throw std::runtime_error("Error: texture manager not assigned because the renderer is nullptr. Cannot continue.");
	if (index >= textureManager_->size())
		throw std::invalid_argument("Error: SpriteManager::ChangeByIndex(int index): index is out of bounds.");
	currentForm_ = index;
}
