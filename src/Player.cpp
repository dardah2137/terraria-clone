#include "Player.hpp"

#include <iostream>
Player::Player(SDL_Texture* sprite)
	: sprite(sprite)
{
}

void Player::move(float x, float y)
{

	this->x += x; this->y += y;
}

void Player::setPos(float x, float y)
{
	this->x = x; this->y = y;
}

float Player::getX() { return x; }

float Player::getY() { return y; }