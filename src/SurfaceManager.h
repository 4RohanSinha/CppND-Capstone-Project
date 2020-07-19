#ifndef SURFACE_MANAGER_H
#define SURFACE_MANAGER_H

#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "Surface.h"

class SurfaceManager {
public:
	void AddSource(std::string text, Font font);
	void AddSurface(std::shared_ptr<Surface> surface);
	std::shared_ptr<Surface> GetCurrentSurface();
	std::shared_ptr<Surface> operator[](int i) const;
	void ChangeToNextSurface();
	void ChangeSurfaceByIndex(int index);
	int size() { return surfaces_.size(); }
private:
	std::vector<std::shared_ptr<Surface>> surfaces_;
	int currentIndex_;
};

#endif
