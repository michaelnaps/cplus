
/* Introduction to event driven programming. */

#include <SDL.h>
#include <iostream>
#include <string>
using namespace std;

// initialization function
bool initialize(SDL_Window* window, SDL_Surface* screen, const int& WIDTH, const int& HEIGHT);

// load media function
bool loadMedia(SDL_Surface* image, const string& filename);

// close down window function
void closeSDL(SDL_Window* window, SDL_Surface* image);

int main()
{
	SDL_Window* user_window = NULL;
	SDL_Surface* user_screen = NULL;	
	SDL_Surface* user_image = NULL;
	
	if (!initialize(user_window, user_screen, 640, 480)) { cout << "ERROR initializing SDL." << endl; }
	else {
		if (!loadMedia(user_image, "hello_world.bmp")) { cout << "ERROR loading image." << endl; }
		else {
			SDL_BlitSurface(user_image, NULL, user_screen, NULL);
			SDL_UpdateWindowSurface(user_window);
			SDL_Delay(2000);
		}
	}
	
	// bool quit(false);  // flag used to exit main while loop
	// SDL_Event event;
	
	closeSDL(user_window, user_image);
	return 0;
}

bool initialize(SDL_Window* window, SDL_Surface* screen, const int& WIDTH, const int& HEIGHT) {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) { 
		cout << "ERROR: " << SDL_GetError() << endl; 
		return false;
	}
	else {
		window = SDL_CreateWindow("New Sim", SDL_WINDOWPOS_UNDEFINED, 
			SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
		
		if (window == NULL) { 
			cout << "Window could not be initialized! ERROR: " << SDL_GetError() << endl; 
			return false;
		}
		else {
			screen = SDL_GetWindowSurface(window);
		}
	}
	
	return true;
}

bool loadMedia(SDL_Surface* image, const string& filename) {
	image = SDL_LoadBMP(filename.c_str());
	
	if (image == NULL) {
		cout << "ERROR: " << SDL_GetError() << endl;
		return false;
	}
	
	return true;
}
	
void closeSDL(SDL_Window* window, SDL_Surface* image) {
	SDL_FreeSurface(image);
	image = NULL;
	
	SDL_DestroyWindow(window);
	window = NULL;
	
	SDL_Quit();
}





























