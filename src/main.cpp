#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include <vector>
#include <time.h>
#include <cmath>

#include "RenderWindow.hpp"
#include "Utils.hpp"
#include "Text.hpp"
#include "Math.hpp"
#include "Entity.hpp"
#include "Constants.hpp"

int main(int argc, char* args[]){
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		std::cout << "HEY.. SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl; 

	if (!(IMG_Init(IMG_INIT_PNG)))
		std::cout << "IMG_Init HAS FAILED. Error: " << SDL_GetError() << std::endl;

	if (TTF_Init() == -1)
		std::cout << "TTF_Init HAS FAILED. Error: " << SDL_GetError() << std::endl;

	RenderWindow window("Conway's Game Of Life", 1280, 720);
	SDL_Renderer* renderer = window.getRenderer();

	SDL_Texture* dotTex = window.loadTexture("res/gfx/dot.png");

	std::vector <Entity> dots = {};

	int rows = 720/SIZE;
	int cols = 1280/SIZE;

	for (int i = 0; i<rows; ++i){
		for (int j = 0; j<cols; ++j){
			Entity dot(Vector2f(SIZE*j, SIZE*i), dotTex, DEAD);
			dots.push_back(dot);
		}
	}


	// INITIALIZE KEYBOARD INPUTS ARRAY
	const Uint8* keyboard = SDL_GetKeyboardState(NULL);

	float currentTime  = utils::hireTimeInSeconds();
	float lastStep     = currentTime;
	float timeStep     = 0.2f;

	int gridPos        = 0;

	unsigned int generations = 0;

	bool simulationStarted = true;
	bool gameStarted       = false;
	SDL_Event event;

	SDL_SetRenderDrawColor(renderer, 0x40, 0x40, 0x40, 0xFF);

/*                              GAME LOOP STARTS                                     */
	while (simulationStarted){

		currentTime = utils::hireTimeInSeconds();

		if (SDL_PollEvent(&event) && event.type == SDL_QUIT){
				simulationStarted = false;
		}

		if (event.button.button == SDL_BUTTON_LEFT){

			gridPos = cols*floor(event.motion.y/SIZE) + floor(event.motion.x/SIZE);

			dots[gridPos].setState(LIVE);

			window.clear();

			for (Entity& dot : dots){
				if (dot.isAlive())
					window.render(dot);
			}

			Text gens(GENERATION_PARAMS);
			gens.displayText(5, 5, renderer);
			gens.destroyText();

			window.display();

		}

		if (event.button.button == SDL_BUTTON_RIGHT){

			gridPos = cols*floor(event.motion.y/SIZE) + floor(event.motion.x/SIZE);

			dots[gridPos].setState(DEAD);

			window.clear();

			for (Entity& dot : dots){
				if (dot.isAlive())
					window.render(dot);
			}

			Text gens(GENERATION_PARAMS);
			gens.displayText(5, 5, renderer);
			gens.destroyText();

			window.display();
		}

	    if (keyboard[SDL_SCANCODE_SPACE] && currentTime - lastStep > timeStep){

			lastStep = currentTime;
			gameStarted = !gameStarted;

		}

		if (keyboard[SDL_SCANCODE_C]){

			gameStarted = false;
			generations = 0;

			window.clear();

			for (Entity& dot : dots){
				dot.setState(DEAD);
			}

			Text gens(GENERATION_PARAMS);
			gens.displayText(5, 5, renderer);
			gens.destroyText();

			window.display();

		}

		if (gameStarted && currentTime - lastStep > timeStep){

			dots[0].ApplyRules(&dots, rows, cols);
			generations += 1;

			lastStep = currentTime;
			window.clear();

			for (Entity& dot : dots){
				if (dot.isAlive())
					window.render(dot);
			}

			Text gens(GENERATION_PARAMS);
			gens.displayText(5, 5, renderer);
			gens.destroyText();

			window.display();
		}

	}

	window.cleanUp(); // DELETE EVERYTHING ON SCREEN

	SDL_Quit(); 

	return 0;
}