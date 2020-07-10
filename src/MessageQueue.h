#ifndef MESSAGE_QUEUE_H
#define MESSAGE_QUEUE_H

#include <thread>
#include <future>
#include <mutex>
#include <queue>
#include <deque>
#include <condition_variable>

template <class T>
class MessageQueue {
public:
	MessageQueue() {}
	T receive();
	void send(T &&message);
private:
	std::deque<T> queue_;
	std::condition_variable condition_;
	std::mutex mtx_;
};

struct PointMessage {
	float x;
	float y;
};

#endif
