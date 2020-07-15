#ifndef GAMEEVENTLISTENER_H
#define GAMEEVENTLISTENER_H

#include <SDL2/SDL.h>
#include "Event.h"
#include "Node.h"
#include "Input.h"

class GameEventListener {
public:
	template <typename T>
	GameEventListener(Event event, T handlerFunction, std::shared_ptr<Input> inputMonitor): event_(event), handlerFunction_(handlerFunction), inputMonitor_(inputMonitor) {}
	void ListenForEvent();

	//NOTE: if the event happens to be SDL_QUIT, immediately return and quit the program

private:
	Event event_ = Event(EventType::kNone);
	
	//usage of std::function from https://en.cppreference.com/w/cpp/utility/functional/function
	std::function<void()> handlerFunction_;
	std::shared_ptr<Input> inputMonitor_ = nullptr;
};

#endif
