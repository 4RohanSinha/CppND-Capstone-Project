#include <iostream>
#include "Texture.h"

Texture::Texture(std::string imgName, SDL_Renderer* renderer) {
	texture_ = IMG_LoadTexture(renderer, imgName.c_str());
	ref_count = new ReferenceCounter();
	ref_count->increment();
}

Texture::Texture(Surface surface, SDL_Renderer* renderer) {
	texture_ = SDL_CreateTextureFromSurface(renderer, (surface.GetSDL()).get());
	ref_count = new ReferenceCounter();
	ref_count->increment();
}


Texture::Texture(const Texture& source) {
	texture_ = source.texture_;
	ref_count = source.ref_count;
	if (texture_ != nullptr)
		ref_count->increment();
}

Texture& Texture::operator=(const Texture& source) {
	if (this == &source)
		return *this;

	this->Delete();

	texture_ = source.texture_;
	ref_count = source.ref_count;
	if (texture_ != nullptr)
		ref_count->increment();

	return *this;
}

Texture::Texture(Texture&& source) {
	texture_ = source.texture_;
	ref_count = source.ref_count;
	source.texture_ = nullptr;
	source.ref_count = nullptr;
}

Texture& Texture::operator=(Texture&& source) {
	if (this == &source)
		return *this;

	this->Delete();
	
	texture_ = source.texture_;
	ref_count = source.ref_count;
	source.texture_ = nullptr;
	source.ref_count = nullptr;

	return *this;
}

void Texture::Delete() {
	if (ref_count != nullptr) {
		ref_count->decrement();
		if (**ref_count == 0) {
			delete ref_count;
			SDL_DestroyTexture(texture_);
		}
	}
	ref_count = nullptr;
	texture_ = nullptr;
}

Texture::~Texture() {
	this->Delete();
}
