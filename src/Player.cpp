#include "Player.hpp"

#include <iostream>

Player::Player(SDL_Texture* sprite, double gravity, World* world)
	: sprite(sprite),
	_gravity(gravity),
	_pWorld(world)
{
}

void Player::apply_velocity(double x, double y) {
	applyVelocityX(x);
	applyVelocityY(y);
};

void Player::applyVelocityX(double x)
{
	double vel_x_after = vel_x + x;

	if (vel_x_after >= terminal_velocity_x) {
		this->vel_x = terminal_velocity_x;
		return;
	}
	else if (vel_x_after <= -terminal_velocity_x) {
		this->vel_x = -terminal_velocity_x;
		return;
	}
	this->vel_x += x;
	return;
}

void Player::applyVelocityY(double y)
{
	vel_y += y;
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
	//std::cout << vel_y << std::endl;
}

//isnt pixel based, automatically converts to world coordinates
void Player::setPos(double x, double y)
{
	this->x = x*32; this->y = y*32;
}

double Player::getX() { return x; }

double Player::getY() { return y; }

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
	vel_y -= _gravity;
	if (vel_y <= _gravity) {
		if (vel_y >= terminal_velocity_y) { vel_y = terminal_velocity_y; }
		else {
			vel_y += (double)(1 / 2) * (-_gravity);
		}
	}
	double y_after = y - vel_y;
	bool is_negative_y = y_after < 0;
	bool is_negative_x = false;
	bool vel_y_positive = vel_y > 0;
	if (vel_y_positive) {
		canJump = false;
	}
	std::cout << "SZIT!" << vel_y << std::endl;

	if (!vel_y_positive && is_negative_y && checkCollisionAt(std::round(x/32), -std::floor((abs(y) / 32))-1)) {
		canJump = true;
		vel_y = 0;
	}
	else if(!vel_y_positive && checkCollisionAt (std::round(x / 32), std::floor(y / 32)) ) {
		canJump = true;
		std::cout << std::round(x / 32) << " " << std::floor(y_after / 32) - 1 << std::endl;
		vel_y = 0;
	}
	y += vel_y;
}


