#pragma once

#include "Block.hpp"

#include <SDL.h>
#include <vector>
#include <string>
#include <unordered_map>

class Game {
public:
	Game();
	void Run();
private:
	void LoadTextures();

	SDL_Window* _window{};
	SDL_Renderer* _renderer{};
	std::unordered_map<BLOCKTYPE, SDL_Texture*> _block_textures{};
};
