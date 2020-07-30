#include "SceneManager.h"

std::shared_ptr<Scene> SceneManager::CreateNewScene(std::string identifier) {
	scenes_[identifier] = std::make_shared<Scene>();
	scenes_[identifier]->renderer_ = renderer;
	return scenes_[identifier];
}

void SceneManager::AddScene(std::shared_ptr<Scene> scene, std::string identifier) {
	scene->renderer_ = renderer_;
	scenes_[identifier] = scene;
	currentScene_ = identifier;
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
