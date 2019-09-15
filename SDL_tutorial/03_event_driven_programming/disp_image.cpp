
/* Display an image using SDL window commands. */

#include <SDL.h>
#include <iostream>
using namespace std;

// starts up SDL and creates window
bool init();

// loads media
bool loadMedia();

// frees media and shuts down SDL
void closeSDL();

// GLOBAL VARIABLES
SDL_Window* gwindow = NULL;  // window to be opened
SDL_Surface* gscreen = NULL;  // surface to be used
SDL_Surface* gimage = NULL;  // image to be loaded in

int SCREEN_WIDTH = 640;
int SCREEN_HEIGHT = 480;

int main(int argv, char *argc[])
{	
	// start up SDL, create window
	if (!init()) {
		cout << "ERROR initializing!" << endl;
	}
	else {
		// load media
		if (!loadMedia()) {
			cout << "ERROR loading media!" << endl;
		}
		else {
			// apply image
			SDL_BlitSurface(gimage, NULL, gscreen, NULL);
			
			// update surface
			SDL_UpdateWindowSurface(gwindow);
			SDL_Delay(2000);
		}
	}
	
	// close down system
	closeSDL();
	
	return 0;
}

bool init() {
	bool success = true;
		
	// returns error code if SDL is not properly initiated
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		cout << "SDL could not initialize! ERROR: " << SDL_GetError() << endl;
		success = false;
	}
	else {
		// create window
		gwindow = SDL_CreateWindow("CAT SIMULATION", SDL_WINDOWPOS_UNDEFINED, 
			SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN ); 
		
		// if window does not initialize, output error
		if (gwindow == NULL) {
			cout << "Window could not be initialized! ERROR: " << SDL_GetError() << endl;
			success = false;
		}
		else {
			// get window surface
			gscreen = SDL_GetWindowSurface(gwindow);
		}
	}
	
	return success;  // return success statement
}

bool loadMedia() {
	bool success = true;
	
	// load splash image
	gimage = SDL_LoadBMP("hello_world.bmp");
	
	// if image is not loaded in correctly
	if (gimage == NULL) {
		cout << "ERROR loading image: " << SDL_GetError() << endl;
		success = false;
	}
	
	return success;  // return success statement
}

void closeSDL() {
	// deallocated surface
	SDL_FreeSurface(gimage);
	gimage = NULL;
	
	// destroy window
	SDL_DestroyWindow(gwindow);
	gwindow = NULL;
	
	// quit SDL
	SDL_Quit();
}




























