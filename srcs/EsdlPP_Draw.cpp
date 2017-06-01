#include <EsdlPP_Draw.h>

void
EsdlPP_Draw::PutPixel(SDL_Surface &surf, int x, int y, int color)
{
	Uint32		*pixels;

	if ((x >= 0 && y >= 0) && (x < surf.w && y < surf.h))
	{
		pixels = (Uint32 *)surf.pixels;
		pixels[(y * surf.w) + x] = color;
	}
}

void
EsdlPP_Draw::DrawCircle(SDL_Surface &surf, SDL_Rect rect, int radius, int color)
{
	int			x;
	int			y;
	int			m;

	x = 0;
	y = radius;
	m = 5 - 4 * radius;
	while (x <= y)
	{
		PutPixel(surf, x + rect.x, y + rect.y, color);
		PutPixel(surf, y + rect.x, x + rect.y, color);
		PutPixel(surf, -x + rect.x, y + rect.y, color);
		PutPixel(surf, -y + rect.x, x + rect.y, color);
		PutPixel(surf, x + rect.x, -y + rect.y, color);
		PutPixel(surf, y + rect.x, -x + rect.y, color);
		PutPixel(surf, -x + rect.x, -y + rect.y, color);
		PutPixel(surf, -y + rect.x, -x + rect.y, color);
		if (m > 0)
		{
			y -= 1;
			m = m - 8 * y;
		}
		x += 1;
		m += 8 * x + 4;
	}
}

void
EsdlPP_Draw::DrawLine(SDL_Surface &surf, SDL_Rect rect, int color)
{
	SDL_Point	d;
	SDL_Point	s;
	int			err;
	int			e2;

	d.x = abs(rect.w - rect.x);
	d.y = abs(rect.h - rect.y);
	s.x = (rect.x < rect.w ? 1 : -1);
	s.y = (rect.y < rect.h ? 1 : -1);
	err = d.x - d.y;
	while (rect.x != rect.w || rect.y != rect.h)
	{
		PutPixel(surf, rect.x, rect.y, color);
		if ((e2 = 2 * err) > -d.y)
			err -= (d.y + 0 * (rect.x += s.x));
		if (rect.x == rect.w && rect.y == rect.h)
		{
			PutPixel(surf, rect.x, rect.y, color);
			return ;
		}
		if (e2 < d.x)
			err += (d.x + 0 * (rect.y += s.y));
	}
}

void
EsdlPP_Draw::DrawSquare(SDL_Surface &surf, SDL_Rect rect, int color)
{
	for (int i = 0; i < rect.h; i++)
	{
		for (int j = 0; j < rect.w; j++)
		{
			if ((i == 0 || i == rect.h - 1) || (j == 0 || j == rect.w - 1))
				PutPixel(surf, j + rect.x, i + rect.y, color);
		}
	}
}

void
EsdlPP_Draw::DrawFilledSquare(SDL_Surface &surf, SDL_Rect rect, int color)
{
	for (int i = 0; i < rect.h; i++)
	{
		for (int j = 0; j < rect.w; j++)
		{
			PutPixel(surf, j + rect.x, i + rect.y, color);
		}
	}
}