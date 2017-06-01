#ifndef		ESDLPP_COLOR_H
#define		ESDLPP_COLOR_H

#include <EsdlPP_Engine.h>

class EsdlPP_Color
{

public:

	static SDL_Color IntToSDLColor(int color);
	static SDL_Color IntToSDLColor(int r, int g, int b, int a);

	static int SDLColorToInt(SDL_Color color);
};

#endif