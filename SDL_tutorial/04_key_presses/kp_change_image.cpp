
/* Introduction to key-type events applying changes to SDL window. */

#include <SDL.h>
#include <iostream>
#include <string>
using namespace std;

// SDL INITIALIZATION AND CLOSE FUNCTIONS

// initialization function
bool initialize(SDL_Window* window, SDL_Surface* screen, const int& WIDTH, const int& HEIGHT);

// loads individual image
SDL_Surface* loadImage(string filename);

int main(int argc, char* argv[])
{
	bool CONTINUE(true);
	SDL_Window* my_window(NULL);
	SDL_Surface* my_screen(NULL);
	SDL_Surface* current_screen(NULL);

	enum KeyPressSurfaces {
		PRESS_DEFAULT, 
		PRESS_UP, 
		PRESS_DOWN, 
		PRESS_LEFT, 
		PRESS_RIGHT,
		PRESS_TOTAL
	};
	
	// the image that correspoonds to a key press
	SDL_Surface* kp_surface[PRESS_TOTAL];
	
	// intialize the window being used to display the game
	if (!initialize(my_window, my_screen, 640, 480)) { cout << "ERROR initializing SDL." << endl; }
	else {
		// load images into apprpriate surface array
		kp_surface[PRESS_DEFAULT] = loadImage("press.bmp");
		kp_surface[PRESS_UP] = loadImage("up.bmp");
		kp_surface[PRESS_DOWN] = loadImage("down.bmp");
		kp_surface[PRESS_LEFT] = loadImage("left.bmp");
		kp_surface[PRESS_RIGHT] = loadImage("right.bmp");
		
		// check all array points for NULL spaces a.k.a. the iamge was not loaded
		for (int i(0); i < PRESS_TOTAL; ++i) {
			if (kp_surface[i] == NULL) { 
				cout << "ERROR: Image " << i << " did not load correctly." << endl; 
				CONTINUE = false;
			}
		}
		
		if (CONTINUE) {
			// begin main loop with window set as default surface image
			SDL_Event kp;
			
			while (CONTINUE) {
				while (SDL_PollEvent(&kp) != 0) {
					// user requests quit via window 'x'
					if (kp.type == SDL_QUIT) { CONTINUE = false; }
					
					// user presses a key
					else if (kp.type == SDL_KEYDOWN) {
						switch(kp.key.keysym.sym) {
							case SDLK_UP:
							current_screen = kp_surface[PRESS_UP];
							break;
							
							case SDLK_DOWN:
							current_screen = kp_surface[PRESS_DOWN];
							break;
							
							case SDLK_LEFT:
							current_screen = kp_surface[PRESS_LEFT];
							break;
							
							case SDLK_RIGHT:
							current_screen = kp_surface[PRESS_RIGHT];
							break;
							
							default:
							current_screen = kp_surface[PRESS_DEFAULT];
							break;
						}
					}
					
					// apply changes
					SDL_BlitSurface(current_screen, NULL, my_screen, NULL);
					SDL_UpdateWindowSurface(my_window);
				}
			}
		}
	}

	// close down all varaibles related to SDL and quit
	SDL_FreeSurface(my_screen);  // erase screen variable
	my_screen = NULL;  // set to null pointer
	
	SDL_FreeSurface(current_screen);  // erase screen variable
	current_screen = NULL;  // set to null pointer
	
	for (int i(0); i < PRESS_TOTAL; ++i) {
		SDL_FreeSurface(kp_surface[i]);  // erase screen variable
		kp_surface[i] = NULL;  // set to null pointer
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

SDL_Surface* loadImage(string filename) {
	SDL_Surface* loaded_image = SDL_LoadBMP(filename.c_str());
	if (loaded_image == NULL) {
		cout << "ERROR loading image at " << filename << "." << endl;
		cout << "ERROR: " << SDL_GetError() << endl;
	}

	return loaded_image;
}




















