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

class Sprite: public Node {
public:
	Sprite(std::string mainImage, float x, float y);
	
	Sprite(std::string mainImage, float x, float y, int width, int height);

	void NextImage();

	void ChangeImage();

	void AnimateSize(int newWidth, int newHeight);

	void SetImage(int imageIndex);

	void AddImage(std::string img);

	std::string GetCurrentImage() { return imageSources_[currentForm_]; }

	int GetCurrentImageIndex() { return currentForm_; }

	std::string GetImageSourceAt(int index) { return imageSources_[index]; }

	int NumberImages() { return imageSources_.size(); }

	static bool CheckImageSource(std::string src);

protected:

	void CreateSurface(int i);

	void GenerateSurfacesFromSources();

private:
	std::vector<std::string> imageSources_;
	bool executeFunction_{false};
};

#endif
