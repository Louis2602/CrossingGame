#include "Sound.h";

bool Sound::getState() {
	return isOn;
}

void Sound::setState(bool state) {
	isOn = state;
}

void Sound::SoundBackground(bool state) {
	if (state)
		PlaySound(TEXT("LegendaryAmadeus.wav"), NULL, SND_ASYNC);
	else
		PlaySound(NULL, NULL, SND_ASYNC);

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
	PlaySound(TEXT("Move.wav"), NULL, SND_ASYNC);

}
void Sound::SoundSuccess() {
	PlaySound(TEXT("Success.wav"), NULL, SND_ASYNC);

}
void Sound::SoundWin() {
	PlaySound(TEXT("win.wav"), NULL, SND_ASYNC);
}
void Sound::SoundLose() {
	PlaySound(TEXT("lose.wav"), NULL, SND_ASYNC);
}