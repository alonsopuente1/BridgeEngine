#include <SDL.h>
#include <stdio.h>
#include <iostream>
#include "Window.h"
#undef main

#define WHITE 0xFF, 0xFF, 0xFF
#define RED 0xFF, 0x00, 0x00
#define GREEN 0x00, 0xFF, 0x00
#define BLUE 0x00, 0x00, 0xFF
#define YELLOW 0xFF, 0xFF, 0x00
#define MAGENTA 0xFF, 0x00, 0xFF
#define CYAN 0x00, 0xFF, 0xFF

#define LOG(x) std::cout << x << std::endl

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const char* TITLE = "Hello, World!";

Window window(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE);

int random(const int LB, const int UB) {
	return rand() % UB + LB;
}


int main(int argc, const char* args[]) {
	srand(time(0));


	window.SetColour(WHITE);
	window.Loop();

	return 0;
}