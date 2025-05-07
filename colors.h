#ifndef COLORS_H
#define COLORS_H

struct Color
{
	unsigned int r;
	unsigned int g;
	unsigned int b;
	unsigned int a;
};

inline Color color(unsigned int r, unsigned int g, unsigned int b, unsigned int a)
{
	Color result;
	result.r = r;
	result.g = g;
	result.b = b;
	result.a = a;
	return result;
}

const Color BARELY_BLACK = {
	color(22, 22, 22, 255)
};

const Color DARK_GREY = {
	color(44, 44, 44, 255)
};

#endif