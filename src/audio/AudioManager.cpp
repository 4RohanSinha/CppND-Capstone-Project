#include "AudioManager.h"

AudioManager::AudioManager(): channels_(2) {
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 2048);
}

AudioManager::AudioManager(int channels): channels_(channels) {
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, channels_, 2048);
}

void AudioManager::LoadFromDirectory(std::string dir) {
	for (auto& file: std::filesystem::directory_iterator(dir)) {
		AudioType aType;
		std::string path = file.path();
		std::transform(path.begin(), path.end(), path.begin(), [](unsigned char character) { return std::tolower(character); });
		size_t fileExtensionStart = path.find_last_of(".");
		size_t audioTypeIndex = path.find_last_of("_");
		std::string identifier = path.substr(0, fileExtensionStart);
		std::string audioType = identifier.substr(audioTypeIndex, identifier.length()); 
		std::string finalId = identifier.substr(0, audioTypeIndex);
		if (audioType == "_music")
			AddMusic(path, finalId); 
		else
			AddSoundEffect(path, finalId);
	}	

}

void AudioManager::AddMusic(std::string file, std::string identifier) {
	media_[identifier] = std::make_unique<Music>(file);
}

void AudioManager::AddMusic(std::unique_ptr<Music> music, std::string identifier) {
	media_[identifier] = std::move(music);
}

void AudioManager::AddSoundEffect(std::string file, std::string identifier) {
	media_[identifier] = std::make_unique<SoundEffect>(file);
}

void AudioManager::AddSoundEffect(std::unique_ptr<SoundEffect> effect, std::string identifier) {
	media_[identifier] = std::move(effect);
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
