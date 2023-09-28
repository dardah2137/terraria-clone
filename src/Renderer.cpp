#include "Renderer.hpp"
#include <iostream>

constexpr int TEXTURE_SIZE{ 32 };
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
	for (auto iter = _pBlocks->begin(); iter != _pBlocks->end(); ++iter) {
		SDL_Rect place_data{ (iter->first.x * TEXTURE_SIZE) + SCREEN_WIDTH/2 + player->getX(),
			0 - (iter->first.y * TEXTURE_SIZE) + SCREEN_HEIGHT/2 + player->getY(),
			TEXTURE_SIZE,
			TEXTURE_SIZE,
		};
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
