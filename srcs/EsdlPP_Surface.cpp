#include <EsdlPP_Surface.h>

void
EsdlPP_Surface::ClearSurface(SDL_Surface &surf, int color)
{
	for (int i = 0; i < surf.h; i++)
	{
		for (int j = 0; j < surf.w; j++)
		{
			EsdlPP_Draw::PutPixel(surf, j, i, color);
		}
	}
}