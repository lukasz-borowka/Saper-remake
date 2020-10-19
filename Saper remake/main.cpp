/*
Saper game remake made with use of the SDL 2 library
By Lukasz Borowka
*/

#include "GFX/GFX.h"
#include <iostream>

#define FPS 60

int window_w = 640, window_h = 480;

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

	if( (mouse_x > x && mouse_x < x + w) && (mouse_y > y && mouse_y < y + h) ) //check if pointed
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

void Menu_Loop();
void Game_Loop();

int main(int argc, char* argv[])
{

	SDL_Init(SDL_INIT_EVERYTHING);
	GFX_Setup(window_w, window_h);

	Menu_Loop();

	SDL_Quit();
	return 0;
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
		GFX_LimitFps(ticks, FPS); //frame end
	} //while
}

void Game_Loop()
{
}