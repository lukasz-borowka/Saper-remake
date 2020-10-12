/*
Saper game remake made with use of the SDL 2 library
By Lukasz Borowka
*/

#include <SDL.h>
#include <iostream>

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
SDL_Texture * texture = NULL;
SDL_Renderer * renderer = NULL;
SDL_Event ev;

int window_w = 640, window_h = 480;

void Menu_Loop()
{
	bool quit = false;
	while(!quit){ }
}

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow("Saper by Lukasz Borowka", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_w, window_h, NULL);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, window_w, window_h);

	Uint32 * pixels;
	pixels = new Uint32 [window_w * window_h];
	memset(pixels, 255, window_w * window_h * sizeof(Uint32));
	delete[] pixels;
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);


	bool quit = false, left_mouse_button_down = false;

	while(!quit){
		SDL_UpdateTexture(texture, NULL, pixels, window_w * sizeof(Uint32));

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
				pixels[mouse_y * window_w + mouse_x] = SDL_Color(0, 0, 0);
			}
			break;

		case SDL_QUIT:
			quit = true;
			break;
		} //switch

		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
	} //while


	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
	/*setlocale(LC_CTYPE, "Polish");

	Window Menu_Window;

	SDL_Delay(7000);

	return EXIT_SUCCESS;*/
}