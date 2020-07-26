#ifndef SCENE_H
#define SCENE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "rendering/Layer.h"
#include "Node.h"
#include "NodeGroup.h"

class Scene {
public:
	void Render(NodeGroup& ngroup);
	void Render(std::unique_ptr<Node>& node); //experimental
	void Render(std::shared_ptr<Node> node);
	void Clear();
private:
	std::shared_ptr<SDL_Renderer> renderer;
};

#endif
