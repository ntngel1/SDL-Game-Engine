#include "Canvas.h"

Canvas::Canvas(std::weak_ptr<SDL_Renderer> renderer)
{
	this->renderer = renderer;
}

void Canvas::setColor(const Color& color)
{
	SDL_SetRenderDrawColor(renderer.lock().get(), color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
}

void Canvas::drawLine(int startX, int startY, int endX, int endY)
{
	SDL_RenderDrawLine(renderer.lock().get(), startX, startY, endX, endY);
}
