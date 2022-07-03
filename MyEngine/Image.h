#pragma once
#include <SDL.h>

enum class Direction {
	NONE,
	UP,
	DOWN,
	LEFT,
	RIGHT
};

class Image
{
public:
	Image(const char* path, int x, int y, int w, int h);
	~Image();

	void Update(double delta_time);
	void Display(SDL_Surface* screensurface);
	void handleEvents(SDL_Event const &event);
private:
	SDL_Surface* m_image;
	SDL_Rect m_position;
	double m_x;
	double m_y;
	Direction m_direction;
};

