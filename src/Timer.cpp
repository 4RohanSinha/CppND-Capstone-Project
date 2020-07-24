#include "Timer.h"

void Timer::BeginKeyframe() {
	frame_start = SDL_GetTicks();
}

void Timer::EndKeyframe() {
	frame_end = SDL_GetTicks();
	frame_duration = frame_end - frame_start;
	numKeyframes_++;
	DelayIfNeeded();
}

void Timer::DelayIfNeeded() {
	if (frame_duration < target_frame_duration_)
		SDL_Delay(target_frame_duration_ - frame_duration);
}
