#include "Entity.hpp"

/*-------------------------------------------- GENERAL ENTITIES CLASS --------------------------------------------*/
Entity::Entity(Vector2f p_pos, SDL_Texture* p_tex, bool p_alive)
:alive(p_alive), nextState(p_alive), pos(p_pos), tex(p_tex)
{
	currentFrame.x = 0;
	currentFrame.y = 0;
	SDL_QueryTexture(p_tex, NULL, NULL, &currentFrame.w, &currentFrame.h);
}

SDL_Texture* Entity::getTex(){
	return tex;
}

SDL_Rect Entity::getCurrentFrame(){
	return currentFrame;
}

void Entity::ApplyRules(std::vector <Entity> *dots, int rows, int cols){

	for (int i = 0; i<rows; ++i){
		for (int j = 0; j<cols; ++j){			
			checkRules(dots, i, j, rows, cols);
		}
	}

	for (int i = 0; i<rows; ++i){
		for (int j = 0; j<cols; ++j){			
			(*dots)[i*cols + j].setState((*dots)[i*cols + j].getNextState());
		}
	}

}

void Entity::checkRules(std::vector <Entity> *dots, int i, int j, int rows, int cols){

	int liveNeighbors = 0;

	for (int k = i-1; k <= i+1; ++k){
		for (int l = j-1; l <= j+1; ++l){
			if (k == i && l ==j)
				continue;

			if (k>=0 && l>=0 && k<rows && l<cols && (*dots)[k*cols + l].isAlive())
				liveNeighbors += 1;

		}
	}

	if ((*dots)[i*cols + j].isAlive() && (liveNeighbors < 2 || liveNeighbors > 3)){

		(*dots)[i*cols + j].setNextState(DEAD);

	} else if (!( (*dots)[i*cols + j].isAlive() ) && liveNeighbors == 3){

		(*dots)[i*cols + j].setNextState(LIVE);

	} else {
		(*dots)[i*cols + j].setNextState((*dots)[i*cols + j].isAlive());
	}

}

