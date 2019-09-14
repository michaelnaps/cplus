#include <iostream>
#include <SDL.h>
using namespace std;

int main(int argc, char *argv[])
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		cout << "ERROR: " << SDL_GetError() << endl;
	}
	
	system("pause");
	
	return EXIT_SUCCESS;
}