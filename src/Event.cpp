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
