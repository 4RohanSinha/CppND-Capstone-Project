#include "Sprite.h"

Sprite::Sprite(std::string mainImage, float x, float y): Node(x, y) {
	imageSources_.push_back(mainImage);
	rendererSetDimensions_ = false;
	currentForm_ = 0;
	collisionBitMask = "Sprite";
}

Sprite::Sprite(std::string mainImage, float x, float y, int width, int height): Node(x, y, width, height) {
	imageSources_.push_back(mainImage);
	rendererSetDimensions_ = false;
	currentForm_ = 0;
	collisionBitMask = "Sprite";
	
}

void Sprite::CreateSurface(int i) {
	surface_ = GetSharedPtr(IMG_Load(imageSources_[i].c_str()));
	surfaces_.push_back(surface_);
}

void Sprite::GenerateSurfacesFromSources() {
	int i = 0;
	while (i < imageSources_.size()) {
		CreateSurface(i);
		i++;
	}
}

void Sprite::SetImage(int imageIndex) {
	if (imageIndex >= imageSources_.size())
		throw std::invalid_argument("Error: Sprite::SetImage(int imageIndex): imageIndex is greater than the number of image sources provided. Aborting...");
	else {
		currentForm_ = imageIndex;
	}
}

void Sprite::NextImage() {
}

void Sprite::ChangeImage() {
		
}

void Sprite::AnimateSize(int newWidth, int newHeight) {}

void Sprite::AddImage(std::string img) {
	if (CheckImageSource(img)) {
		imageSources_.push_back(img);
		surface_ = GetSharedPtr(IMG_Load(img.c_str()));
		newSurfaces_.push(surface_);
		status_ = TextureRender::kRenderNow;
		currentForm_ = imageSources_.size() - 1;
	}
	else
		throw std::invalid_argument("Error: the image file " + img + " does not exist!");
}

bool Sprite::CheckImageSource(std::string src) {
	std::ifstream filestream(src);

	if (filestream.is_open())
		return true;
	return false;
}
