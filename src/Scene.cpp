#include "Scene.h"

void Scene::Render(NodeGroup& ngroup) {
	for (int i = 0; i < ngroup.size(); i++) {
		ngroup[i]->AssignRenderer(renderer);
		ngroup[i]->Clear();
		ngroup[i]->ConstructRectangle();
		ngroup[i]->Render();
	}
}

void Scene::Render(std::unique_ptr<Node>& node) {
	node->AssignRenderer(renderer);
	node->Clear();
	node->ConstructRectangle();
	node->Render();
}

void Scene::Render(std::shared_ptr<Node> node) {
        node->AssignRenderer(renderer);
        node->Clear();
        node->ConstructRectangle();
        node->Render();
}

void Scene::Clear() {
	SDL_RenderClear(renderer.get());
}
