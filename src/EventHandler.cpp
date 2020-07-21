#include "EventHandler.h"

bool EventHandler::CheckKeyboardInput(std::set<KeyCharacter> inputKeys, std::set<KeyCharacter> listenKeys) {
	bool runFunction = (inputKeys == listenKeys) || (listenKeys.find(KeyCharacter::kAll) != listenKeys.end() && inputKeys.size() > 0);

	return runFunction;
}

void KeyDownEventHandler::Listen() {
	if (CheckKeyboardInput(inputMonitor_->GetPressedKeys(), keys_))
		handlerFunction_();
}

void KeyUpEventHandler::Listen() {
	if (CheckKeyboardInput(inputMonitor_->GetReleasedKeys(), keys_))
		handlerFunction_();
}
