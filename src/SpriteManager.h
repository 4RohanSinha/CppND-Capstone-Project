#ifndef SPRITE_MANAGER_H
#define SPRITE_MANAGER_H

#include <vector>
#include <unordered_map>
#include "SurfaceManager.h"
#include "TextureManager.h"
#include "NodeManager.h"

class SpriteManager: public NodeManager {
public:
	SpriteManager(): NodeManager() {}
	SpriteManager(std::shared_ptr<SDL_Renderer> renderer);
	void AssignCoordinates(int x_val, int y_val, int w_val, int h_val);
	void AssignRenderer(std::shared_ptr<SDL_Renderer> renderer);
	void AddSource(std::string source);
	std::shared_ptr<Texture> GetCurrentTexture();
	std::unordered_map<std::string, Texture> operator[](int i) const;
	void ShowNextSource();
	void ChangeByIndex(int index);
	int CurrentIndex() { return currentForm_; }
	void ConstructRectangle(float x, float y, int w, int h);
	void Render();
	void Clear();
private:
	SDL_Rect rect_;
	//unique ptr used to declare object without initializing it
	std::unique_ptr<TextureManager> textureManager_ = nullptr;
	std::vector<std::string> imageSources_;
	int currentForm_{0};
	bool rendererAssigned_{false};

};

#endif
