#include "Window.h"
#include <stdio.h>

Window::Window(const int w, const int h, const char* title) {
	this->init(w, h, title);
	this->screensurface = SDL_GetWindowSurface(this->window);
}
Window::~Window() {
	SDL_DestroyWindow(this->window);
	SDL_Quit();
}

void Window::init(int w, int h, const char* title) {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL Could not be initialized! SDL Error: %s\n", SDL_GetError());
	}
	this->window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);
	if (this->window == NULL) {
		printf("Window could not be created: SDL Error %s\n", SDL_GetError());
		return;
	}
}

void Window::update(int colour[]) {
	SDL_FillRect(this->screensurface, NULL, SDL_MapRGB(this->screensurface->format, colour[0], colour[1], colour[2]));
	SDL_UpdateWindowSurface(window);
}
