#ifndef EVENT_H
#define EVENT_H

#include <vector>
#include <memory>
#include <cstdarg>
#include "Node.h"

//enum class to allow for the same value in two diff. enums (kNone)
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


//WARNING: to add any keys to this enum, MAKE SURE THEY ARE BEFORE kNone.
enum KeyCharacter {
	keyA, keyB, keyC, keyD, keyE, keyF, keyG, keyH, keyI, keyJ, keyK, keyL, keyM,
	keyN, keyO, keyP, keyQ, keyR, keyS, keyT, keyU, keyV, keyW, keyX, keyY, keyZ,
	keyShift, keyCtrl, keyLeftArr, keyRightArr, keyUpArr, keyDownArr,
	key0, key1, key2, key3, key4, key5, key6, key7, key8, key9, keyReturn, keyTab,
	keyPlus, keyMinus, keyEquals, keySlash, keyComma, keyPeriod, kNone, kAll
};

class Event {
public:
	Event(EventType event): event_(event) {}

	//using variable arguments: http://www.cplusplus.com/reference/cstdarg/va_list/
	Event(EventType event, int num, ...);

	Event(EventType event, std::vector<std::shared_ptr<Node>> nodesInvolved): event_(event), nodesInvolved_(nodesInvolved) {}

	auto GetNodesInvolved() { return nodesInvolved_; }

	void AddNodeInvolved(std::shared_ptr<Node> node) { nodesInvolved_.push_back(node); }
	void SetEventType(EventType event) { event_ = event; }

	EventType GetEventType() { return event_; }

	std::vector<float> GetCoordinates() { return coordinates_; }

	void SetCoordinates(float x, float y) { coordinates_.assign(x, y); }

	KeyCharacter GetKeyCharacter() { return keyChar_; }

	void SetKeyCharacter(KeyCharacter keyChar) { keyChar_ = keyChar; }

	bool operator==(const Event& otherEvent) const;
	
	bool operator!=(const Event& otherEvent) const;
private:
	EventType event_{EventType::kNone};
	std::vector<std::shared_ptr<Node>> nodesInvolved_;
	std::vector<float> coordinates_;
	KeyCharacter keyChar_{KeyCharacter::kNone};

};

#endif

