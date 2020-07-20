#ifndef SURFACE_MANAGER_H
#define SURFACE_MANAGER_H

#include <vector>
#include <stdexcept>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "Surface.h"

class SurfaceManager {
public:
	void AddSource(std::string text, Font font);
	void AddSurface(std::shared_ptr<Surface> surface);
	std::shared_ptr<Surface> operator[](int i) const;
	int size() { return surfaces_.size(); }
private:
	std::vector<std::shared_ptr<Surface>> surfaces_;
};

#endif
