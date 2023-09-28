#include "Player.hpp"

#include <iostream>
Player::Player(SDL_Texture* sprite)
	: sprite(sprite)
{
}

void Player::move(int x, int y)
{

	this->x += x; this->y += y;
}

void Player::setPos(int x, int y)
{
	this->x = x; this->y = y;
}

int Player::getX() { return x; }

int Player::getY() { return y; }

SDL_Rect* Player::getRectPos()
{
	return nullptr;
}
