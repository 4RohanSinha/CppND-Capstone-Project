//note: std::filesystem only works with C++17 and above
#ifndef AUDIO_MANAGER_H
#define AUDIO_MANAGER_H

#include <fstream>
#include <sstream>
#include <filesystem>
#include <unordered_map>
#include <algorithm>
#include <string>
#include "Audio.h"

class AudioManager {
public:
	AudioManager();
	AudioManager(int channels);
	void LoadFromDirectory(std::string dir);
	void AddMusic(std::string file, std::string identifier);
	void AddMusic(std::unique_ptr<Music> music, std::string identifier);
	void AddSoundEffect(std::string file, std::string identifier);
	void AddSoundEffect(std::unique_ptr<SoundEffect> effect, std::string identifier);
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
private:
	std::unordered_map<std::string, std::unique_ptr<Audio>> media_;
	int channels_;
};

#endif
