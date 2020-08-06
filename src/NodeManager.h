#ifndef NODE_MANAGER_H
#define NODE_MANAGER_H

#include "SDL2_headers.h"

class NodeManager {
public:
	NodeManager(): rendererAssigned_(false) {}
	NodeManager(SDL_Renderer* renderer): renderer_(renderer), rendererAssigned_(true) {}
	virtual void Render() = 0;

protected:
	bool rendererAssigned_{false};
	SDL_Renderer* renderer_ = nullptr;
};

#endif
