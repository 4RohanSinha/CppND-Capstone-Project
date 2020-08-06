#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <memory>
#include "SDL2_headers.h"
#include "Surface.h"
#include "ReferenceCounter.h"
#include <iostream>

class Texture {
public:
	Texture(std::string imgName, SDL_Renderer* renderer);
	Texture(Surface surface, SDL_Renderer* renderer);
	Texture(const Texture& source);
	Texture& operator=(const Texture& source);
	Texture(Texture&& source);
	Texture& operator=(Texture&& source);
	SDL_Texture* get() { return texture_; }
	int reference_count() { return **ref_count; }
	void Delete();
	~Texture();
private:
	SDL_Texture* texture_ = nullptr;
	ReferenceCounter* ref_count = nullptr;
};

#endif
