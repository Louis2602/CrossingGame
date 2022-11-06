#pragma comment(lib, "Winmm.lib")
#define _CRT_SECURE_NO_WARNINGS

#include "Controller.h"
#include "Graphics.h"
#include "Sound.h"
#include "Game.h"
#include "Menu.h"
#include "CANIMAL.h"
#include "CVEHICLE.h"
#include "CPEOPLE.h"
#include "cLine.h"


#include <chrono>
#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <thread>
#include <conio.h>
#include <string>
#include <fstream>
#include <vector>
#include <time.h>

using namespace std::chrono;
//using namespace std::literals::chrono_literals;
using namespace std;

#define _EASY 1
#define WIDTH_CONSOLE 1366
#define HEIGH_CONSOLE 768

extern bool Continue;