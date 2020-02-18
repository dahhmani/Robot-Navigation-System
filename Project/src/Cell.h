#pragma once

namespace fp
{
	class Maze; // forward class declaration

	enum Cells { NotConnected = 0, Connected = 1 };

	struct Cell
	{
		int x, y;

		unsigned int index(const Maze& maze) const;
		bool operator==(Cell other) const;
		bool operator!=(Cell other) const;
	};
}