#pragma once

#include <SDL.h>

/* --- --- --- ---
GFX funcs:
	GFX_DrawLine:
		(surface, px, py, qx, qy, color)

	GFX_DrawRect:
		(surface, w, h, x, y, thickness, filled, color)

	GFX_LimitFps:
		(ticks, fps)
*/
#include "GFX.cpp"
#include "GFX_DrawLine.cpp"
#include "GFX_DrawRect.cpp"
#include "GFX_LimitFps.cpp"

//
//DEFINES:
#define GFX_FILLED 1
#define GFX_EMPTY 2

//
//COLORS:
//default:
#define col_black SDL_MapRGB(surface->format, 0, 0, 0)
#define col_white SDL_MapRGB(surface->format, 255, 255, 255)
#define col_light_gray SDL_MapRGB(surface->format, 180, 180, 180)
#define col_mid_gray SDL_MapRGB(surface->format, 110, 110, 110)
#define col_dark_gray SDL_MapRGB(surface->format, 50, 50, 50)
//red:
#define col_full_red SDL_MapRGB(surface->format, 255, 0, 0)
//green:
#define col_full_green SDL_MapRGB(surface->format, 0, 255, 0)
//blue:
#define col_full_blue SDL_MapRGB(surface->format, 0, 0, 255)

//
//FUNCS:
void GFX(SDL_Surface * surface, int x, int y, Uint32 color);
void GFX_DrawLine(SDL_Surface * surface, int px, int py, int qx, int qy, Uint32 color);
void GFX_DrawRect(SDL_Surface * surface, int w, int h, int x, int y, int thickness, int filled, Uint32 color);
void GFX_LimitFps(Uint32 ticks, int fps);