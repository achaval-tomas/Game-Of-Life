#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Math.hpp"
#include <vector>
#include <cmath>
#include "Constants.hpp"

class Entity {
public:
	Entity(Vector2f p_pos, SDL_Texture* p_tex, bool alive);

	inline Vector2f& getPos() {return pos;}
	inline void setPos(Vector2f p_pos){ pos = p_pos; }

	SDL_Texture* getTex();

	SDL_Rect getCurrentFrame();

	bool isAlive(){return alive;}
	void setState(bool state){alive = state;}

	bool getNextState(){return nextState;}
	void setNextState(bool state){nextState = state;}

	void ApplyRules(std::vector <Entity> *dots, int rows, int cols);
	void checkRules(std::vector <Entity> *dots, int i, int j, int rows, int cols);

private:
	bool alive;
	bool nextState;
	Vector2f pos;
	SDL_Rect currentFrame;
	SDL_Texture* tex;
};