#include "Sound.h";

bool Sound::getState() {
	return isOn;
}

void Sound::setState(bool state) {
	isOn = state;
}

void Sound::SoundBackground() {
	Sound s;
	if (s.getState())
		PlaySound(TEXT("LegendaryAmadeus.wav"), NULL, SND_ASYNC);
	else
		PlaySound(NULL, NULL, SND_ASYNC);
	
}

void Sound::SoundByeBye() {
	Sound s;
	if(s.getState())
		PlaySound(TEXT("ByeBye.wav"), NULL, SND_ASYNC);
	else
		PlaySound(NULL, NULL, SND_ASYNC);
}

void Sound::EndSoundGame() {
	Sound s;
	if(s.getState())
		PlaySound(NULL, NULL, SND_FILENAME);
	else
		PlaySound(NULL, NULL, SND_ASYNC);
}

void Sound::SoundRocket() {
	Sound s;
	if(s.getState())
		PlaySound(TEXT("SoundRocket.wav"), NULL, SND_ASYNC);
	else
		PlaySound(NULL, NULL, SND_ASYNC);
}

void Sound::PlayerMove() {
	Sound s;
	if(s.getState())
		PlaySound(TEXT("Move.wav"), NULL, SND_ASYNC);
	else
		PlaySound(NULL, NULL, SND_ASYNC);
}