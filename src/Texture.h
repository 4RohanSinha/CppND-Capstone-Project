#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "Surface.h"

class Texture {
public:
	Texture(std::string imgName, std::shared_ptr<SDL_Renderer> renderer);
	Texture(std::shared_ptr<Surface> surface, std::shared_ptr<SDL_Renderer> renderer);
	std::shared_ptr<SDL_Texture> GetSDL();
private:
	std::shared_ptr<SDL_Texture> texture_ = nullptr;
	std::shared_ptr<SDL_Renderer> renderer_ = nullptr;
};

#endif
