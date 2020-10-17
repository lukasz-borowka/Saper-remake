#include "GFX.h"

/*
GFX_DrawRect:
	SDL_Surface * surface 		temporary sdl surface
	int w, int h 				width & height of the rect
	int x, int y 				x & y pos of the rect, relatively to the window
	int thickness 				thickness of the border of the rect, used only if not filled
								if the fickness is greater that 1 then the other lines are drew inside the rect
	int filled 					gfx flag: GFX_FILLED / GFX_EMPTY
	Uint32 color 				rect color using unsigned integer 32 (red, green, blue)

If the rect is empty (GFX_EMPTY flag) then cals the GFX_DrawLine() function to draw the border of the rect

Grid:
A------B
|      |
D------C	
*/
void GFX_DrawRect(SDL_Surface * surface, int w, int h, int x, int y, int thickness, int filled, Uint32 color)
{	
	if(filled == GFX_FILLED)
	{
		for(int p = 0; p < w; p++)
		{
			for(int q = 0; q < h; q++)
				GFX(surface, x + p, y + q, color);
		}
	}
	else if(filled == GFX_EMPTY & thickness > 0)
	{
		//Repeat drawing lines as long as it's needed
		//So if thickness equals 1 then draws the border only
		//If its greater than 1 then draws more lines
		for(int i = 0; i < thickness; i++)
		{
			GFX_DrawLine(surface, x, y + i, x + w, y + i, color);				// A -- B
			GFX_DrawLine(surface, x, y + h - i, x + w + 1, y + h - i, color);	// D -- C
			GFX_DrawLine(surface, x + i, y, x + i, y + h, color);				// A -- D
			GFX_DrawLine(surface, x + w - i, y, x + w - i, y + h, color);		// B -- C
		}
	}
}