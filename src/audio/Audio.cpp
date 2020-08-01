#include <iostream>
#include "Audio.h"


void Music::LoadMusic() {
	music_ = Mix_LoadMUS(filename_.c_str());
	if (music_ == NULL || music_ == nullptr)
		throw std::runtime_error("Error: unable to load music from file.");
}

void Music::Play() {
	RepeatFor(0);
}


void Music::Repeat(int n) {
	RepeatFor(n);
}

void Music::RepeatForever() {
	RepeatFor(-1);
}

void Music::Stop() {
	Mix_HaltMusic();
}

void Music::Pause() {
	Mix_PauseMusic();
}

void Music::Resume() {
	Mix_ResumeMusic();
}

void Music::RepeatFor(int n) {
	Mix_PlayMusic(music_, n);
}

float Music::GetVolume() {
	return static_cast<float>(Mix_VolumeMusic(-1))/static_cast<float>(MIX_MAX_VOLUME);
}

void Music::SetVolume(float val) {
	Mix_VolumeMusic(static_cast<int>(val * MIX_MAX_VOLUME));
}


Music::~Music() {
	Mix_FreeMusic(music_);
}

void SoundEffect::LoadMusic() {
	effect_ = Mix_LoadWAV(filename_.c_str());
	if (effect_ == NULL || effect_ == nullptr)
		throw std::runtime_error("Error: unable to load sound effect from file.");
}

void SoundEffect::Play() {
	channel_ = Mix_PlayChannel(-1, effect_, 1);
}

void SoundEffect::Pause() {
	Mix_Pause(channel_);
}

void SoundEffect::Resume() {
	Mix_Resume(channel_);
}

void SoundEffect::Repeat(int n) {
	channel_ = Mix_PlayChannel(-1, effect_, n);
}

void SoundEffect::Stop() {
	Mix_HaltChannel(channel_);
}

float SoundEffect::GetVolume() {
	return static_cast<float>(Mix_Volume(channel_, -1))/static_cast<float>((MIX_MAX_VOLUME));
}

void SoundEffect::SetVolume(float val) {
	Mix_Volume(channel_, static_cast<int>(MIX_MAX_VOLUME*val));
}

SoundEffect::~SoundEffect() {
	Mix_FreeChunk(effect_);
}

