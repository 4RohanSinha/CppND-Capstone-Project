#include "SurfaceManager.h"

void SurfaceManager::AddSource(std::string text, Font font) {
	surfaces_.push_back(Surface(text, font));
}

void SurfaceManager::AddSurface(Surface surface) {
	surfaces_.push_back(surface);
}

Surface SurfaceManager::operator[](int i) const {
	return surfaces_[i];
}
