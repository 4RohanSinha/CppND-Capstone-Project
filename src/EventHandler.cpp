#include "EventHandler.h"

bool EventHandler::CheckKeyboardInput(std::vector<KeyCharacter> inputKeys, std::vector<KeyCharacter> listenKeys) {
	bool runFunction = (inputKeys == listenKeys);
	for (int i = 0; i < listenKeys.size(); i++)
		if (listenKeys[i] == KeyCharacter::kAll && inputKeys.size() > 0)
			runFunction = true;

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
