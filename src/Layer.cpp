#include "Layer.h"
#include <algorithm>
#include <iostream>

Layer::Layer(std::shared_ptr<SDL_Renderer> renderer) {
	renderer_ = renderer;
}

void Layer::AddNode(std::shared_ptr<Node> node) {
	if (node->useNewExperiment) {
		node->AssignRenderer(renderer_);
		node->ConstructRectangle();
		node->Render();
		nodes_.push_back(node);
		return;
	}

	if (node->textureSurface_) {
		node->GenerateSurfacesFromSources();
		CreateTexturesFromSurfaces(node);
		if (node->rendererSetDimensions_)
			SDL_QueryTexture((node->textures_[node->currentForm_]).get(), NULL, NULL, &node->width_, &node->height_);
	}
	
	node->ConstructRectangle();
	nodes_.push_back(node);
	
}


std::shared_ptr<SDL_Texture> Layer::CreateTextureFromSurface(std::shared_ptr<SDL_Surface> surface) {
	if ((surface != nullptr && renderer_ != nullptr) && (surface != NULL && renderer_ != NULL))
		return GetSharedPtr(SDL_CreateTextureFromSurface(renderer_.get(), surface.get()));	
	else
		throw std::runtime_error("Fatal Error: Layer::CreateTextureFromSurface(std::shared_ptr<SDL_Surface> surface): nullptr in either surface or renderer_ argument");
}

void Layer::CreateTexturesFromSurfaces(std::shared_ptr<Node> node) {
	for (auto i: node->surfaces_) {
		node->textures_.push_back(CreateTextureFromSurface(i));
	}
}

void Layer::AddTextureFromNewSurface(std::shared_ptr<Node> node, std::shared_ptr<SDL_Surface> surface) {
	if (node->textures_.size() == node->surfaces_.size()) {
		node->surfaces_.push_back(surface);
	} else if (node->textures_.size() > node->surfaces_.size()) {
		throw std::runtime_error("Runtime Error: the number of textures is greater than the number of surfaces for a node. Unable to proceed.");
	}
	//no if statement if the number of surfaces is greater than the number of textures because that may imply that the user has already added the surface
	node->textures_.push_back(CreateTextureFromSurface(surface));
}

//TODO: transition entirely to new rendering system based on the NodeManager
//work on the TextManager class
void Layer::Update() {
	if (renderer_ == nullptr)
		return;
	for (auto i: nodes_) {

		if (i->isHidden_ == false && i != nullptr) {
			int n = 1; //number of times to render the texture - this may need to be increased for the texture to be clearly visible

			//IMPORTANT NOTE: this boolean is a tmp variable that will be removed after the TODO above is complete
			if (i->useNewExperiment) {
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

			else {
				if (!((i->animations_).empty())) {
					ClearNode(i);
					auto curAnimation = (i->animations_).front();
					curAnimation->SetStartPosition(std::vector<float>{i->x, i->y});
					if (curAnimation->HasReachedDestination()) {
						(i->animations_).pop_front();
					} else {
						auto nextPoint = curAnimation->GetNextPosition();
						if (nextPoint.size() == 5) {
							for (auto j: curAnimation->GetType()) {
								if (j == Animation::AnimationType::kMove) {
									i->x = nextPoint[0];
									i->y = nextPoint[1];
								}
								
								if (j == Animation::AnimationType::kSize) {
									i->width_ = (int) (nextPoint[2]);
									i->height_ = (int) (nextPoint[3]);
								}
							}
						}
					}

					i->AnimationChange();
					i->ConstructRectangle();
				}	
		
				if (i->status_ == TextureRender::kRenderNow) {
					ClearNode(i);
					if (i->newSurfaces_.size() > 0) {
						AddTextureFromNewSurface(i, i->newSurfaces_.front());
						i->newSurfaces_.pop();
					}
					i->status_ = TextureRender::kNoRender;
				}

				if (i->status_ == TextureRender::kClear) {
					ClearNode(i);
					i->status_ = TextureRender::kNoRender;
				}

				ClearNode(i);
				i->ConstructRectangle();


				if (i->rendererSetDimensions_) {
					SDL_QueryTexture((i->textures_[i->currentForm_]).get(), NULL, NULL, &i->width_, &i->height_);
					n = 7;

				}

				for (int k = 0; k < n; k++) {
					SDL_RenderCopy(renderer_.get(), (i->textures_[i->currentForm_]).get(), NULL, (i->rect_).get());
				}
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
	SDL_SetRenderTarget(renderer_.get(), (node->texture_).get());
	SDL_RenderFillRect(renderer_.get(), (node->rect_).get());
}
