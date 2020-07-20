#ifndef SPRITE_MANAGER_H
#define SPRITE_MANAGER_H

#include <vector>
#include <unordered_map>
#include "SurfaceManager.h"
#include "TextureManager.h"

class SpriteManager {
public:
	SpriteManager(): rendererAssigned_(false) {}
	SpriteManager(std::shared_ptr<SDL_Renderer> renderer);
	void AssignRenderer(std::shared_ptr<SDL_Renderer> renderer);
	void AddImageSource(std::string imageSource);
	std::shared_ptr<Texture> GetCurrentTexture();
	std::unordered_map<std::string, std::shared_ptr<Texture>> operator[](int i) const;
	void ShowNextImage();
	void ChangeByIndex(int index);
	int CurrentIndex() { return currentForm_; }
private:
	std::shared_ptr<SDL_Renderer> renderer_ = nullptr;
	std::shared_ptr<SDL_Rect> rect_ = nullptr;
	std::unique_ptr<TextureManager> textureManager_ = nullptr;
	std::vector<std::string> imageSources_;
	int currentForm_;
	bool rendererAssigned_{false};

};

#endif
