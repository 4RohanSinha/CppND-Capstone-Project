#ifndef SURFACE_H
#define SURFACE_H

#include <string>
#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "Font.h"
#include "Integrate.h"

class Surface {
public:
	Surface(std::string text, Font font);
	std::shared_ptr<SDL_Surface> GetSDL();
private:
	std::shared_ptr<SDL_Surface> surface_ = nullptr;
};

#endif
