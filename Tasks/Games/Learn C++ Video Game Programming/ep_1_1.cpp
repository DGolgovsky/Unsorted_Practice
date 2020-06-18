// Using SDL and standard IO
#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>

// Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
typedef struct
{
	int x, y;
	short life;
	char *name;
} Man;

typedef struct
{
	int x, y;
} Enemy;

Enemy e = {20, 20};

int processEvents(SDL_Window *window, Man *man) {
	SDL_Event event;
	int done = 0;

	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_WINDOWEVENT_CLOSE: {
				if (window) {
					SDL_DestroyWindow(window);
					window = NULL;
					done = 1;
				}
			}
				break;
			case SDL_KEYDOWN: {
				switch (event.key.keysym.sym) {
					case SDLK_ESCAPE:
						done = 1;
						break;
				}
			}
				break;
			case SDL_QUIT:
				// Quit out of the game
				done = 1;
				break;
		}
	}

	const Uint8 *state = SDL_GetKeyboardState(NULL);
	if (state[SDL_SCANCODE_LEFT]) {
		man->x -= 10;
	}
	if (state[SDL_SCANCODE_RIGHT]) {
		man->x += 10;
	}
	if (state[SDL_SCANCODE_UP]) {
		man->y -= 10;
	}
	if (state[SDL_SCANCODE_DOWN]) {
		man->y += 10;
	}
}

void draw(SDL_Renderer *renderer, Man *man) {
	// Set the drawing color to white
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	SDL_Rect rect = {man->x, man->y, 200, 200};
	SDL_RenderFillRect(renderer, &rect);
}

void draw(SDL_Renderer *renderer, Enemy *enemy) {
	// Set the drawing color to red
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

	SDL_Rect rect = {enemy->x, enemy->y, 100, 100};
	SDL_RenderFillRect(renderer, &rect);
}

void doRender(SDL_Renderer *renderer, Man *man) {
	// Set the drawing color to blue
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

	// Clear the screen (to blue)
	SDL_RenderClear(renderer);

	draw(renderer, man);
	draw(renderer, &e);

	/*
	 * We are done drawing, "present" or show to the screen
	 * what we've draw
	 */
	SDL_RenderPresent(renderer);
}

int main(int argc, char **argv) {
	SDL_Window *window = NULL;        // Declare a window
	SDL_Renderer *renderer = NULL;    // Declare a renderer

	if (SDL_Init(SDL_INIT_VIDEO) < 0) { // Initialize SDL2
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}

	Man man;
	man.x = 220;
	man.y = 110;

	// Create an application window with the following settings:
	window = SDL_CreateWindow("Game Window", // window title
							  SDL_WINDOWPOS_UNDEFINED,         // initial x position
							  SDL_WINDOWPOS_UNDEFINED,        // initial y position
							  SCREEN_WIDTH,                    // width, in pixels
							  SCREEN_HEIGHT,                   // height, in pixels
							  0);                              // flags
	if (window == NULL) {
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	// The window is open: enter program loop (see SDL_PollEvent)
	int done = 0;

	// Event loop
	while (!done) {
		// Check for events
		done = processEvents(window, &man);

		// Render display
		doRender(renderer, &man);

		// don't burn up the CPU ;-)
		SDL_Delay(10);
	}

	// Close and destroy the window
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	// Quit SDL subsystems
	SDL_Quit();

	return 0;
}
