#ifndef SCENE_H
#define SCENE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "Layer.h"

class Scene {
public:
	void Update();
private:
	std::vector<std::shared_ptr<Layer>> layers_;
};

#endif
