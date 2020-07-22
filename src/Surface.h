#ifndef SURFACE_H
#define SURFACE_H

#include <string>
#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "Font.h"

//Using SDL2 with smart pointers
//research for using SDL2 and smart pointers combined is from: https://blog.galowicz.de/2016/02/21/automatic_resource_release_with_sdl/

struct SDL_Deleter {
	void operator()(SDL_Window* window) { SDL_DestroyWindow(window); }
	void operator()(SDL_Renderer* renderer) { SDL_DestroyRenderer(renderer); }
	void operator()(SDL_Texture* texture) { SDL_DestroyTexture(texture); }
	void operator()(SDL_Surface* surface) { SDL_FreeSurface(surface); }
	void operator()(TTF_Font* ttfFont) { TTF_CloseFont(ttfFont); }
	void operator()(Mix_Chunk* effect) { Mix_FreeChunk(effect); }
	void operator()(Mix_Music* music) { Mix_FreeMusic(music); }
};

template <typename T>
std::shared_ptr<T> GetSharedPtr(T *t) {
          return std::shared_ptr<T>(t, SDL_Deleter());
}

template <typename T>
std::unique_ptr<T, SDL_Deleter> GetUniquePtr(T* t) {
	return std::unique_ptr<T, SDL_Deleter>(t);
}

class Surface {
public:
	Surface(std::string text, Font font);
	std::shared_ptr<SDL_Surface> GetSDL();
private:
	std::shared_ptr<SDL_Surface> surface_ = nullptr;
};

#endif
