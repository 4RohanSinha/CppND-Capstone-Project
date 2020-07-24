#ifndef TIMER_H
#define TIMER_H

#include <iostream>
#include <SDL2/SDL.h>

//adapted from timer in game.h and game.cpp from CppND-Capstone-Snake-Game
class Timer {
public:
	Timer(std::size_t target_frame_duration): target_frame_duration_(target_frame_duration) {}
	void BeginKeyframe();
	void EndKeyframe();
	Uint32 GetKeyframeDuration() const { return frame_duration; }
	int GetNumberOfKeyframes() const { return numKeyframes_; }
private:
	Uint32 frame_start;
	Uint32 frame_end;
	Uint32 frame_duration;
	std::size_t target_frame_duration_;
	int numKeyframes_;

	void DelayIfNeeded();
};

#endif
