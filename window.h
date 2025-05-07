#pragma once
#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>

#include "consts.h"

class Window
{
	public:
		Window();
		~Window();
	private:
		int initWindow();
	public:
		SDL_Window* getWindow();


	private:
		SDL_Window* m_window;

};
#endif WINDOW_H

