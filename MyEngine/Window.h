#pragma once
#include "Image.h"
#include <SDL.h>
#include<time.h>
#include <cstdlib>

class Window {
public:
	Window(const int w, const int h, const char* title);
	~Window();

	void Loop();
	void Update(double delta_time);
	void Draw();
	void SetColour(const int r, const int g, const int b);
	

private:
	
	int rgb[3];

	SDL_Window* m_window;
	SDL_Surface* m_screensurface;
	SDL_Event m_window_event;

	Image m_jonny;
};
