#pragma once

class Renderer;

#include <SDL.h>
#include <memory>
#include "Window.h"

struct RendererDeleter
{
	void operator()(SDL_Renderer* renderer)
	{
		SDL_DestroyRenderer(renderer);
		std::cout << "Destructed renderer" << std::endl;
	}
};

class Renderer
{
public:
	Renderer(std::weak_ptr<Window> window);
	~Renderer();

	void render();
	void clear();
	[[nodiscard]] std::shared_ptr<SDL_Renderer> getSDLRenderer() const;

private:
	std::shared_ptr<SDL_Renderer> renderer;
	std::weak_ptr<Window> window;
};
