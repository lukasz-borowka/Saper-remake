/*
Saper game remake made with use of the SDL 2 library
By Lukasz Borowka
*/

#include "GFX/GFX.h"
#include <iostream>

#define FPS 60

int window_w = 640, window_h = 480;

//////// DRAWING FUNCTIONS ; GFX

void GFX_DrawLine(SDL_Surface * surface, int px, int py, int qx, int qy, Uint32 color)
{
	/*
	GFX_DrawLine:
		SDL_Surface * surface 		temporary sdl surface
		int px, int py 				x & y pos of the first (p) point
		int qx, int qy 				x & y pos of the second (q) point
		Uint32 color 				line color using unsigned integer 32 (red, green, blue)
	*/

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
void GFX_DrawRect(SDL_Surface * surface, int w, int h, int x, int y, int thickness, int filled, Uint32 color)
{
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
	*/
	
	if(filled == GFX_FILLED)
	{
		for(int p = 0; p < w; p++)
		{
			for(int q = 0; q < h; q++)
				GFX(surface, x + p, y + q, color);
		}
	}
	else if(filled == GFX_EMPTY)
	{
		//If the thickness equals 1, then just draw the border which consists of 4 lines
		if(thickness == 1)
		{
			/*
			A------B
			|      |
			D------C
			*/
			GFX_DrawLine(surface, x, y, x + w, y, color);				// A -- B
			GFX_DrawLine(surface, x, y + h, x + w + 1, y + h, color);	// D -- C
			GFX_DrawLine(surface, x, y, x, y + h, color);				// A -- D
			GFX_DrawLine(surface, x + w, y, x + w, y + h, color);		// B -- C
		}
		//If the thickness is greater that 1, then draw amount of lines that's needed
		else if(thickness > 1)
		{
			//Repeat drawing lines as long as it's needed
			for(int i = 0; i < thickness; i++)
			{
				GFX_DrawLine(surface, x, y + i, x + w, y + i, color);				// A -- B
				GFX_DrawLine(surface, x, y + h - i, x + w + 1, y + h - i, color);	// D -- C
				GFX_DrawLine(surface, x + i, y, x + i, y + h, color);				// A -- D
				GFX_DrawLine(surface, x + w - i, y, x + w - i, y + h, color);		// B -- C
			}
		}
	}
}

void Draw_Button(SDL_Surface * surface, int w, int h, int x, int y, int mouse_x, int mouse_y, bool clicked, Uint32 color)
{
	/*
	Draw_Button:
		SDL_Surface * surface 		temporary sdl surface
		int w, int h 				width & height of the button
		int x, int y 				x & y pos of the button, relatively to the window
		int mouse_x, int mouse_y	x & y pos of the cursor ; it is used to check if the button is pointed
		bool clicked				along with mouse_x & mouse_y is used to check if the button is clicked
		Uint32 color 				rect color using unsigned integer 32 (red, green, blue)
	*/

	Uint32 back_color = col_dark_gray;
	int button_height = 10;

	if( (mouse_x > x & mouse_x < x + w) & (mouse_y > y & mouse_y < y + h) ) //check if pointed
	{
		if(clicked)
		{
			GFX_DrawRect(surface, w, h - button_height, x, y + button_height, 0, GFX_FILLED, color);
		}
		else
		{
		/*CODE LATER*/
			GFX_DrawRect(surface, w, h, x, y, 1, GFX_FILLED, back_color);
			GFX_DrawRect(surface, w, h - button_height, x, y, 1, GFX_FILLED, color);
		}
	}
	else
	{
		GFX_DrawRect(surface, w, h, x, y, 1, GFX_FILLED, back_color);
		GFX_DrawRect(surface, w, h - button_height, x, y, 1, GFX_FILLED, color);
	}
}

void limitfps(Uint32 ticks)
{
	if ((1000 / fps) > SDL_GetTicks() - ticks) {
		SDL_Delay(1000 / fps - (SDL_GetTicks() - ticks));
	}
}

void Menu_Loop();
void Game_Loop();

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);

	Menu_Loop();

	//window = SDL_CreateWindow("Saper by Lukasz Borowka", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_w, window_h, NULL);
	//surface = SDL_GetWindowSurface(window);
	
	/*renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, window_w, window_h);

	Uint32 * pixels;
	pixels = new Uint32 [window_w * window_h];
	memset(pixels, 255, window_w * window_h * sizeof(Uint32));
	delete[] pixels;
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);*/

	//Colors
	/*Black = SDL_MapRGB(surface->format, 0, 0, 0);
	White = SDL_MapRGB(surface->format, 255, 255, 255);

	SDL_FillRect(surface, NULL, White);

	bool quit = false, left_mouse_button_down = false;

	while(!quit){
		//SDL_UpdateTexture(texture, NULL, pixels, window_w * sizeof(Uint32));
		

		SDL_WaitEvent(&ev);
		switch(ev.type)
		{
		case SDL_MOUSEBUTTONUP:
			if(ev.button.button == SDL_BUTTON_LEFT)
				left_mouse_button_down = false;
			break;

		case SDL_MOUSEBUTTONDOWN:
			if(ev.button.button == SDL_BUTTON_LEFT)
				left_mouse_button_down = true;
			break;

		case SDL_MOUSEMOTION:
			if(left_mouse_button_down)
			{
				int mouse_x = ev.motion.x;
				int mouse_y = ev.motion.y;
				gfx(mouse_x, mouse_y);
			}
			break;

		case SDL_QUIT:
			quit = true;
			break;
		} //switch

		SDL_UpdateWindowSurface(window);

		//SDL_RenderClear(renderer);
		//SDL_RenderCopy(renderer, texture, NULL, NULL);
		//SDL_RenderPresent(renderer);
	} //while
	*/
	//SDL_DestroyWindow(window);
	//window = SDL_CreateWindow("Saper by Lukasz Borowka", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 100, 100, NULL);
	//SDL_Delay(4000);

	//SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
	/*setlocale(LC_CTYPE, "Polish");

	Window Menu_Window;

	SDL_Delay(7000);

	return EXIT_SUCCESS;*/
}

