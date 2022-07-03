#include "Window.h"
#include "Image.h"
#include <iostream>
#include <stdio.h>

#define LOG(x) std::cout << x << std::endl


Window::Window(const int w, const int h, const char* title) : m_jonny("jongobong.bmp", 0, 0, 177, 172) {
	m_window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);
	m_screensurface = SDL_GetWindowSurface(m_window);

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL could not be initialized: SDL Error " << SDL_GetError();
	}
	
	if (!m_window) {
		std::cout << "Window could not be created: SDL Error " << SDL_GetError();
	}
	
	if (!m_screensurface) {
		std::cout << "Screen surface could not be created: SDL Error " << SDL_GetError();
	}

	
	int rgb[3] = { 0xFF, 0xFF, 0xFF };
}
Window::~Window() {
	SDL_FreeSurface(m_screensurface);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

void Window::Loop() {
	bool loop = true;

	while (loop) {

		while (SDL_PollEvent(&m_window_event) > 0) {
			m_jonny.handleEvents(m_window_event);
			switch (m_window_event.type) {
			case SDL_QUIT:
				loop = false;
				break;
			}
		}
		Update(1.0/60.0);
		Draw(); 
	}


}

void Window::Draw() {
	SDL_FillRect(m_screensurface, NULL, SDL_MapRGB(m_screensurface->format, rgb[0], rgb[1], rgb[2]));

	m_jonny.Display(m_screensurface);

	SDL_UpdateWindowSurface(m_window);
}

void Window::SetColour(const int r, const int g, const int b) {
	rgb[0] = r;
	rgb[1] = g;
	rgb[2] = b;
}

void Window::Update(double delta_time) {
	m_jonny.Update(delta_time);
}
