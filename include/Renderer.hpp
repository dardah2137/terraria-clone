#pragma once
#include "World.hpp"

#include "Player.hpp"
#include <unordered_map>
#include <SDL.h>


class Renderer {
public:
	Renderer(SDL_Renderer* renderer,
		World* world,
		std::unordered_map<BLOCKTYPE, SDL_Texture*> block_textures,
		Player* player);
	void RenderFrame();
private:
	void RenderBlocks();
	void RenderPlayer();
	Player* player{};
	SDL_Rect centerPlayerPos;
	SDL_Renderer* _pRenderer;
	World* _pWorld;
	std::map<std::pair<int, int>, BLOCKTYPE>* _pBlocks{};
	std::unordered_map<BLOCKTYPE, SDL_Texture*> _block_textures;
};