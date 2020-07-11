#ifndef EVENT_H
#define EVENT_H

#include <vector>
#include <memory>
#include <cstdarg>
#include "Node.h"

enum EventType {
	kCollision,
	kUpKey,
	kDownKey,
	kTapDown,
	kTapUp,
	kSwipe,
	kClick,
	kQuit
};

enum KeyCharacter {
	keyA, keyB, keyC, keyD, keyE, keyF, keyG, keyH, keyI, keyJ, keyK, keyL, keyM,
	keyN, keyO, keyP, keyQ, keyR, keyS, keyT, keyU, keyV, keyW, keyX, keyY, keyZ,
	keyShift, keyCtrl, keyLeftArr, keyRightArr, keyUpArr, keyDownArr,
	key0, key1, key2, key3, key4, key5, key6, key7, key8, key9, keyReturn, keyTab,
	keyPlus, keyMinus, keyEquals, keySlash, keyComma, keyPeriod
};

class Event {
public:
	Event(EventType event): event_(event) {}
	//using variable arguments: http://www.cplusplus.com/reference/cstdarg/va_list/
	Event(EventType event, int num, ...);

	Event(EventType event, std::vector<std::shared_ptr<Node>> nodesInvolved): event_(event), nodesInvolved_(nodesInvolved) {}

	auto GetNodesInvolved() { return nodesInvolved_; }

	void AddNodeInvolved(std::shared_ptr<Node> node) { nodesInvolved_.push_back(node); }
	void SetEvent(EventType event) { event_ = event; }

	EventType GetEvent() { return event_; }

	std::vector<float> GetCoordinates() { return coordinates_; }

	void SetCoordinates(float x, float y) { coordinates_.assign(x, y); }

	KeyCharacter GetKeyCharacter() { return keyChar_; }
	void SetKeyCharacter(KeyCharacter keyChar) { keyChar_ = keyChar; }
private:
	EventType event_;
	std::vector<std::shared_ptr<Node>> nodesInvolved_;
	std::vector<float> coordinates_;
	KeyCharacter keyChar_;
};

#endif

