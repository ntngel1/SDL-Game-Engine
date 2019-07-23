#pragma once

#include <cstdint>

class Color
{
public:
	Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 0xFF);

	[[nodiscard]] uint8_t getRed() const { return this->red; }
	[[nodiscard]] uint8_t getGreen() const { return this->green; }
	[[nodiscard]] uint8_t getBlue() const { return this->blue; }
	[[nodiscard]] uint8_t getAlpha() const { return this->alpha; }

private:
	uint8_t red, green, blue, alpha;
};
