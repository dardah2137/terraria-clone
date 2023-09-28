#include "Renderer.hpp"
#include <iostream>

constexpr int BLOCK_SIZE{ 32 };
extern const unsigned short SCREEN_WIDTH;
extern const unsigned short SCREEN_HEIGHT;

Renderer::Renderer(SDL_Renderer* renderer, World* world, std::unordered_map<BLOCKTYPE, SDL_Texture*> block_textures, Player* player)
	: _pRenderer(renderer),
	_pWorld(world),
	_block_textures(block_textures),
	player(player)
{
	_pBlocks = _pWorld->get_pBlocks();
	centerPlayerPos = { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 32, 32 };
}

void Renderer::RenderBlocks() {
	SDL_Rect place_data{0,0,BLOCK_SIZE,BLOCK_SIZE};
	for (auto iter = _pBlocks->begin(); iter != _pBlocks->end(); ++iter) {
		place_data.x = -(iter->first.first * BLOCK_SIZE) + SCREEN_WIDTH / 2 + player->getX();
		place_data.y = -(iter->first.second * BLOCK_SIZE) + SCREEN_HEIGHT / 2 + player->getY();
		SDL_RenderCopy(_pRenderer, _block_textures.find(iter->second)->second, NULL, &place_data);
	}
}

void Renderer::RenderPlayer() {
	SDL_RenderCopy(_pRenderer, player->sprite, NULL, &centerPlayerPos);
}

void Renderer::RenderFrame()
{
	SDL_RenderClear(_pRenderer);

	RenderPlayer();
	RenderBlocks();

	SDL_RenderPresent(_pRenderer);
}
