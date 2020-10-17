#include "GFX.h"

/*
Simple fps limiter

It requires Uint32 input wich needs to be set in the beginning of the frame, by:
	Uint32 ticks = SDL_GetTicks();

Also gets int fps input which is just max fps
*/
void GFX_LimitFps(Uint32 ticks, int fps)
{
	if ((1000 / fps) > SDL_GetTicks() - ticks)
	{
		SDL_Delay(1000 / fps - (SDL_GetTicks() - ticks));
	}
}