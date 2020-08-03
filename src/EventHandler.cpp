#include "EventHandler.h"

bool EventHandler::CheckKeyboardInput(std::set<KeyCharacter> inputKeys, std::set<KeyCharacter> listenKeys) {

	//check if listenKeys (the keys to listen for) are a subset of inputKeys (the keys the user is pressing)
	//inspired from: https://stackoverflow.com/questions/48299390/check-if-unordered-set-contains-all-elements-in-other-unordered-set-c
	return (listenKeys.size() <= inputKeys.size() && (std::all_of(listenKeys.begin(), listenKeys.end(), [&inputKeys](auto const& element) { return inputKeys.find(element) != inputKeys.end(); }) || (listenKeys.find(KeyCharacter::kAll) != listenKeys.end() && inputKeys.size() > 0)));
}

void KeyDownEventHandler::Listen(Input& inputMonitor) {
	if (CheckKeyboardInput(inputMonitor.GetPressedKeys(), keys_))
		handlerFunction_();
}

void KeyUpEventHandler::Listen(Input& inputMonitor) {
	if (CheckKeyboardInput(inputMonitor.GetReleasedKeys(), keys_))
		handlerFunction_();
}
