#include "Controller.h"
#include <iostream>

Controller::Controller(std::shared_ptr<std::vector<std::shared_ptr<Node>>> nodes) {
	nodes_ = nodes;
	inputListeners.push_back(std::make_shared<GameEventListener>(Event(EventType::kQuit), [] () {}, inputMonitor_));
}

void Controller::CollisionUpdate() {
	for (auto i: collideDetect) {
		i->CheckForCollisions();
	}
}

void Controller::ListenUpdate() {
	for (auto i: inputListeners) {
		i->ListenForEvent();
	}
}

void Controller::Update() {
	inputMonitor_->Update();
	ListenUpdate();
	CollisionUpdate();
}
