#include "EventHandler.h"

bool EventHandler::CheckKeyboardInput(std::set<KeyCharacter> inputKeys, std::set<KeyCharacter> listenKeys) {
	bool runFunction = (inputKeys == listenKeys) || (listenKeys.find(KeyCharacter::kAll) != listenKeys.end() && inputKeys.size() > 0);

	return runFunction;
}

void KeyDownEventHandler::Listen(Input& inputMonitor) {
	if (CheckKeyboardInput(inputMonitor.GetPressedKeys(), keys_))
		handlerFunction_();
}

void KeyUpEventHandler::Listen(Input& inputMonitor) {
	if (CheckKeyboardInput(inputMonitor.GetReleasedKeys(), keys_))
		handlerFunction_();
}
