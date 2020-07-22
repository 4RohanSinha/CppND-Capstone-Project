#include "Sprite.h"

Sprite::Sprite(std::string mainImage, float x, float y): Node(x, y) {
	rendererSetDimensions_ = false;
	collisionBitMask = "Sprite";
	spriteManager_.AddSource(mainImage);
	spriteManager_.AssignCoordinates(x, y, 100, 100);
	useNewExperiment = true;
}

Sprite::Sprite(std::string mainImage, float x, float y, int width, int height): Node(x, y, width, height) {
	rendererSetDimensions_ = false;
	collisionBitMask = "Sprite";
	spriteManager_.AddSource(mainImage);
	spriteManager_.AssignCoordinates(x, y, width, height);
	useNewExperiment = true;
	
}

void Sprite::SetImage(int imageIndex) {
	spriteManager_.ChangeByIndex(imageIndex);
}

void Sprite::NextImage() {
	spriteManager_.ShowNextSource();
}

void Sprite::AddImage(std::string img) {
	if (CheckImageSource(img)) {
		spriteManager_.AddSource(img);
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

void Sprite::AssignRenderer(std::shared_ptr<SDL_Renderer> renderer) {
	spriteManager_.AssignRenderer(renderer);
}

void Sprite::Render() {
	spriteManager_.Render();
}

void Sprite::Clear() {
	spriteManager_.Clear();
}
