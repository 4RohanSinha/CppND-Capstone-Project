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
	TextureManager(std::shared_ptr<SDL_Renderer> renderer): renderer_(renderer) {}
	//TODO: implement constructor for following method
	TextureManager(std::shared_ptr<SDL_Renderer> renderer, std::shared_ptr<SurfaceManager> surfaceManager);
	void AddSource(std::string imgName);
	void AddSource(std::shared_ptr<Surface> surface);
	void AddTexture(std::shared_ptr<Texture> texture);
	std::shared_ptr<Texture> GetCurrentTexture();
	std::shared_ptr<Texture> operator[](int i) const;
	void RenderNextTexture();
	void RenderTextureByIndex(int index);
	int size() { return textures_.size(); }
private:
	std::vector<std::shared_ptr<Texture>> textures_;
	int currentIndex_;
	std::shared_ptr<SDL_Renderer> renderer_ = nullptr;
};

#endif
