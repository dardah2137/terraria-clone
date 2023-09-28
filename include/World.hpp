#pragma once
#include "Block.hpp"

#include <map>



class World {
public:
	World();
	bool addBlock(Location location, BLOCKTYPE block, bool replace);
	std::map<Location, BLOCKTYPE>* get_pBlocks();
private:
	std::map<Location, BLOCKTYPE> _blocks{};
};