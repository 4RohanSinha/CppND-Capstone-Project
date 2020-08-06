#include "Timer.h"

void Timer::BeginKeyframe() {
	//mark start of frame
	frame_start = SDL_GetTicks();
}

void Timer::EndKeyframe() {
	//end frame
	frame_end = SDL_GetTicks();
	//get frame duration
	frame_duration = frame_end - frame_start;
	//increase the total number keyframes shown
	numKeyframes_++;
	//execute delay if needed
	DelayIfNeeded();
}

void Timer::DelayIfNeeded() {
	//check if current frame duration is too fast
	//if so, delay for the difference between the two durations
	if (frame_duration < target_frame_duration_)
		SDL_Delay(target_frame_duration_ - frame_duration);
}
