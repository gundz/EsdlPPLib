#include <EsdlPP_Color.h>

SDL_Color
EsdlPP_Color::IntToSDLColor(int color)
{
	SDL_Color				ret_color;

	ret_color.r = (color >> 24) & 0xFF;
	ret_color.g = (color >> 16) & 0xFF;
	ret_color.b = (color >> 8) & 0xFF;
	ret_color.a = (color) & 0xFF;
	return (ret_color);
}

SDL_Color
EsdlPP_Color::IntToSDLColor(int r, int g, int b, int a)
{
	SDL_Color				ret_color;

	ret_color.r = r;
	ret_color.g = g;
	ret_color.b = b;
	ret_color.a = a;
	return (ret_color);
}

int
EsdlPP_Color::SDLColorToInt(SDL_Color color)
{
	int						ret_color;

	ret_color = 0;
	ret_color = (ret_color << 8) + color.r;
	ret_color = (ret_color << 8) + color.g;
	ret_color = (ret_color << 8) + color.b;
	ret_color = (ret_color << 8) + color.a;
	return (ret_color);
}