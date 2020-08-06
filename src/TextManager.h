#ifndef TEXT_MANAGER_H
#define TEXT_MANAGER_H

#include "SurfaceManager.h"
#include "TextureManager.h"
#include "NodeManager.h"
#include "Font.h"

class TextManager: public NodeManager {
public:
	TextManager(): NodeManager() {}
	TextManager(SDL_Renderer* renderer);
	void AssignCoordinates(int x_val, int y_val);
	void AssignRenderer(SDL_Renderer* renderer);
	void AddSource(std::string source);
	void AddFont(Font font);
	void ShowNextSource();
	void ChangeByIndex(int index);
	int CurrentIndex() { return currentForm_; }
	void ConstructRectangle(float x, float y);
	void Render();
	void Clear();
private:
	SDL_Rect rect_;
	SurfaceManager surfaceManager_;
	std::unique_ptr<TextureManager> textureManager_ = nullptr;
	std::vector<std::string> textSources_;
	std::vector<Font> fonts_;
	int currentForm_{0};
	bool rendererAssigned_{false};
};

#endif
