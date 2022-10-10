#include "Header.h";

void SoundBackground() {
	PlaySound(TEXT("LegendaryAmadeus.wav"), NULL, SND_ASYNC);
}

void SoundByeBye() {
	PlaySound(TEXT("ByeBye.wav"), NULL, SND_ASYNC);
}

void EndSoundGame() {
	PlaySound(NULL, NULL, SND_FILENAME);
}

void SoundRocket() {
	PlaySound(TEXT("SoundRocket.wav"), NULL, SND_ASYNC);
}