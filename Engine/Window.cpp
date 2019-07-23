#include "Window.h"
#include <iostream>

Window::Window()
{
	// Initializing SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "Cannot initialize SDL" << std::endl;
		exit(EXIT_FAILURE);
	}

	// Initializing window
	/*SDL_Window* window = SDL_CreateWindow("Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 200, 200,
	                                      SDL_WINDOW_SHOWN);
	if (window == nullptr)
	{
		std::cout << "Cannot initialize window" << std::endl;
		exit(EXIT_FAILURE);
	}*/

	this->window = std::shared_ptr<SDL_Window>(SDL_CreateWindow("Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 200, 200,
		SDL_WINDOW_SHOWN), WindowDeleter());
}

Window::~Window()
{
	window.reset(); // TODO Fix Quiting before window was destroyed
	SDL_Quit();
}

Renderer* Window::getRenderer() const
{
	return this->renderer;
}

std::shared_ptr<SDL_Window> Window::getSDLWindow() const
{
	return this->window;
}
