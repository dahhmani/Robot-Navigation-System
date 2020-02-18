#pragma once 

#include "API.h"
#include "Cell.h"

namespace fp
{
	class Maze
	{
	public:
		Maze();

		void setWall(const Cell& c1, const Cell& c2);
		bool isWall(const Cell& c1, const Cell& c2) const;
		bool containCell(const Cell& c) const;

		void display_adjacencyMatrix() const;

		unsigned int get_width() const { return m_width; }
		unsigned int get_height() const { return m_height; }
		unsigned int get_num_cells() const { return m_num_cells; }
		Cell get_start() const { return m_start; }
		std::vector<Cell> get_goals() const { return m_goals; }

	private:
		char& at(unsigned int c1_index, unsigned int c2_index);
		char at(unsigned int c1_index, unsigned int c2_index) const;

		int m_width, m_height, m_num_cells;
		Cell m_start;
		std::vector<Cell> m_goals;
		std::vector<char> m_adjacencyMatrix;
	};
}