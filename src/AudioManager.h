#ifndef AUDIO_MANAGER_H
#define AUDIO_MANAGER_H

#include <fstream>
#include <sstream>
#include <memory>
#include <unordered_map>
#include <algorithm>
#include <string>
#include "Audio.h"

class AudioManager {
public:
	AudioManager();
	AudioManager(int channels);
	void AddMusic(std::string file, std::string identifier);
	void AddSoundEffect(std::string file, std::string identifier);
	void AddMedia(std::unique_ptr<Audio> clip, std::string identifier);
	void Play(std::string identifier);
	void Pause(std::string identifier);
	void Resume(std::string identifier);
	void Stop(std::string identifier);
	void SetVolume(std::string identifier, float val);
	void SetVolume(float val);
	float GetVolume(std::string identifier);
	float GetVolume();
	std::string GetFilenameFor(std::string identifier);
	~AudioManager();
	//there should only ever be one audio manager at a time
	AudioManager(const AudioManager& source) = delete;
	AudioManager& operator=(const AudioManager& source) = delete;
	AudioManager(AudioManager&& source);
	AudioManager& operator=(AudioManager&& source);
private:
	//unordered_map of string identifier to media
	//media has to be unique_ptr because Audio is an abstract class with pure virtual functions (see Audio.h)
	std::unordered_map<std::string, std::unique_ptr<Audio>> media_;
	//number of channels
	int channels_;
};

#endif
