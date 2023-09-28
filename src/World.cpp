#include "World.hpp"
#include <iostream>

World::World() {

}

//adds block at a location, if there is already a block there, returns false
bool World::addBlock(std::pair<int, int> location, BLOCKTYPE block, bool replace = false)
{
	if(_blocks.contains(location)) { return false; }
	_blocks.insert({ location, block });
	return true;
}

std::map<std::pair<int, int>, BLOCKTYPE>* World::get_pBlocks()
{
	return &_blocks;
}

BLOCKTYPE World::blockAt(std::pair<int, int>  loc)
{
	if (_blocks.contains(loc)) {
		std::cout << loc.first << " " << loc.second << std::endl;
		return _blocks.find(loc)->second; 
	}
	return BLOCKTYPE(NULL);
}
