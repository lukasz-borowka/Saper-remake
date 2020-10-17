#include "GFX.h"

/*
GFX_DrawLine:
	SDL_Surface * surface 		temporary sdl surface
	int px, int py 				x & y pos of the first (p) point
	int qx, int qy 				x & y pos of the second (q) point
	Uint32 color 				line color using unsigned integer 32 (red, green, blue)
*/
void GFX_DrawLine(SDL_Surface * surface, int px, int py, int qx, int qy, Uint32 color)
{
	double a1 = qy - py, a2 = qx - px;
	//double a = a1 / a2; 			<-- Moved down to if
	if(a2 != 0)
	{
		if(a1 / a2 <= 1) //F(X) func
		{
			double a = a1 / a2;
			double b = py - (a * px);
			int domain = 0, base = 0;
			if((qx - px) < 0) { domain -= (qx - px); base = qx; }
			else { domain += (qx - px); base = px; }

			for(int i = 0; i < domain; i++)
			{
				int y = (i + base) * a + b;
				GFX(surface, i + base, y, color);
			}
		}
		else //Here the a is to large so there would be spaces between the points, so we treat it as F(Y) func to avoid that
		{
			double a = a2 / a1;
			double b = px - (a * px);
			int domain = 0, base = 0;
			if((qy - py) < 0) { domain -= (qy - py); base = qy; }
			else { domain += (qy - py); base = py; }

			for(int i = 0; i < domain; i++)
			{
				int x = (i + base) * a + b;
				GFX(surface, x, i + base, color);
			}
		}
	}
	else //If a2 = 0 then a1 can't be dividen by a2, so we just asume that it has to be the F(Y) func w/ a == 0
	{
		double a = 0;
		double b = px - (a * px);
		int domain = 0, base = 0;
		if((qy - py) < 0) { domain -= (qy - py); base = qy; }
		else { domain += (qy - py); base = py; }

		for(int i = 0; i < domain; i++)
		{
			int x = (i + base) * a + b;
			GFX(surface, x, i + base, color);
		}
	}
}