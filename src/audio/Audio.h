#ifndef AUDIO_H
#define AUDIO_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include "Integrate.h"
#include <stdexcept>
#include <string>

enum class AudioType {
	kMusic,
	kSoundEffect
};

class Audio {
public:
	Audio(std::string filename): filename_(filename) {}
	virtual void LoadMusic() = 0;
	virtual void Play() = 0;
	virtual void Pause() = 0;
	virtual void Resume() = 0;
	virtual void Stop() = 0;
	virtual float GetVolume() = 0;
	virtual void SetVolume(float val) = 0;
	std::string GetFilename() { return filename_; }
	virtual ~Audio() {}
protected:
	std::string filename_;
};

class Music: public Audio {
public:
	Music(std::string filename): Audio(filename) { LoadMusic(); }
	void LoadMusic();
	void Play();
	void Repeat(int n);
	void RepeatForever();
	void Pause();
	void Resume();
	void Stop();
	float GetVolume();
	void SetVolume(float val);
	~Music();
private:
	Mix_Music* music_ = nullptr;
	void RepeatFor(int n);
};

class SoundEffect: public Audio {
public:
	SoundEffect(std::string filename): Audio(filename) { LoadMusic(); }
	void LoadMusic();
	void Play();
	void Repeat(int n);
	void Pause();
	void Resume();
	void Stop();
	float GetVolume();
	void SetVolume(float val);
	~SoundEffect();
private:
	Mix_Chunk* effect_ = nullptr;
	int channel_;	
};

#endif
