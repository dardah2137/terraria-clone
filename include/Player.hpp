#pragma once

#include <SDL.h>

class Player {
public:
	Player(SDL_Texture* sprite);
	void move(int x, int y);
	void setPos(int x, int y);
	int getX();
	int getY();
	SDL_Texture* sprite;
	SDL_Rect* getRectPos();
private:
	SDL_Rect rectPos{};
	int x{}, y{32};
};