
/* Introduction to key-type events applying changes to SDL window. */

#include <SDL.h>
#include <iostream>
#include <string>
using namespace std;

// SDL INITIALIZATION AND CLOSE FUNCTIONS

// initialization function
bool initialize(SDL_Window* window, SDL_Surface* screen, const int& WIDTH, const int& HEIGHT);

// load media function
bool loadMedia(SDL_Surface* image, const string& filename);

// loads individual image
SDL_Surface* loadSurface(string filename);  // STOPPED HERE

int main(int argv, char* argc[])
{
	SDL_Window* my_window(NULL);
	SDL_Surface* my_screen(NULL);
	
	enum KeyPressSurfaces {
		PRESS_DEFAULT, 
		PRESS_UP, PRESS_DOWN, 
		PRESS_LEFT, PRESS_RIGHT,
		PRESS_TOTAL
	}
	
	// close down all varaibles related to SDL and quit
	
	SDL_FreeSurface(my_screen);  // erase screen variable
	my_screen = NULL;
	
	SDL_DestroyWindow(my_window);  // destroy window
	window = NULL;  // set to null
	
	SDL_Quit();  // clear out memory from variables

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

// FUNCTION DEFINITION: 'closeSDL()'
// function closes given variables for SDL windows and screens
// 'window' - window variable that will be closed
// 'image' - image varaible that will be erased from memory
void closeSDL(SDL_Window* window, SDL_Surface* image) {
	SDL_FreeSurface(image);  // erase image
	image = NULL;  // set to null
	
	SDL_DestroyWindow(window);  // destroy window
	window = NULL;  // set to null
	
	SDL_Quit();  // clear out memory from variables
}