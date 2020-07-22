#ifndef INTEGRATE_H
#define INTEGRATE_H 

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <memory>

namespace integration {
	//using custom deleter with std::shared_ptr & std::unique_ptr: https://thispointer.com/shared_ptr-and-custom-deletor/
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
