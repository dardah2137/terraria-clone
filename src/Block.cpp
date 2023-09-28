#include "Block.hpp"

Location::Location(int x, int y) 
	: x(x),
	y(y)
{

}

bool Location::operator<(const Location& rhs) const
{
	return this->x < rhs.x;
}