void Menu_Loop()
{
	/*
	The main menu loop:
		Creates its window, and surface
		Draws buttons:
			Play button
		When Play clicked it calls the Game_Loop() function

		Colors: White, Gray, Black, Light_Gray, Orange, Light_Blue;
	*/

// DECLARATIONS:
	SDL_Window * window = NULL;
	SDL_Surface * surface = NULL;
	SDL_Event event;

	bool quit = false, left_button_down = false;
	int window_w = 640, window_h = 480, mouse_x = 0, mouse_y = 0;

// INITIALIZE:
	window = SDL_CreateWindow("Saper", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_w, window_h, NULL);
	surface = SDL_GetWindowSurface(window);

// COLORS:
	//Currently there is no need to declare colors, they're preprocesed using define
	//Uint32 black = SDL_MapRGB(surface->format, 0, 0, 0);
	//Uint32 white = SDL_MapRGB(surface->format, 255, 255, 250);
	//Uint32 red = SDL_MapRGB(surface->format, 255, 0, 0);

	SDL_FillRect(surface, NULL, col_white);
	//GFX_DrawLine(surface, 0, 0, 200, 200, black);
	//GFX_DrawRect(surface, 200, 300, 10, 10, 1, GFX_FILLED, red);

// LOOP:
	while(!quit)
	{
		Uint32 ticks = SDL_GetTicks(); //frame start
		SDL_WaitEvent(&event);
		switch(event.type)
		{
		case SDL_MOUSEBUTTONUP:
			left_button_down = false;
			break;

		case SDL_MOUSEBUTTONDOWN:
			left_button_down = true;
			break;

		case SDL_MOUSEMOTION:
			mouse_x = event.motion.x;
			mouse_y = event.motion.y;
			//std::cout << mouse_x << "   " << mouse_y << std::endl;
			break;

		case SDL_QUIT:
			quit = true;
			break;
		} //switch
		//SDL_GetMouseState(&mouse_x, &mouse_y);
		//std::cout << mouse_x << "   " << mouse_y << "   " << left_button_down << std::endl;

		SDL_FillRect(surface, NULL, col_white);

		//Some lines
		GFX_DrawLine(surface, 0, 0, 100, 400, col_black);
		GFX_DrawLine(surface, 0, 0, 400, 100, col_black);
		GFX_DrawLine(surface, 100, 100, 100, 300, col_mid_gray);

		GFX_DrawRect(surface, 150, 50, 50, 50, 8, GFX_EMPTY, col_full_green);

		//Start button
		Draw_Button(surface, 300, 120, 150, 150, mouse_x, mouse_y, left_button_down, col_full_red);

		SDL_UpdateWindowSurface(window);
		limitfps(ticks); //frame end
	} //while
}

void Game_Loop()
{
}