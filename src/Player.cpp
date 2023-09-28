#include "Player.hpp"

#include <iostream>

const float SPEED_LIMIT = 5;
const float X_VELOCITY_SLOWDOWN = 1.5F;

Player::Player(SDL_Texture* sprite, float gravity, World* world)
	: sprite(sprite),
	_gravity(gravity),
	_pWorld(world)
{
}

void Player::apply_velocity(float x, float y) {
	applyVelocityX(x);
	applyVelocityY(y);
};

void Player::applyVelocityX(float x)
{
	float vel_x_after = vel_x + x;

	if (vel_x_after >= SPEED_LIMIT) {
		this->vel_x = SPEED_LIMIT;
	}
	else if (vel_x_after <= -SPEED_LIMIT) {
		this->vel_x = -SPEED_LIMIT;
	}
	else {
		this->vel_x += x;
	}
}

void Player::applyVelocityY(float y) 
{
	vel_y += y * _gravity;
}

bool Player::checkCollisionAt(int x, int y)
{
	if (_pWorld->blockAt({ x, y })) {
		return true;
	}
	return false;
}

void Player::tick_velocity() {
	handleVelX();
	handleVelY();
}

//isnt pixel based, automatically converts to world coordinates
void Player::setPos(float x, float y)
{
	this->x = x*32; this->y = y*32;
}

float Player::getX() { return x; }

float Player::getY() { return y; }

int Player::getWorldX() { return x/32; }

int Player::getWorldY() { return y/32; }


void Player::handleVelX()
{
	x += vel_x;

	if (vel_x < 0) {
		if ((vel_x + X_VELOCITY_SLOWDOWN) > 0) {
			vel_x = 0;
			return;
		}
		vel_x += X_VELOCITY_SLOWDOWN;
	}
	else {
		if ((vel_x - X_VELOCITY_SLOWDOWN) < 0) {
			vel_x = 0;
			return;
		}
		vel_x -= X_VELOCITY_SLOWDOWN;
	}
}

void Player::handleVelY()
{
	int moduloY = (int)y % 32;
	int moduloX = (int)x % 32;
	if (moduloY % 32 == 0) {
		if (checkCollisionAt(std::ceil(x) / 32, (y - 32) / 32))
		{
			return;
		}
		if (checkCollisionAt(std::floor(x+32) / 32, (y - 32) / 32)) {
			return;
		}
	}
	y -= _gravity;
}

