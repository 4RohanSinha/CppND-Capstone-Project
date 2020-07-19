#ifndef LAYER_H
#define LAYER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "Node.h"

class Layer {
public:
	Layer() {}
	Layer(std::shared_ptr<SDL_Renderer> renderer); //constructor - takes in a shared ptr to the renderer
	void AddNode(std::shared_ptr<Node> node); //Add node to the vector

	void Update();

	void ClearNode(std::shared_ptr<Node> node);
	
	bool HasNodes();
private:
	std::vector<std::shared_ptr<Node>> nodes_; //allow each node to still be accessed after it is added to the vector
	std::shared_ptr<SDL_Renderer> renderer_; //allow the main renderer from the Renderer class which instantiates the Layer objects to be a shared resource
	//Note: the SDL2 functions rely on raw pointers, so renderer_.get() will have to be used frequently
	std::shared_ptr<SDL_Texture> CreateTextureFromSurface(std::shared_ptr<SDL_Surface> surface);
	void CreateTexturesFromSurfaces(std::shared_ptr<Node> node);
	void AddTextureFromNewSurface(std::shared_ptr<Node> node, std::shared_ptr<SDL_Surface> surface);
	
};

#endif
