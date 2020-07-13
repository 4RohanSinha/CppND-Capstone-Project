#include <SDL2/SDL.h>
#include <iostream>
#include "GameEventListener.h"

void GameEventListener::ListenForEvent() {
	auto e = inputMonitor_->GetUserEvent();
	if (e == event_) {
		handlerFunction_();
	}
}
