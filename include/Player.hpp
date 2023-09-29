#pragma once

#include <SDL.h>

#include "World.hpp"

enum DIRECTION {
	LEFT,
	RIGHT,
	UP,
	DOWN
};

class Player {
public:
	Player(SDL_Texture* sprite, double gravity, World* world);
	void apply_velocity(double x, double y);
	void tick_velocity();

	void setPos(double x, double y);
	double getX();
	double getY();
	int getWorldX();
	int getWorldY();
	bool canJump;
	SDL_Texture* sprite;
private:
	void handleVelY();
	void handleVelX();
	void applyVelocityX(double x);
	void applyVelocityY(double y);
	//enter as screen coordinates
	bool checkCollisionAt(int x, int y);
	const double terminal_velocity_y = 5.0;

	World* _pWorld{};
	double _gravity{};
	double x{}, y{1};
	double vel_x{}, vel_y{};
};