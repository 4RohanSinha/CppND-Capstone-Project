#ifndef SCENE_H
#define SCENE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "rendering/Layer.h"
#include "Node.h"

class Scene {
public:
	Scene();
	void Update();
	void AddLayers(int n);
	void AddToLayer(int layer, std::shared_ptr<Node> node);
	void AddNode(std::shared_ptr<Node> node);
	int GetNumberOfLayers() { return layers_.size(); }
private:
	std::shared_ptr<SDL_Renderer> renderer;
	std::vector<Layer> layers_;
};

#endif
