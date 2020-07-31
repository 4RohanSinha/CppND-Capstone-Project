#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "Texture.h"
#include "SurfaceManager.h"

class TextureManager {
public:
	TextureManager() {}
	TextureManager(SDL_Renderer* renderer, SurfaceManager surfaceManager);
	void AddSource(std::string imgName, SDL_Renderer* renderer);
	void AddSource(Surface surface, SDL_Renderer* renderer);
	void AddTexture(Texture texture);
	Texture& operator[](int i);
	int size() { return textures_.size(); }
private:
	std::vector<Texture> textures_;
	std::shared_ptr<SDL_Renderer> renderer_ = nullptr;
};

#endif
