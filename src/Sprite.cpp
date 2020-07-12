#include "Sprite.h"

Sprite::Sprite(std::string mainImage, float x, float y): Node(x, y) {
	imageSources_.push_back(mainImage);
	rendererSetDimensions_ = false;
	currentForm_ = 0;
	CreateSurface();
	collisionBitMask = "Sprite";
}

Sprite::Sprite(std::string mainImage, float x, float y, int width, int height): Node(x, y, width, height) {
	imageSources_.push_back(mainImage);
	rendererSetDimensions_ = false;
	currentForm_ = 0;
	CreateSurface();
	collisionBitMask = "Sprite";
	
}

void Sprite::CreateSurface() {
	surface_ = GetSharedPtr(IMG_Load(imageSources_[currentForm_].c_str()));
}


void Sprite::NextImage() {
	if (currentForm_ + 1 < imageSources_.size())
		currentForm_++;
	status_ = TextureRender::kRenderNow;
}

void Sprite::ChangeImage() {
		
}

void Sprite::AnimationChange() {
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
