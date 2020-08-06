#include "AudioManager.h"

AudioManager::AudioManager(): channels_(2) {
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 2048);
}

AudioManager::AudioManager(int channels): channels_(channels) {
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, channels_, 2048);
}

void AudioManager::AddMusic(std::string file, std::string identifier) {
	media_[identifier] = std::make_unique<Music>(file);
}

void AudioManager::AddSoundEffect(std::string file, std::string identifier) {
	media_[identifier] = std::make_unique<SoundEffect>(file);
}

void AudioManager::AddMedia(std::unique_ptr<Audio> clip, std::string identifier) {
	media_[identifier] = std::move(clip);
}

void AudioManager::Play(std::string identifier) {
	media_[identifier]->Play();
}

void AudioManager::Pause(std::string identifier) {
	media_[identifier]->Pause();
}

void AudioManager::Resume(std::string identifier) {
	media_[identifier]->Resume();
}

void AudioManager::Stop(std::string identifier) {
	media_[identifier]->Stop();
}

void AudioManager::SetVolume(std::string identifier, float val) {
	media_[identifier]->SetVolume(val);
}

void AudioManager::SetVolume(float val) {
	Mix_Volume(-1, static_cast<int>(val * MIX_MAX_VOLUME));
}

float AudioManager::GetVolume(std::string identifier) {
	return media_[identifier]->GetVolume();
}

float AudioManager::GetVolume() {
	return static_cast<float>(Mix_Volume(-1, -1))/static_cast<float>(MIX_MAX_VOLUME);
}

std::string AudioManager::GetFilenameFor(std::string identifier) {
	return media_[identifier]->GetFilename();
}

AudioManager::~AudioManager(){
	Mix_Quit();
}

AudioManager::AudioManager(AudioManager&& source) {
	media_ = std::move(source.media_);
	channels_ = source.channels_;
	source.media_.clear();
	source.channels_ = 0;
}

AudioManager& AudioManager::operator=(AudioManager&& source) {
	if (this == &source)
		return *this;

	media_ = std::move(source.media_);
	channels_ = source.channels_;
	source.media_.clear();
	source.channels_ = 0;
	return *this;
}

