#pragma once
#include "Block.hpp"

#include <map>



class World {
public:
	World();
	bool addBlock(std::pair<int, int> location, BLOCKTYPE block, bool replace);
	std::map<std::pair<int, int>, BLOCKTYPE>* get_pBlocks();
	BLOCKTYPE blockAt(std::pair<int, int>  loc);
private:
	std::map<std::pair<int, int>, BLOCKTYPE> _blocks{};
};