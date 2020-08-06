#ifndef INTEGRATE_H
#define INTEGRATE_H 

#include "SDL2_headers.h"
#include <memory>

//this file allows for better integration of the SDL2 library into C++
//SDL2 was written in C so it relies on raw pointers
//one part of the namespace below involves functions to create smart pointers with the SDL Deleters
namespace integration {
	//using custom deleter with std::shared_ptr & std::unique_ptr: https://thispointer.com/shared_ptr-and-custom-deletor/
	//https://blog.galowicz.de/2016/02/21/automatic_resource_release_with_sdl/
	//a function object as a custom deleter for shared pointers to various SDL2 objects

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
	std::shared_ptr<T> create_shared(T* t) {
		return std::shared_ptr<T>(t, SDL_Deleter());
	}

	template <typename T>
	std::unique_ptr<T, SDL_Deleter> create_unique(T* t) {
		return std::unique_ptr<T, SDL_Deleter>(t);
	}

	template<typename T>
	using unique_ptr_sdl = std::unique_ptr<T, SDL_Deleter>;
};

#endif
