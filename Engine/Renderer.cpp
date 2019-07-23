#include "Renderer.h"

Renderer::Renderer(std::weak_ptr<Window> window)
{
	std::shared_ptr<SDL_Window> SDLWindow = window.lock()->getSDLWindow();
	this->renderer = std::shared_ptr<SDL_Renderer>(
		SDL_CreateRenderer(SDLWindow.get(), -1, SDL_RENDERER_ACCELERATED), 
		RendererDeleter()
	);
	this->window = window;
}

Renderer::~Renderer() = default;

void Renderer::render()
{
	SDL_RenderPresent(renderer.get());
}

void Renderer::clear()
{
	SDL_RenderClear(renderer.get());
}

std::shared_ptr<SDL_Renderer> Renderer::getSDLRenderer() const
{
	return this->renderer;
}
