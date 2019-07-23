#pragma once

class Window;

#include <iostream>
#include <memory>
#include <SDL.h>
#include "Renderer.h"

struct WindowDeleter
{
	void operator()(SDL_Window* window)
	{
		SDL_DestroyWindow(window);
	}
};

class Window
{
public:
	Window();
	~Window();

	Renderer* getRenderer() const;
	[[nodiscard]] std::shared_ptr<SDL_Window> getSDLWindow() const;

private:
	std::shared_ptr<SDL_Window> window;
	Renderer* renderer = nullptr;
};
