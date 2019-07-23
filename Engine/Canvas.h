#pragma once

#include <SDL.h>
#include <memory>
#include "Color.h"

class Canvas
{
public:
	Canvas(std::weak_ptr<SDL_Renderer> renderer);

	void setColor(const Color& color);
	void drawLine(int startX, int startY, int endX, int endY);

private:
	std::weak_ptr<SDL_Renderer> renderer;
};
