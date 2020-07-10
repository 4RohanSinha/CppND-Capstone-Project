#include "Layer.h"
#include <iostream>

Layer::Layer(std::shared_ptr<SDL_Renderer> renderer) {
	renderer_ = renderer;
}

void Layer::AddNode(std::shared_ptr<Node> node) {
	node->CreateSurface();
	node->CreateTexture(renderer_);
	if (node->rendererSetDimensions_)
		SDL_QueryTexture((node->texture_).get(), NULL, NULL, &node->width_, &node->height_);
	node->ConstructRectangle();
	nodes_.push_back(node);
	
}


void Layer::Update() {
	if (renderer_ == nullptr)
		return;
	for (auto i: nodes_) {
		
		if (i->isHidden_ == false && i != nullptr) {
			int n = 1; //number of times to render the texture - this may need to be increased for the texture to be clearly visible

			if (i->rendererSetDimensions_) {
				SDL_QueryTexture((i->texture_).get(), NULL, NULL, &i->width_, &i->height_);
				n = 7;

			}

			if (!((i->moveAnimates_).empty())) {
				ClearNode(i);
				auto curAnimation = (i->moveAnimates_).front();
				curAnimation->SetStartCoordinates(i->x_, i->y_);
				if (curAnimation->HasReachedDestination()) {
					(i->moveAnimates_).pop();
					i->status_ = TextureRender::kRenderNow;
				} else {
					auto nextPoint = curAnimation->GetNextPoint();
					if (nextPoint.size() == 2) {
						i->x_ = nextPoint[0];
						i->y_ = nextPoint[1];
					}
				}
			}	
			if (i->status_ == TextureRender::kRenderNow) {
				ClearNode(i);
				i->CreateSurface();
				i->CreateTexture(renderer_);
				i->status_ = TextureRender::kNoRender;
			}

			if (i->status_ == TextureRender::kRenderForever) {
				ClearNode(i);
				i->CreateSurface();
				i->CreateTexture(renderer_);
			}
			i->ConstructRectangle();

			for (int k = 0; k < n; k++) {
				SDL_RenderCopy(renderer_.get(), (i->texture_).get(), NULL, (i->rect_).get());
			}

		}
	}

	SDL_RenderPresent(renderer_.get());
}

bool Layer::HasNodes() {
	return (nodes_.size() > 0);
}

void Layer::ClearNode(std::shared_ptr<Node> node) {
	SDL_SetRenderTarget(renderer_.get(), (node->texture_).get());
	SDL_RenderFillRect(renderer_.get(), (node->rect_).get());
}
