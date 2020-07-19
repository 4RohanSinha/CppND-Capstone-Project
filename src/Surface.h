#ifndef SURFACE_H
#define SURFACE_H

#include <string>
#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "Font.h"

//Using SDL2 with smart pointers
//research for using SDL2 and smart pointers combined is from: https://blog.galowicz.de/2016/02/21/automatic_resource_release_with_sdl/
static void SDL_DelObject(SDL_Window* window) {SDL_DestroyWindow(window);}
static void SDL_DelObject(SDL_Renderer* renderer) {SDL_DestroyRenderer(renderer);}
static void SDL_DelObject(SDL_Texture* texture) {SDL_DestroyTexture(texture);}
static void SDL_DelObject(SDL_Surface* surface) {SDL_FreeSurface(surface);}
static void SDL_DelObject(TTF_Font* ttfFont) { if (ttfFont != NULL && ttfFont != nullptr) TTF_CloseFont(ttfFont); }

template <typename T>
std::shared_ptr<T> GetSharedPtr(T *t) {
        //TODO: see if function pointer can be passed in instead
        return std::shared_ptr<T>(t, [](T* t) { SDL_DelObject(t); });
}

class Surface {
public:
	Surface(std::string text, Font font);
	std::shared_ptr<SDL_Surface> GetSDL();
private:
	std::shared_ptr<SDL_Surface> surface_ = nullptr;
};

#endif
