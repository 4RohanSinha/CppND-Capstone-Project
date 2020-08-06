#include <iostream>
#include "Audio.h"

Audio::Audio(std::string filename): filename_(filename) {
	ref_count = new ReferenceCounter();
	ref_count->increment();
}
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

void Music::Delete() {
	if (ref_count != nullptr) {
		ref_count->decrement();
		if (**ref_count == 0) {
			delete ref_count;
			Mix_FreeMusic(music_);
		}
	}
	ref_count = nullptr;
	music_ = nullptr;
}

Music::~Music() {
	this->Delete();
}

Music::Music(const Music& source) {
	music_ = source.music_;
	ref_count = source.ref_count;
	if (music_ != nullptr)
		ref_count->increment();
}

Music& Music::operator=(const Music& source) {
	if (this == &source)
		return *this;

	this->Delete();
	music_ = source.music_;
	ref_count = source.ref_count;
	if (music_ != nullptr)
		ref_count->increment();

	return *this;
}

Music::Music(Music&& source) {
	music_ = source.music_;
	ref_count = source.ref_count;
	source.music_ = nullptr;
	source.ref_count = nullptr;
}

Music& Music::operator=(Music&& source) {
	if (this == &source)
		return *this;

	this->Delete();

	music_ = source.music_;
	ref_count = source.ref_count;
	source.music_ = nullptr;
	source.ref_count = nullptr;
	return *this;
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

void SoundEffect::Delete() {
	if (ref_count != nullptr) {
		ref_count->decrement();
		if (**ref_count == 0) {
			delete ref_count;
			Mix_FreeChunk(effect_);
		}
	}
	ref_count = nullptr;
	effect_ = nullptr;
}

SoundEffect::~SoundEffect() {
	this->Delete();
}

SoundEffect::SoundEffect(const SoundEffect& source) {
	effect_ = source.effect_;
	ref_count = source.ref_count;
	if (effect_ != nullptr)
		ref_count->increment();
}

SoundEffect& SoundEffect::operator=(const SoundEffect& source) {
	if (this == &source)
		return *this;

	this->Delete();

	effect_ = source.effect_;
	ref_count = source.ref_count;
	if (effect_ != nullptr)
		ref_count->increment();
	return *this;
}

SoundEffect::SoundEffect(SoundEffect&& source) {
	effect_ = source.effect_;
	ref_count = source.ref_count;
	source.effect_ = nullptr;
	source.ref_count = nullptr;
}

SoundEffect& SoundEffect::operator=(SoundEffect&& source) {
	if (this == &source)
		return *this;

	this->Delete();

	effect_ = source.effect_;
	ref_count = source.ref_count;
	source.effect_ = nullptr;
	source.ref_count = nullptr;
	return *this;
}
