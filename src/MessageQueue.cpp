#include "MessageQueue.h"

template <typename T>
T MessageQueue<T>::receive() {
	std::unique_lock<std::mutex> lck(mtx_);
	condition_.wait(lck, [this] { return !queue_.empty(); });
	T message = std::move(queue_.back());
	queue_.back();
	return message;
}

template <typename T>
void MessageQueue<T>::send(T &&message) {
	std::lock_guard<std::mutex> lck(mtx_);
	queue_.push_back(std::move(message));
	condition_.notify_one();
}
