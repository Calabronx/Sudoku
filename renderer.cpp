#include "renderer.h"

Renderer::Renderer(SDL_Window* window)
{
    if (!window) {
        SDL_Log("Window pointer is null!");
        return;
    }

    m_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!m_renderer) {
        SDL_Log("Failed to create renderer: %s", SDL_GetError());
    }
}

Renderer::~Renderer()
{
}

SDL_Renderer* Renderer::getRenderer()
{
    return m_renderer;
}
