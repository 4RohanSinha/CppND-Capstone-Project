#include "EventHandler.h"

void KeyDownEventHandler::Listen(Input& inputMonitor) {
	bool callFunction = true;
	for (auto& i: keys_) {
		if (inputMonitor.GetStatusOfKey(i) != KeyStatus::keyPressed)
			callFunction = false;
		else if (i == KeyCharacter::kAll) {
			callFunction = true;
			break;
		}
	}

	if (callFunction)
		handlerFunction_();
}

void KeyUpEventHandler::Listen(Input& inputMonitor) {
	bool callFunction = true;
	for (auto& i: keys_) {
		if (inputMonitor.GetStatusOfKey(i) != KeyStatus::keyReleased)
			callFunction = false;
		else if (i == KeyCharacter::kAll) {
			callFunction = true;
			break;
		}
	}

	if (callFunction)
		handlerFunction_();
}
