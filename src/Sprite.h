#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "Node.h"
#include "SpriteManager.h"

class Sprite: public Node {
public:
	Sprite(std::string mainImage, float x, float y);
	
	Sprite(std::string mainImage, float x, float y, int width, int height);

	void NextImage();

	void SetImage(int imageIndex);

	void AddImage(std::string img);

	int GetCurrentImageIndex() { return spriteManager_.CurrentIndex(); }

	std::string GetImageSourceAt(int index) { return spriteManager_[index].begin()->first; }
	std::string GetCurrentImage() { return GetImageSourceAt(GetCurrentImageIndex()); }

	static bool CheckImageSource(std::string src);

	void ConstructRectangle() { spriteManager_.ConstructRectangle(x, y, width_, height_); }

	void AssignRenderer(std::shared_ptr<SDL_Renderer> renderer);

	void Render();

	void Clear();

protected:
	float speed{2.0};
	float angle;
	std::vector<float> velocity{0, 0};
private:
	SpriteManager spriteManager_;
};

#endif
