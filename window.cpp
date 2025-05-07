#include "window.h"
#include <iostream>

Window::Window()
{
	initWindow();
}

Window::~Window()
{
	delete m_window;
}

int Window::initWindow()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "Failed to initialize the window\n";
		return -1;
		
	}

	m_window = SDL_CreateWindow("SDL window",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		SCREEN_WIDTH,
		SCREEN_HEIGHT, 0);

	if (m_window == nullptr)
	{
		std::cout << "Failed to create the window\n";
		return -1;
		
	}

	//SDL_Surface* window_surface = SDL_GetWindowSurface(m_window);

	//if (window_surface == nullptr)
	//{
	//	std::cout << "Failed to get the surface from the window\n";
	//	return -1;
	//}

	//SDL_UpdateWindowSurface(m_window);

	//SDL_Delay(5000);

	return 0;
}

SDL_Window* Window::getWindow() 
{
	// TODO: insert return statement here
	return m_window;
}
