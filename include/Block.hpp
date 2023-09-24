#pragma once

enum BLOCKTYPE {
	GRASS,
	DIRT,
	WOOD_LOG,
	LEAVES,
	LAST
};

class Block {
public:
	Block(BLOCKTYPE type);
};