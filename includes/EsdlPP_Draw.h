#ifndef		ESDLPP_DRAW_H
#define		ESDLPP_DRAW_H

#include <EsdlPP_Engine.h>

class EsdlPP_Draw
{

public:

	static void PutPixel(SDL_Surface &surf, int x, int y, int color);

	static void DrawCircle(SDL_Surface &surf, SDL_Rect rect, int radius, int color);

	static void DrawLine(SDL_Surface &surf, SDL_Rect rect, int color);

	static void DrawFilledSquare(SDL_Surface &surf, SDL_Rect rect, int color);

	static void DrawSquare(SDL_Surface &surf, SDL_Rect rect, int color);
};

#endif