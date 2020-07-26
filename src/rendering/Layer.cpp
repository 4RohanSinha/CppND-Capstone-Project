#include "Layer.h"
#include <algorithm>
#include <iostream>

Layer::Layer(std::shared_ptr<SDL_Renderer> renderer) {
	renderer_ = renderer;
}

void Layer::AddNode(std::shared_ptr<Node> node) {
	node->AssignRenderer(renderer_);
	node->ConstructRectangle();
	node->Render();
	nodes_.push_back(node);
	return;
}

//TODO: transition entirely to new rendering system based on the NodeManager
//work on the TextManager class
void Layer::Update() {
	if (renderer_ == nullptr)
		return;
	//TODO: fix renderer_; there are 16 copies produced of the shared ptr
	for (auto i: nodes_) {

		if (i->isHidden_ == false && i != nullptr) {
			int n = 1; //number of times to render the texture - this may need to be increased for the texture to be clearly visible

			//IMPORTANT NOTE: this boolean is a tmp variable that will be removed after the TODO above is complete
			if (i->textureSurface_) {
				i->Clear();
				i->ConstructRectangle();
				i->Render();
			}

			else if (!i->textureSurface_) {

				SDL_SetRenderDrawColor(renderer_.get(), i->GetColor().GetRed(), i->GetColor().GetGreen(), i->GetColor().GetBlue(), i->GetColor().GetAlpha());
				std::for_each(i->points_.begin(), i->points_.end(), [i](SDL_Point& a) { 
						
				});
				SDL_RenderDrawPoints(renderer_.get(), i->points_.data(), i->points_.size());
				SDL_SetRenderDrawColor(renderer_.get(), 0, 0, 0, 0);
				i->ConstructRectangle();
			}
		}
	}

	SDL_RenderPresent(renderer_.get());
}

bool Layer::HasNodes() {
	return (nodes_.size() > 0);
}

//TODO: transparent backgrounds
void Layer::ClearNode(std::shared_ptr<Node> node) {
}
