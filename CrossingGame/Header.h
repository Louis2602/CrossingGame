#pragma comment(lib, "Winmm.lib")
#define _CRT_SECURE_NO_WARNINGS

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
#include <mutex>
#include <direct.h>

using namespace std::chrono;

//using namespace std::literals::chrono_literals;
using namespace std;
extern mutex mtx;

#define _EASY 1
#define WIDTH_CONSOLE 1366
#define HEIGH_CONSOLE 768