#include <iostream>
#include "SpriteManager.h"

SpriteManager::SpriteManager(std::shared_ptr<SDL_Renderer> renderer): NodeManager(renderer) {
	textureManager_ = std::make_unique<TextureManager>(renderer_);
}

void SpriteManager::AssignCoordinates(int x_val, int y_val, int w_val, int h_val) {
	rect_.x = x_val;
	rect_.y = y_val;
	rect_.w = w_val;
	rect_.h = h_val;
}

void SpriteManager::AssignRenderer(std::shared_ptr<SDL_Renderer> renderer) {
	renderer_ = renderer;
	rendererAssigned_ = true;
	textureManager_ = std::make_unique<TextureManager>(renderer_);
	for (int i = 0; i < imageSources_.size(); i++)
		textureManager_->AddSource(imageSources_[i]);
}

void SpriteManager::AddSource(std::string source) {
	imageSources_.push_back(source);
	if (textureManager_ != nullptr)
		textureManager_->AddSource(source);
}

std::string SpriteManager::operator[](int i) const {
	return imageSources_[currentForm_];
}

void SpriteManager::ShowNextSource() {
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

void SpriteManager::ConstructRectangle(float x, float y, int w, int h) {
	rect_.x = x;
	rect_.y = y;
	rect_.w = w;
	rect_.h = h;
}

void SpriteManager::Render() {
	SDL_RenderCopy(renderer_.get(), (*textureManager_)[currentForm_].texture_.get(), NULL, &rect_);
}

void SpriteManager::Clear() {
	SDL_SetRenderTarget(renderer_.get(), (*textureManager_)[currentForm_].texture_.get());
	SDL_RenderFillRect(renderer_.get(), &rect_);
}
