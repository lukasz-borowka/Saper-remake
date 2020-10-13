/*
Saper game remake made with use of the SDL 2 library
By Lukasz Borowka
*/

#include <SDL.h>
#include <iostream>

#define GFX_FILLED 1
#define GFX_EMPTY 2

/*class Window
{
private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	int width, height;

	bool isRunning;

public:
	Window(const char* title = "Saper Remake by Lukasz Borowka",
		int x = SDL_WINDOWPOS_CENTERED,
		int y = SDL_WINDOWPOS_CENTERED,
		int w = 800, int h = 600);

	~Window();

	bool running() { return isRunning; }
	int Height() { return height; }
	int Width() { return width; }
};
/////////////////////////////////////////////////////////////////////////////////////////////

Window::Window(const char* title, int x, int y, int w, int h) {
	isRunning = true;

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) std::cout << "Starting SDL... 100%" << std::endl;
	else {
		std::cout << "SDL_Init error...";
		isRunning = false;
	}

	width = w;
	height = h;

	window = SDL_CreateWindow(title, x, y, w, h, NULL);
	if ((SDL_GetError() != 0) & isRunning) std::cout << "Creating window... 100%" << std::endl;
	else
	{
		std::cout << "Window error...";
		isRunning = false;
	}


}

Window::~Window()
{
}*/

SDL_Window * window = NULL;
SDL_Surface * surface = NULL;
//SDL_Texture * texture = NULL;
//SDL_Renderer * renderer = NULL;
SDL_Event ev;

//Colors
Uint32 Black;
Uint32 White;

int window_w = 640, window_h = 480;

//////// DRAWING FUNCTIONS
void GFX(SDL_Surface * surface, int x, int y, Uint32 color)
{
	if (x > -1 & y > -1 & x < window_w & y < window_h) {
		Uint32 * p = (Uint32 *)surface->pixels + y * surface->w + x;
		*p = color;
	}
}
void GFX_DrawLine(SDL_Surface * surface, int px, int py, int qx, int qy, Uint32 color)
{
	/*
	GFX_DrawLine:
		SDL_Surface * surface 		temporary sdl surface
		int px, int py 				x & y pos of the first (p) point
		int qx, int qy 				x & y pos of the second (q) point
		Uint32 color 				line color using unsigned integer 32 (red, green, blue)
	*/

	
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
		for(int p = 0, p < w, p++)
		{

		}
	}
	else if(filled == GFX_EMPTY)
	{

	}
}

void Menu_Loop();
void Game_Loop();

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow("Saper by Lukasz Borowka", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_w, window_h, NULL);
	surface = SDL_GetWindowSurface(window);
	
	/*renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, window_w, window_h);

	Uint32 * pixels;
	pixels = new Uint32 [window_w * window_h];
	memset(pixels, 255, window_w * window_h * sizeof(Uint32));
	delete[] pixels;
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);*/

	//Colors
	Black = SDL_MapRGB(surface->format, 0, 0, 0);
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

	//SDL_DestroyWindow(window);
	//window = SDL_CreateWindow("Saper by Lukasz Borowka", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 100, 100, NULL);
	//SDL_Delay(4000);

	SDL_DestroyWindow(window);
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
}







void Game_Loop()
{
}