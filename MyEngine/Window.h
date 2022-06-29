#pragma once
#include <SDL.h>
#include<time.h>
#include <cstdlib>

class Window {
public:
	SDL_Window* window;
	SDL_Surface* screensurface;

	Window(const int w, const int h, const char* title);
	~Window();
	
	void init(int w, int h, const char* title) ;
	void update(int colour[]) ;
};
