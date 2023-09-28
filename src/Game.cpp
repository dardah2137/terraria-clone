#include "Game.hpp"

#include "Block.hpp"
#include "Renderer.hpp"

#include <iostream>
#include <SDL_image.h>

extern const unsigned short SCREEN_WIDTH{ 1280 };
extern const unsigned short SCREEN_HEIGHT{ 720 };

void Game::LoadTextures() {
	SDL_Texture* block = IMG_LoadTexture(_renderer, "assets/blocks.png");
	SDL_Rect tmpoffset{};
	tmpoffset.x = 0;
	tmpoffset.y = 0;
	tmpoffset.h = 32;
	tmpoffset.w = 32;

	for (int i = 1; i != LAST; i++) {
		SDL_Texture* temp = SDL_CreateTexture(_renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_TARGET, 32, 32);

		SDL_SetRenderTarget(_renderer, temp);
		SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 0);
		SDL_RenderClear(_renderer);
		SDL_RenderCopy(_renderer, block, &tmpoffset, NULL);
		std::cout << SDL_GetError() << std::endl;

		_block_textures.insert({ static_cast<BLOCKTYPE>(i), temp});
		tmpoffset.x += 32;

		SDL_SetRenderTarget(_renderer, NULL);
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
		SCREEN_WIDTH,
		SCREEN_HEIGHT,
		0);
	if (!_window) {
		std::cout << SDL_GetError() << std::endl;
		return;
	}
	_renderer = SDL_CreateRenderer(_window,
		-1,
		SDL_RENDERER_PRESENTVSYNC);

	if (!_renderer) {
		std::cout << SDL_GetError() << std::endl;
		return;
	}

	LoadTextures();
	World world;
	Player player(IMG_LoadTexture(_renderer, "assets/pudzion.png"), 2, &world);
	player.setPos(2, 4);
	Renderer renderer(_renderer, &world, _block_textures, &player);

	world.addBlock({ 0, 0 }, (BLOCKTYPE)2, true);
	world.addBlock({ 2, -3 }, (BLOCKTYPE)1, true);

	Uint64 now{ SDL_GetPerformanceCounter() };
	Uint64 last{ now };
	const Uint64 performanceFrequency = SDL_GetPerformanceFrequency();
	float deltaTime{};

	const Uint8* keystates = SDL_GetKeyboardState(NULL);
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

		if (keystates[SDL_SCANCODE_D]) {
			if (!keystates[SDL_SCANCODE_A]) { player.apply_velocity(-0.15F * deltaTime, 0); }
		} else if (keystates[SDL_SCANCODE_A]) { player.apply_velocity(0.15F * deltaTime, 0); }
		if (world.blockAt( { player.getWorldX(), player.getWorldY() - 1 } )
			&& keystates[SDL_SCANCODE_W]) { player.apply_velocity(0, 0.5F * deltaTime); }
		if (keystates[SDL_SCANCODE_S]) { player.apply_velocity(0, -0.5F * deltaTime); }

		player.tick_velocity();

		renderer.RenderFrame();
		now = SDL_GetPerformanceCounter();
		deltaTime = (float)(now - last) * 1000 / performanceFrequency;
		//std::cout << player.getWorldX() << " " << player.getWorldY() - 1 << " " << world.blockAt({player.getWorldX(), player.getWorldY() - 1}) << std::endl;
		
		last = now;
	}
}