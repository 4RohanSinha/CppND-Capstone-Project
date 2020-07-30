#include "Controller.h"
#include <iostream>

void Controller::ListenUpdate() {
	for (auto& i: eventHandlers_)
		i->Listen(inputMonitor_);
}

void Controller::Update() {
	inputMonitor_.Update();
	ListenUpdate();
}
