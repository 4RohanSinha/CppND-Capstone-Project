#include "Scene.h"

Scene::Scene() {

}

void Scene::Update() {
	for (auto i: layers_)
		i.Update();
}

void Scene::AddToLayer(int layer, std::shared_ptr<Node> node) {
	if (layer - 1 >= layers_.size())
		throw std::invalid_argument("Error: node added to layer that is out of bounds.");
	layers_[layer-1].AddNode(node);
}

void Scene::AddLayers(int n) {
	for (int i = 0; i < n; i++)
		layers_.push_back(Layer(renderer));
}

void Scene::AddNode(std::shared_ptr<Node> node) {
	layers_[layers_.size() - 1].AddNode(node);
}
