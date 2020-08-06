#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include "SDL2_headers.h"
#include <initializer_list>
#include <set>
#include <functional>
#include <memory>
#include "Keyboard.h"
#include "Input.h"

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
	//in the Controller class, unique_ptrs to EventHandler objects are stored
	//because they are unique_ptrs, they will call delete on the internal raw pointer when the object when it goes out of scope
	//this class is abstract, so a virtual destructor is added
	//also, the compiler gives a warning without this line
	virtual ~EventHandler() {}
protected:
	EventType eventType_{EventType::kNone};	
	std::function<void()> handlerFunction_;
};

class KeyDownEventHandler final: public EventHandler {
public:

	template <typename T>
	KeyDownEventHandler(T handlerFunction, std::vector<KeyCharacter> keys): EventHandler(EventType::kDownKey, handlerFunction), keys_(keys) {
	}

	void Listen(Input& inputMonitor);
private:
	std::vector<KeyCharacter> keys_;
};


class KeyUpEventHandler final: public EventHandler {
public:

	template <typename T>
	KeyUpEventHandler(T handlerFunction, std::vector<KeyCharacter> keys): EventHandler(EventType::kUpKey, handlerFunction), keys_(keys) {
	}

	void Listen(Input& inputMonitor);
private:
	std::vector<KeyCharacter> keys_;
};

#endif
