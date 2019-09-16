
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
SDL_Surface* loadSurface(string filename);

int main(int argc, char* argv[])
{
	SDL_Window* my_window(NULL);
	SDL_Surface* my_screen(NULL);
	SDL_Surface* current_screen(NULL);

	enum KeyPressSurfaces {
		PRESS_DEFAULT, 
		PRESS_UP, PRESS_DOWN, 
		PRESS_LEFT, PRESS_RIGHT,
		PRESS_TOTAL
	};
	
	// the image that correspoonds to a key press
	SDL_Surface* key_press_surface_T[PRESS_TOTAL];
	
	if (!initialize(my_window, my_screen, 480, 640)) { cout << "ERROR initializing SDL." << endl; }

	// close down all varaibles related to SDL and quit
	
	SDL_FreeSurface(my_screen);  // erase screen variable
	my_screen = NULL;  // set to null pointer
	
	SDL_FreeSurface(current_screen);  // erase screen variable
	current_screen = NULL;  // set to null pointer
	
	for (int i(0); i < PRESS_TOTAL; ++i) {
		SDL_FreeSurface(key_press_surface_T[i]);  // erase screen variable
		key_press_surface_T[i] = NULL;  // set to null pointer
	}
	
	SDL_DestroyWindow(my_window);  // destroy window
	my_window = NULL;  // set to null pointer
	
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

// STOPPED HERE
SDL_Surface* loadSurface(string filename) {
	SDL_Surface* loaded_image = SDL_LoadBMP(filename.c_str());
	if (loaded_image == NULL) {
		cout << "ERROR loading image at " << filename << "." << endl;
		cout << "ERROR: " << SDL_GetError() << endl;
	}
	
	return loaded_image;
}




















