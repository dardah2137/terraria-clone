#pragma once

#include <SDL.h>
#include <vector>
#include <memory>
#include <string>
#include <unordered_map>

#include <Block.hpp>

class Game {
public:
	Game();
	void Run();
private:
	void LoadTextures();
	SDL_Window* _window;
	SDL_Renderer* _renderer;
	std::unordered_map<BLOCKTYPE, SDL_Texture*> _block_textures{};
	std::vector<std::vector<std::unique_ptr<Block>>>* _blocks{};
};
