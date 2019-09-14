// File: catsim_2.cpp
// Created by: Michael Napoli
// Created on: 9/14/2019
// Last modified on:

/*
	Program that displays a simulated cat using SDL
	graphics coding. The user must keep the cat alive
	by any means necessary.
	{inspired by initial text based version)
*/

#include <iostream>
#include <SDL.h>
using namespace std;

// screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char *argv[])
{	
	SDL_Window* window = NULL;  // window to be rendered to
	SDL_Surface* screen = NULL;  // surface contained by window
	
	// returns error code if SDL is not properly initiated
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		cout << "SDL could not initialize! ERROR: " << SDL_GetError() << endl;
	}
	else {
		// create window
		window = SDL_CreateWindow("CAT SIMULATION", SDL_WINDOWPOS_UNDEFINED, 
			SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN ); 
		
		// if window does not initialize, output error
		if (window == NULL) {
			cout << "Window could not be initialized! ERROR: " << SDL_GetError() << endl;
		}
		else {
			// get window surface
			screen = SDL_GetWindowSurface(window);
			
			// make surace white
			SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF));
			
			// update surface
			SDL_UpdateWindowSurface(window);
			
			// wait two seconds
			SDL_Delay(2000);
		}
	}
	
	// close window
	SDL_DestroyWindow(window);
	
	// quit SDL subsystem
	SDL_Quit();
	
	return 0;
}