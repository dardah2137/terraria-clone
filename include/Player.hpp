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
	Player(SDL_Texture* sprite, float gravity, World* world);
	void apply_velocity(float x, float y);
	void tick_velocity();

	void setPos(float x, float y);
	float getX();
	float getY();
	int getWorldX();
	int getWorldY();
	SDL_Texture* sprite;
private:
	void handleVelY();
	void handleVelX();
	void applyVelocityX(float x);
	void applyVelocityY(float y);
	//enter as screen coordinates
	bool checkCollisionAt(int x, int y);

	World* _pWorld{};
	float _gravity{};
	float x{}, y{1};
	float vel_x{}, vel_y{};
};