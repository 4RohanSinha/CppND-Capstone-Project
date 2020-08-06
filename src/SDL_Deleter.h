#ifndef SDL_DELETER_H
#define SDL_DELETER_H 

#include "SDL2_headers.h"
#include <memory>


//this is a function object overloaded for various sdl objects
//it is for the custom deleter needed to have smart pointers to SDL objects
//this was used more at the end of the project for only a few classes - majority of the project does not use this
//this was just something new to try out in C++
//using custom deleter with std::shared_ptr & std::unique_ptr: https://thispointer.com/shared_ptr-and-custom-deletor/
//https://blog.galowicz.de/2016/02/21/automatic_resource_release_with_sdl/
struct SDL_Deleter {
	void operator()(SDL_Window* window) { SDL_DestroyWindow(window); }
	void operator()(SDL_Renderer* renderer) { SDL_DestroyRenderer(renderer); }
	void operator()(SDL_Texture* texture) { SDL_DestroyTexture(texture); }
	void operator()(SDL_Surface* surface) { SDL_FreeSurface(surface); }
	void operator()(TTF_Font* ttfFont) { TTF_CloseFont(ttfFont); }
	void operator()(Mix_Chunk* effect) { Mix_FreeChunk(effect); }
	void operator()(Mix_Music* music) { Mix_FreeMusic(music); }

};

#endif
