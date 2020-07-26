#include "SceneManager.h"

void SceneManager::AddScene(Scene& scene, std::string identifier) {
	scenes_[identifier] = scene;
}

void SceneManager::ShowScene(std::string identifier) {
	scenes_[currentScene_].Clear();
	currentScene_ = identifier;
	//TODO: Render scene
}

void SceneManager::DeleteScene(std::string identifier) {
	scenes_.erase(identifier);
}
