#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "Surface.h"
#include "Integrate.h"

class Texture {
public:
	Texture(std::string imgName, std::shared_ptr<SDL_Renderer> renderer);
	Texture(Surface surface, std::shared_ptr<SDL_Renderer> renderer);
private:
	//integration::unique_ptr_sdl<T> is an alias for std::unique_ptr<T, SDL_Deleter>, which has a custom deleter (the function object SDL_Deleter)
	//see Integrate.h for more details
	integration::unique_ptr_sdl<SDL_Texture> texture_ = nullptr;
	std::shared_ptr<SDL_Renderer> renderer_ = nullptr;

	//allow SpriteManager to directly access texture_
	//this prevents the need for copying and using std::shared_ptr
	friend class SpriteManager;
	friend class TextManager;
};

#endif
