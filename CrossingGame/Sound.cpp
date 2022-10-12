#include "Sound.h";

void Sound::SoundBackground() {
	PlaySound(TEXT("LegendaryAmadeus.wav"), NULL, SND_ASYNC);
}

void Sound::SoundByeBye() {
	PlaySound(TEXT("ByeBye.wav"), NULL, SND_ASYNC);
}

void Sound::EndSoundGame() {
	PlaySound(NULL, NULL, SND_FILENAME);
}

void Sound::SoundRocket() {
	PlaySound(TEXT("SoundRocket.wav"), NULL, SND_ASYNC);
}

void Sound::PlayerMove() {
	PlaySound(TEXT("PlayerMove.wav"), NULL, SND_ASYNC);
}