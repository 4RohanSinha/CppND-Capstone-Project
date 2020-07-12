#ifndef EVENTLISTENER_H
#define EVENTLISTENER_H

#include <SDL2/SDL.h>
#include "Event.h" 
#include "Node.h"

class GameEventListener {
public:
	GameEventListener() {}
	void ListenForUserInput();
	void ListenForNodeEvents();
	void SendEvent(std::shared_ptr<Event> event) { events_.push(event); }
	//NOTE: if the event happens to be SDL_QUIT, immediately return and quit the program
	std::shared_ptr<Event> ReceiveNextEvent(); //pop the events_ queue and return the popped el

private:
	std::queue<std::shared_ptr<Event>> events_;
	SDL_Event event;
	bool isRunning_{true};
};

#endif
