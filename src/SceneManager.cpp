#include "SceneManager.h"

Scene* SceneManager::CreateNewScene(std::string identifier) {
	scenes_[identifier] = std::make_unique<Scene>();
	scenes_[identifier]->renderer_ = renderer_;
	currentScene_ = identifier;
	return scenes_[identifier].get();
}

Scene* SceneManager::get(std::string identifier) {
	return scenes_[identifier].get();
}

Scene& SceneManager::getRef(std::string identifier) {
	return *(scenes_[identifier]);
}

void SceneManager::ShowScene(std::string identifier) {
	scenes_[currentScene_]->Clear();
	currentScene_ = identifier;
	scenes_[currentScene_]->Render();
}

void SceneManager::RenderCurrentScene() {
	scenes_[currentScene_]->Render();
}

void SceneManager::DeleteScene(std::string identifier) {
	scenes_.erase(identifier);
}
