#include "Controller.h"
#include <iostream>

void Controller::CollisionUpdate() {
	for (auto& i: collideDetect) {
		i->CheckForCollisions();
	}
}

void Controller::ListenUpdate() {
	for (auto& i: eventHandlers_)
		i->Listen();
}

void Controller::Update() {
	inputMonitor_->Update();
	ListenUpdate();
	CollisionUpdate();
}
