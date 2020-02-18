#include "Cell.h"
#include "Maze.h"

unsigned int fp::Cell::index(const fp::Maze& maze) const
{
	return y * maze.get_width() + x;
}

bool fp::Cell::operator==(fp::Cell other) const
{
	return x == other.x && y == other.y;
}

bool fp::Cell::operator!=(fp::Cell other) const
{
	return x != other.x || y != other.y;
}