#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <SDL2/SDL.h>
#include "Event.h" 

class Controller {
public:
	Controller() {}
	void ListenForUserInput();
	void SendEvent(std::shared_ptr<Event> event) { events_.push(event); }
	//NOTE: if the event happens to be SDL_QUIT, immediately return and quit the program
	std::shared_ptr<Event> ReceiveNextEvent(); //pop the events_ queue and return the popped el

	bool IsRunning();
private:
	std::queue<std::shared_ptr<Event>> events_;
	bool isRunning_{true};
	SDL_Event event;
};

#endif
