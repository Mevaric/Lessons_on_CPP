// SimpleSnake.cpp : Defines the entry point for the console application.
//



// NOT WORK YET
#include "stdafx.h"
#include <iostream>
#define SDL_MAIN_HANDLED
#include <SDL.h>


int main()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window * window = SDL_CreateWindow("snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
	SDL_Renderer * render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	bool runing = true;

	while (runing) {
	
	}
    return 0;
}



