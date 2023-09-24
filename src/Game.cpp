#include "Game.hpp"
#include "Block.hpp"
#include <iostream>
#include <SDL_image.h>
constexpr unsigned short WIDTH{ 1280 };
constexpr unsigned short HEIGHT{ 720 };

void Game::LoadTextures() {
	SDL_Texture* block = IMG_LoadTexture(_renderer, "assets/blocks.png");
	SDL_Rect tmpoffset{};
	tmpoffset.x = 0;
	tmpoffset.y = 0;
	tmpoffset.h = 32;
	tmpoffset.w = 32;

	for (int i = 0; i != LAST; i++) {
		SDL_Texture* temp = SDL_CreateTexture(_renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_TARGET, 32, 32);

		SDL_SetRenderTarget(_renderer, temp);
		SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 0);
		SDL_RenderClear(_renderer);
		SDL_RenderCopy(_renderer, block, &tmpoffset, NULL);
		std::cout << SDL_GetError() << std::endl;

		_block_textures.insert({ static_cast<BLOCKTYPE>(i), temp});
		tmpoffset.x += 32;

		SDL_SetRenderTarget(_renderer, NULL);

		temp = nullptr;
	}

	block = nullptr;
	free(block);
	SDL_SetRenderTarget(_renderer, NULL);
}

Game::Game()
{

}

void Game::Run() {
	if (!SDL_INIT_EVERYTHING) {
		std::cout << SDL_GetError();
	}
	_window = SDL_CreateWindow("Dadoraria",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		WIDTH,
		HEIGHT,
		0);
	if (!_window) {
		std::cout << SDL_GetError() << std::endl;
		return;
	}
	_renderer = SDL_CreateRenderer(_window,
		-1,
		SDL_RENDERER_TARGETTEXTURE || SDL_RENDERER_PRESENTVSYNC || SDL_RENDERER_ACCELERATED);

	if (!_renderer) {
		std::cout << SDL_GetError() << std::endl;
		return;
	}

	LoadTextures();

	SDL_Rect rectangle{};
	rectangle.x = 320;
	rectangle.y = 480;
	rectangle.w = 32;
	rectangle.h = 32;

	for (std::pair<BLOCKTYPE, SDL_Texture*> n : _block_textures) {
		for (int i = 0; i <= 10; ++i) {
			SDL_RenderCopy(_renderer, n.second, NULL, &rectangle);
			rectangle.x += 32;
		}
		rectangle.x = 320;
		rectangle.y += 32;
	}
	SDL_RenderPresent(_renderer);

	bool quit = false;
	SDL_Event ev{};

	//main game loop

	while (!quit) {
		SDL_PollEvent(&ev);
		switch (ev.type) {

		case SDL_QUIT:
			quit = true;
			break;

		default:
			break;
		}
	}
}