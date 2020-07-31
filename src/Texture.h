#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "Surface.h"
#include "Integrate.h"
#include <iostream>

class ReferenceCounter {
public:
	ReferenceCounter() { num_ = 0; }
	void increment() { num_++; }
	void decrement() { num_--; }
	void operator++() { num_++; }
	void operator--() { num_--; }
	void operator++(int) { num_++; }
        void operator--(int) { num_--; }
	unsigned int operator*() { return num_; }
	bool operator==(int num) { return num_ == num; }
	bool operator==(const ReferenceCounter& other) { return num_ == other.num_; }

private:
	unsigned int num_;
};
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
	//integration::unique_ptr_sdl<SDL_Texture> texture_ = nullptr;
	SDL_Texture* texture_ = nullptr;
	ReferenceCounter* ref_count = nullptr;
};

#endif
