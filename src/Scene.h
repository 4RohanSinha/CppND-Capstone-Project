#ifndef SCENE_H
#define SCENE_H

#include "SDL2_headers.h"
#include "Node.h"
#include "NodeGroup.h"

class Scene {
public:
	void AddNodeGroup(NodeGroup& ngroup);
	void AddNode(std::shared_ptr<Node> node);
	void AddNodes(std::initializer_list<std::shared_ptr<Node>> nodes);
	void Render();
	void Clear();
private:
	std::vector<std::shared_ptr<Node>> nodes_;
	SDL_Renderer* renderer_;
	friend class SceneManager;
};

#endif
