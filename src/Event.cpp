#include "Event.h"

//using variable arguments: http://www.cplusplus.com/reference/cstdarg/va_list/
Event::Event(EventType event, int num, ...) {
	va_list nodesInvolved;
	
	va_start(nodesInvolved, num);

	for (int i = 0; i < num; i++) {
		nodesInvolved_.push_back(va_arg(nodesInvolved, std::shared_ptr<Node>));
	}

	va_end(nodesInvolved);
}

bool Event::operator==(const Event& otherEvent) const {
	if (event_ != otherEvent.event_)
		return false;
	else if (keyChar_ != otherEvent.keyChar_ && (keyChar_ != KeyCharacter::kAll && otherEvent.keyChar_ != KeyCharacter::kAll))
		return false;
	else if (coordinates_.size() != otherEvent.coordinates_.size())
		return false;
	else if (nodesInvolved_.size() != otherEvent.nodesInvolved_.size())
		return false;
	
	for (int i = 0; i < coordinates_.size(); i++) {
		if (coordinates_[i] != otherEvent.coordinates_[i])
			return false;
	}

	for (int i = 0; i < nodesInvolved_.size(); i++) {
		if (nodesInvolved_[i] != otherEvent.nodesInvolved_[i])
			return false;
	}

	
	return true;
}

bool Event::operator!=(const Event& otherEvent) const {
	return !(*this == otherEvent);
}
