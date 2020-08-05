#include "Scene.h"

void Scene::AddNodeGroup(NodeGroup& ngroup) {
	for (int i = 0; i < ngroup.size(); i++) {
		ngroup[i]->AssignRenderer(renderer_);
		ngroup[i]->Update();
		ngroup[i]->ConstructRectangle();
		ngroup[i]->Render();
		nodes_.push_back(ngroup[i]);
	}
}

void Scene::AddNode(std::shared_ptr<Node> node) {
	nodes_.push_back(node);
	node->AssignRenderer(renderer_);
	node->Update();
	node->ConstructRectangle();
	node->Render();
}

void Scene::AddNodes(std::initializer_list<std::shared_ptr<Node>> nodes) {
	for (auto& i: nodes) {
		i->AssignRenderer(renderer_);
		i->Update();
		i->ConstructRectangle();
		i->Render();
		nodes_.push_back(i);
	}
}

void Scene::Render() {
	Clear();
	if (renderer_ == nullptr)
		throw std::runtime_error("Error: Scene::Render(): renderer not assigned in scene. Maybe the scene has not been added to the scene manager?");
	for (int i = 0; i < nodes_.size(); i++) {
        	nodes_[i]->Clear();
		nodes_[i]->Update();
        	nodes_[i]->ConstructRectangle();
        	nodes_[i]->Render();
	}
	SDL_RenderPresent(renderer_);
}

void Scene::Clear() {
	if (renderer_ == nullptr)
		throw std::runtime_error("Error: Scene::Clear(): renderer not assigned in scene. Maybe the scene has not been added to the scene manager?");
	SDL_RenderClear(renderer_);
}
