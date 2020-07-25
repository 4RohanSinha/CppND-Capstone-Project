#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include <SDL2/SDL.h>
#include <initializer_list>
#include <set>
#include <functional>
#include <memory>
#include "Keyboard.h"
#include "Input.h"

//TODO: allow multiple different kinds of events at one event handler
enum class EventType {
        kCollision,
        kUpKey,
        kDownKey,
        kTapDown,
        kTapUp,
        kSwipe,
        kClick,
        kQuit,
        kNone
};

class EventHandler {
public:
	template <typename T>
	EventHandler(EventType eventType, T handlerFunction): eventType_(eventType), handlerFunction_(handlerFunction) {}
	virtual void Listen(Input& inputMonitor) = 0;
protected:
	EventType eventType_{EventType::kNone};	
	std::function<void()> handlerFunction_;
	static bool CheckKeyboardInput(std::set<KeyCharacter> inputKeys, std::set<KeyCharacter> listenKeys); //returns whether the handler function should be called or not
};

class KeyDownEventHandler final: public EventHandler {
public:
	//using variable arguments: http://www.cplusplus.com/reference/cstdarg/va_list/

	template <typename T>
	KeyDownEventHandler(T handlerFunction, std::set<KeyCharacter> keys): EventHandler(EventType::kDownKey, handlerFunction), keys_(keys) {
	}

	void Listen(Input& inputMonitor);
private:
	std::set<KeyCharacter> keys_;
};


class KeyUpEventHandler final: public EventHandler {
public:
	//using variable arguments: http://www.cplusplus.com/reference/cstdarg/va_list/

	template <typename T>
	KeyUpEventHandler(T handlerFunction, std::set<KeyCharacter> keys): EventHandler(EventType::kUpKey, handlerFunction), keys_(keys) {
	}

	void Listen(Input& inputMonitor);
private:
	std::set<KeyCharacter> keys_;
};

#endif
