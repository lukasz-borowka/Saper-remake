#pragma once

#include <SDL.h>

int Window_Width = 0, Window_Height = 0;

//
//DEFINES:
#define GFX_FILLED 1
#define GFX_EMPTY 2

//
//Including .h file w/ colors
#include "GFX_Colors.h"

/* --- --- --- ---
GFX funcs:
	GFX_DrawLine:
		(surface, px, py, qx, qy, color)

	GFX_DrawRect:
		(surface, w, h, x, y, thickness, filled, color)

	GFX_LimitFps:
		(ticks, fps)
*/
//#include "GFX.cpp"
//#include "GFX_DrawLine.cpp"
//#include "GFX_DrawRect.cpp"
//#include "GFX_LimitFps.cpp"

//
//FUNCS:
void GFX_Setup(int w, int h);
void GFX(SDL_Surface * surface, int x, int y, Uint32 color);
void GFX_DrawLine(SDL_Surface * surface, int px, int py, int qx, int qy, Uint32 color);
void GFX_DrawRect(SDL_Surface * surface, int w, int h, int x, int y, int thickness, int filled, Uint32 color);
void GFX_LimitFps(Uint32 ticks, int fps);

//
//GFX SETUP:
void GFX_Setup(int w, int h)
{
	Window_Width = w;
	Window_Height = h;
}