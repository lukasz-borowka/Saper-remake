#include "GFX.h"

int Window_Width = 0, Window_Height = 0;

/*
	surface 		surface to draw the point on
	int x			x pos of the point
	int y 			y pos of the point
	Uint32 color	color of the point
*/
void GFX(SDL_Surface * surface, int x, int y, Uint32 color)
{
	if (x > -1 & y > -1 & x < Window_Width & y < Window_Height)
	{
		Uint32 * p = (Uint32 *)surface->pixels + y * surface->w + x;
		*p = color;
	}
}

//
//GFX SETUP:
void GFX_Setup(int w, int h)
{
	Window_Width = w;
	Window_Height = h;
}