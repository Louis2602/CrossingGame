#include "Controller.h"
#include "Sound.h"
#include "Graphics.h"

int Round = 1;

int main() {
	Controller::SetUpConsole();
	Sound::SoundBackground();
	Graphics::Menu(Round);
}