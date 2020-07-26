#include "TextManager.h"
#include <iostream>

TextManager::TextManager(std::shared_ptr<SDL_Renderer> renderer): NodeManager(renderer) {
	textureManager_ = std::make_unique<TextureManager>(renderer_);
	rendererAssigned_ = true;
}

void TextManager::AssignCoordinates(int x_val, int y_val) {
	rect_.x = x_val;
	rect_.y = y_val;
	rect_.w = 0;
	rect_.h = 0;
	//width and height are set with SDL_QueryTexture shortly before rendering
}

void TextManager::AssignRenderer(std::shared_ptr<SDL_Renderer> renderer) {
	renderer_ = renderer;
	rendererAssigned_ = true;
	textureManager_ = std::make_unique<TextureManager>(renderer_, surfaceManager_);
}

//TODO: fix the two methods below
//right now, they add too many elements to the textSources_ and fonts_ vectors
//fix that
void TextManager::AddSource(std::string source) {
	textSources_.push_back(source);
	Font filler = Font("Ubuntu-M");
	if (!fonts_.empty()) {
		filler = fonts_[fonts_.size() - 1];
	}
	fonts_.push_back(filler);
	surfaceManager_.AddSurface(Surface(source, filler));

	if (textureManager_ != nullptr)
		textureManager_->AddSource(surfaceManager_[surfaceManager_.size() - 1]);
}

void TextManager::AddFont(Font font) {
	fonts_.push_back(font);
	std::string source = "";
	if (!textSources_.empty()) {
		source = textSources_[textSources_.size() - 1];	
	}

	textSources_.push_back(source);
	surfaceManager_.AddSurface(Surface(source, font));

	if (textureManager_ != nullptr)
		textureManager_->AddSource(surfaceManager_[surfaceManager_.size() - 1]);
}

void TextManager::ShowNextSource() {
	if (textureManager_ == nullptr)
		throw std::runtime_error("Error: texture manager not assigned because the renderer is nullptr. Cannot show next source.");
	currentForm_++;
	if (currentForm_ >= textureManager_->size()) {
		currentForm_ = 0;
	}
}

void TextManager::ChangeByIndex(int index) {
	if (textureManager_ = nullptr)
		throw std::runtime_error("Error: texture manager not assigned because the renderer is nullptr. Cannot change by index.");
	if (index >= textureManager_->size())
		throw std::invalid_argument("Error: TextManager::ChangeByIndex(int index): index is out of bounds.");
	currentForm_ = index;
}

void TextManager::ConstructRectangle(float x, float y) {
	rect_.x = x;
	rect_.y = y;
	rect_.w = 0;
	rect_.h = 0;
}

void TextManager::Render() {
	if (renderer_ == nullptr)
		throw std::runtime_error("The renderer is nullptr. Cannot render.");
	if (textureManager_ == nullptr)
		throw std::runtime_error("Error: texture manager not assigned because the renderer is nullptr. Cannot render.");
	int width;
	int height;
	SDL_QueryTexture((*textureManager_)[currentForm_].texture_.get(), NULL, NULL, &width, &height);
	rect_.w = width;
	rect_.h = height;
	SDL_RenderCopy(renderer_.get(), (*textureManager_)[currentForm_].texture_.get(), NULL, &rect_);
}

void TextManager::Clear() {
	SDL_SetRenderTarget(renderer_.get(), (*textureManager_)[currentForm_].texture_.get());
	SDL_RenderFillRect(renderer_.get(), &rect_);
}
