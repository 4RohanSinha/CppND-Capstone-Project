#include "Sprite.h"

Sprite::Sprite(std::string mainImage, float x, float y): Node(x, y) {
	imageSources_.push_back(mainImage);
	rendererSetDimensions_ = false;
	currentForm_ = 0;
	CreateSurface();
}

Sprite::Sprite(std::string mainImage, float x, float y, int width, int height): Node(x, y, width, height) {
	imageSources_.push_back(mainImage);
	rendererSetDimensions_ = false;
	currentForm_ = 0;
	CreateSurface();
}

void Sprite::CreateSurface() {
	surface_ = GetSharedPtr(IMG_Load(imageSources_[currentForm_].c_str()));
}

void Sprite::NextImage() {

}

void Sprite::ChangeElement() {
		
}

void Sprite::ChangeImage() {

}

void Sprite::AnimateSize(int newWidth, int newHeight) {}

void Sprite::AddImage(std::string img) {
	if (CheckImageSource(img))
		imageSources_.push_back(img);
	else
		throw std::invalid_argument("Error: the image file " + img + " does not exist!");
}

bool Sprite::CheckImageSource(std::string src) {
	std::ifstream filestream(src);

	if (filestream.is_open())
		return true;
	return false;
}
