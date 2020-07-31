#ifndef SCENE_H
#define SCENE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "Node.h"
#include "NodeGroup.h"

class Scene {
public:
	void AddNodeGroup(NodeGroup& ngroup);
	void AddNode(std::shared_ptr<Node> node);
	void Render();
	void Clear();
private:
	std::vector<std::shared_ptr<Node>> nodes_;
//	std::shared_ptr<SDL_Renderer> renderer_;
	SDL_Renderer* renderer_;
	friend class SceneManager;
};

#endif
