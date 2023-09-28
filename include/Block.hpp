#pragma once

#include <utility>
#include <memory>

struct Location {
public:
	Location(int x, int y);
	int x, y;
	bool operator<(const Location& rhs) const;
};

enum BLOCKTYPE {
	GRASS,
	DIRT,
	WOOD_LOG,
	LEAVES,
	LAST
};