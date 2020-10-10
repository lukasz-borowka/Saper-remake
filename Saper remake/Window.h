#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <locale.h>

class Window
{
private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	bool isRunning;

public:
	Window(const char* title = "Saper Remake by Lukasz Borowka",
		int x = SDL_WINDOWPOS_CENTERED,
		int y = SDL_WINDOWPOS_CENTERED,
		int w = 800, int h = 600);

	~Window();

	bool running() { return isRunning; }
};

Window::Window(const char* title, int x, int y, int w, int h) {
	isRunning = true;

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) std::cout << "Starting SDL... 100%" << std::endl;
	else {
		std::cout << "SDL_Init error...";
		isRunning = false;
	}

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
}
