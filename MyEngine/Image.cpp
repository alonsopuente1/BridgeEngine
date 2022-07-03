#include "Image.h"
#include <iostream>

#define LOG(x) std::cout << x << std::endl

Image::Image(const char* path, int x, int y, int w, int h) {
	m_image = SDL_LoadBMP(path);
	
	m_position.x = x;
	m_position.y = y;
	m_position.w = w;
	m_position.h = h;

	m_x = x;
	m_y = y;

	if (!m_image) {
		std::cout << "Could not load image. SDL Error: " << SDL_GetError() << std::endl;
	}
}

Image::~Image() {
	SDL_FreeSurface(m_image);
}

void Image::Update(double delta_time) {
	switch (m_direction)
	{
	case Direction::NONE:
		m_x += 0.0;
		m_y += 0.0;
		break;
	case Direction::UP:
		m_y = m_y - (5.0 * delta_time);
		break;
	case Direction::DOWN:
		m_y = m_y + (5.0 * delta_time);
		break;
	case Direction::LEFT:
		m_x = m_x - (5.0 * delta_time);
		break;
	case Direction::RIGHT:
		m_x = m_x + (5.0 * delta_time);
		break;
	}

	m_position.x = m_x;
	m_position.y = m_y;
}

void Image::Display( SDL_Surface* screensurface) {
	SDL_BlitSurface(m_image, NULL, screensurface, &m_position);
}

void Image::handleEvents(SDL_Event const& event) {
	switch (event.type)
	{
	case SDL_KEYDOWN:
		Uint8 const* keys = SDL_GetKeyboardState(nullptr);

		if (keys[SDL_SCANCODE_W] == 1) {
			m_direction = Direction::UP;
			return;
		}
		else if (keys[SDL_SCANCODE_S] == 1) {
			m_direction = Direction::DOWN;
			return;
		}
		else if (keys[SDL_SCANCODE_A] == 1) {
			m_direction = Direction::LEFT;
			return;
		}
		else if (keys[SDL_SCANCODE_D] == 1) {
			m_direction = Direction::RIGHT;
			return;
		}
		break;
	}
}
