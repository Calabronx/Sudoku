#pragma once
#ifndef RENDERER_H
#define RENDERER_H
#include <SDL2/SDL.h>

class Renderer
{
	public:
		Renderer(SDL_Window *window);
		~Renderer();
		SDL_Renderer* getRenderer();

	private:
		SDL_Renderer*	m_renderer;


};
#endif

