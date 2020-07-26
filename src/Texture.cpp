#include <iostream>
#include "Texture.h"

Texture::Texture(std::string imgName, std::shared_ptr<SDL_Renderer> renderer): renderer_(renderer) {
	texture_ = integration::create_unique(IMG_LoadTexture(renderer_.get(), imgName.c_str()));
}

Texture::Texture(Surface surface, std::shared_ptr<SDL_Renderer> renderer): renderer_(renderer) {
	texture_ = integration::create_unique(SDL_CreateTextureFromSurface(renderer_.get(), (surface.GetSDL()).get()));
}
