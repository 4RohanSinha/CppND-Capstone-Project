#ifndef AUDIO_H
#define AUDIO_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <stdexcept>
#include <string>
#include "ReferenceCounter.h"

class Audio {
public:
	Audio() {}
	Audio(std::string filename);
	//virtual destructor because Audio objects in the AudioManager class are stored in an unordered_map
	//Audio is also an abstract class, so the unordered map is full of Music and SoundEffect objects instead
	//They have destructors because they have raw pointers to SDL objects that need to be deleted
	virtual ~Audio() {}
	//adhering to the Rule of Five with virtual destructors: https://stackoverflow.com/questions/26039907/does-rule-of-three-five-apply-to-inheritance-and-virtual-destructors
	//make other parts of Rule of Five default
	Audio(const Audio& source) = default;
	Audio& operator=(const Audio& source) = default;
	Audio(Audio&& source) = default;
	Audio& operator=(Audio&& source) = default;

	virtual void LoadMusic() = 0;
	virtual void Play() = 0;
	virtual void Pause() = 0;
	virtual void Resume() = 0;
	virtual void Stop() = 0;
	virtual float GetVolume() = 0;
	virtual void SetVolume(float val) = 0;
	std::string GetFilename() { return filename_; }
	virtual void Delete() = 0;
protected:
	ReferenceCounter* ref_count;
	std::string filename_;
};

class Music: public Audio {
public:
	Music(std::string filename): Audio(filename) { LoadMusic(); }
	~Music() override;
	Music(const Music& source);
	Music& operator=(const Music& source);
	Music(Music&& source);
	Music& operator=(Music&& source);
	void LoadMusic() override;
	void Play() override;
	void Repeat(int n);
	void RepeatForever();
	void Pause() override;
	void Resume() override;
	void Stop() override;
	float GetVolume() override;
	void SetVolume(float val) override;
	void Delete() override;
private:
	Mix_Music* music_ = nullptr;
	void RepeatFor(int n);
};

class SoundEffect: public Audio {
public:
	SoundEffect(std::string filename): Audio(filename) { LoadMusic(); }
	~SoundEffect() override;
	SoundEffect(const SoundEffect& source);
	SoundEffect& operator=(const SoundEffect& source);
	SoundEffect(SoundEffect&& source);
	SoundEffect& operator=(SoundEffect&& source);
	void LoadMusic() override;
	void Play() override;
	void Repeat(int n);
	void Pause() override;
	void Resume() override;
	void Stop() override;
	float GetVolume() override;
	void SetVolume(float val) override;
	void Delete() override;
private:
	Mix_Chunk* effect_ = nullptr;
	int channel_;	
};

#endif
