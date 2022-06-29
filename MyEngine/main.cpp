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

bool close = false;
int colours[7][3] = { {WHITE},  {RED }, {GREEN}, {BLUE}, {YELLOW}, {MAGENTA}, {CYAN } };
int index = 0;
bool r = false;

void HandleEvents() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			close = true;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_ESCAPE:
				close = true;
				break;
			case SDLK_RIGHT:
				if (index + 1 > 6) {
					index = 0;
				}
				else {
					index++;
				}
				break;
			case SDLK_r:
				r = !r;
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}

	}
}

int random(const int LB, const int UB) {
	return rand() % UB + LB;
}


int main(int argc, const char* args[]) {
	srand(time(0));

	int colour[3];
	bool user = false;

	if (argc > 1) {
		for (int i = 0; i < 3; i++) {
			colour[i] = atoi(args[i + 1]);
			user = true;
		}
	}

	while(!close) {
		if (user) {
			window.update(colour);
		}
		else if (r) {
			int newColour[3] = { random(0, 255), random(0, 255), random(0, 255) };
			window.update(newColour);
		}
		else {
			window.update(colours[index]);
		}
		HandleEvents();
	}

	return 0;
}