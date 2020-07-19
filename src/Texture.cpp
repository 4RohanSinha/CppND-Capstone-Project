#include "Texture.h"

Texture::Texture(std::string imgName, std::shared_ptr<SDL_Renderer> renderer): renderer_(renderer) {
	texture_ = GetSharedPtr(IMG_LoadTexture(renderer_.get(), imgName.c_str()));
}

Texture::Texture(std::shared_ptr<Surface> surface, std::shared_ptr<SDL_Renderer> renderer): renderer_(renderer) {
	texture_ = GetSharedPtr(SDL_CreateTextureFromSurface(renderer_.get(), (surface->GetSDL()).get()));
}

std::shared_ptr<SDL_Texture> Texture::GetSDL() {
	return texture_;
}
