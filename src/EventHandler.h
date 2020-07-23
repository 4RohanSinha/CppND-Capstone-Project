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
	EventHandler(EventType eventType, std::shared_ptr<Input> inputMonitor, T handlerFunction): eventType_(eventType), inputMonitor_(inputMonitor), handlerFunction_(handlerFunction) {}
	virtual void Listen() = 0;
protected:
	EventType eventType_{EventType::kNone};	
	std::shared_ptr<Input> inputMonitor_ = nullptr;
	std::function<void()> handlerFunction_;
	static bool CheckKeyboardInput(std::set<KeyCharacter> inputKeys, std::set<KeyCharacter> listenKeys); //returns whether the handler function should be called or not
};

class KeyDownEventHandler final: public EventHandler {
public:
	//using variable arguments: http://www.cplusplus.com/reference/cstdarg/va_list/

	template <typename T>
	KeyDownEventHandler(std::shared_ptr<Input> inputMonitor, T handlerFunction, std::set<KeyCharacter> keys): EventHandler(EventType::kDownKey, inputMonitor, handlerFunction), keys_(keys) {
	}

	void Listen();
private:
	std::set<KeyCharacter> keys_;
};


class KeyUpEventHandler final: public EventHandler {
public:
	//using variable arguments: http://www.cplusplus.com/reference/cstdarg/va_list/

	template <typename T>
	KeyUpEventHandler(std::shared_ptr<Input> inputMonitor, T handlerFunction, std::set<KeyCharacter> keys): EventHandler(EventType::kUpKey, inputMonitor, handlerFunction), keys_(keys) {
	}

	void Listen();
private:
	std::set<KeyCharacter> keys_;
};

#endif
