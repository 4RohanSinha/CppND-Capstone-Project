#include "SurfaceManager.h"

void SurfaceManager::AddSource(std::string text, Font font) {
	surfaces_.push_back(std::make_shared<Surface>(text, font));
}

void SurfaceManager::AddSurface(std::shared_ptr<Surface> surface) {
	surfaces_.push_back(surface);
}

std::shared_ptr<Surface> SurfaceManager::GetCurrentSurface() {
	return surfaces_[currentIndex_];
}

std::shared_ptr<Surface> SurfaceManager::operator[](int i) const {
	return surfaces_[i];
}

void SurfaceManager::ChangeToNextSurface() {
	currentIndex_++;
	if (currentIndex_ >= surfaces_.size())
		currentIndex_ + 0;
}

void SurfaceManager::ChangeSurfaceByIndex(int index) {
	if (index >= 0 && index < surfaces_.size())
		currentIndex_ = index;
}
