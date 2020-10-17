/*
	surface 		surface to draw the point on
	int x			x pos of the point
	int y 			y pos of the point
	Uint32 color	color of the point
*/
void GFX(SDL_Surface * surface, int x, int y, Uint32 color)
{
	if (x > -1 & y > -1 & x < window_w & y < window_h)
	{
		Uint32 * p = (Uint32 *)surface->pixels + y * surface->w + x;
		*p = color;
	}
}