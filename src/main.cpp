#define SDL_MAIN_HANDLED

#include <iostream>

#include <SDL2/SDL.h>


int main(int argc, char* argv[]) {
	if (!SDL_INIT_EVERYTHING) {
		std::cout << SDL_GetError();
	}

	SDL_Window *window = SDL_CreateWindow("Dadoraria",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		1280, 
		720,
		0);

	bool quit = false;
	SDL_Event ev{};

	while (!quit) {
		SDL_PollEvent(&ev);
		switch (ev.type) {

		case SDL_QUIT:
			quit = true;
			break;

		default:
			break;
		}
		
	}
		
	return 0;
}