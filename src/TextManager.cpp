#include "TextManager.h"

/*
TextManager::TextManager(std::shared_ptr<SDL_Renderer> renderer): renderer_(renderer) {
	surfaceManager_ = std::make_shared<SurfaceManager>();
	textureManager_ = std::make_unique<TextureManager>(renderer_);
	rendererAssigned_ = true;
}

void TextManager::AssignRenderer(std::shared_ptr<SDL_Renderer> renderer) {
	renderer_ = renderer;
	rendererAssigned_ = true;
	textureManager_ = std::make_unique<TextureManager>(renderer_, surfaceManager_);
}

void TextManager::AddText(std::string text, Font font) {
	surfaceManager_->AddSource(text, font);
	if (textureManager_ != nullptr)
		textureManager_->AddSource((*surfaceManager_)[surfaceManager_->size() - 1]);
}

std::shared_ptr<Surface> TextManager::GetCurrentSurface() {
	return (*surfaceManager_)[currentForm_];
}

std::shared_ptr<Texture> TextManager::GetCurrentTexture() {
	if (textureManager_ == nullptr)
		throw std::runtime_error("textureManager_ has not been assigned yet");
	return (*textureManager_)[currentForm_];
}

std::shared_ptr<Surface> TextManager::GetSurfaceAtIndex(int i) const {
	return (*surfaceManager_)[i];
}

std::shared_ptr<Texture> TextManager::operator[](int i) const {
	if (textureManager_ == nullptr)
		throw std::runtime_error("Error: textureManager_ has not been assigned yet");
	return (*textureManager_)[i];
}

void TextManager::ShowNextText() {
	currentForm_++;
	if (textureManager_ != nullptr) {
		if (currentForm_ >= textureManager_->size())
			currentForm_ = 0;
	}
}

void TextManager::ChangeByIndex(int index) {
	if (textureManager_ == nullptr)
		throw std::runtime_error("Error: textureManager_ has not been assigned yet");
	if (index < textureManager_->size())
		currentForm_ = index;
	else
		throw std::invalid_argument("Error: index out of bounds in TextManager::ChangeByIndex.");
}*/
