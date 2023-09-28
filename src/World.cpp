#include "World.hpp"
#include <iostream>

World::World() {

}

//adds block at a location, if there is already a block there, returns false
bool World::addBlock(Location location, BLOCKTYPE block, bool replace = false)
{
	if(_blocks.contains(location)) { return false; }
	_blocks.insert({ location, block });
	return true;
}

std::map<Location, BLOCKTYPE>* World::get_pBlocks()
{
	return &_blocks;
}
