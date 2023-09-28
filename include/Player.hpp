#pragma once

#include <SDL.h>

class Player {
public:
	Player(SDL_Texture* sprite);
	void move(float x, float y);
	void setPos(float x, float y);
	float getX();
	float getY();
	SDL_Texture* sprite;
private:
	float x{}, y{1};
};