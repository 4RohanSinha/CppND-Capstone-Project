#ifndef TEXT_MANAGER_H
#define TEXT_MANAGER_H

#include "SurfaceManager.h"
#include "TextureManager.h"

class TextManager {
public:
	/*
	TextManager(std::shared_ptr<SDL_Renderer> renderer);
	void AssignRenderer(std::shared_ptr<SDL_Renderer> renderer);
	void AddText(std::string text, Font font);
	std::shared_ptr<Surface> GetCurrentSurface();
	std::shared_ptr<Texture> GetCurrentTexture();
	std::shared_ptr<Surface> GetSurfaceAtIndex(int i) const;
	std::shared_ptr<Texture> operator[](int i) const;
	void ShowNextText();
	void ChangeByIndex(int index);
	int CurrentIndex() const { return currentForm_; }
private:
	std::shared_ptr<SDL_Renderer> renderer_ = nullptr;
	std::shared_ptr<SurfaceManager> surfaceManager_ = nullptr;
	std::unique_ptr<TextureManager> textureManager_ = nullptr;
	int currentForm_;
	bool rendererAssigned_{false};
	*/
};

#endif
