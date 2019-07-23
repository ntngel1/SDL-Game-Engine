#include <SDL.h>
#include <iostream>
#include "Window.h"
#include "Canvas.h"

int main(int argc, char* argv[])
{
	auto window = std::make_shared<Window>();
	auto renderer = std::make_shared<Renderer>(window);
	auto canvas = std::make_shared<Canvas>(renderer->getSDLRenderer());
	renderer->clear();
	canvas->setColor(Color(0x50, 0xFA, 0x00, 0xFF));

	float x = 0;

	while (true) {
		x = x + 0.0005 * (200 - x);
		canvas->setColor(Color(0x00, 0x00, 0x00, 0xFF));
		renderer->clear();
		canvas->setColor(Color(0xFF, 0x00, 0x00, 0xFF));
		canvas->drawLine(0, 0, x, 200);
		canvas->drawLine(200, 0, 200 - x, 200);
		renderer->render();
	}
	SDL_Delay(1500);

	return 0;
}
