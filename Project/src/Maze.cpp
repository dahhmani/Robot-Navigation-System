#include "Maze.h"

fp::Maze::Maze()
	: m_width{ API::mazeWidth() }, m_height{ API::mazeHeight() }, m_num_cells{ m_width * m_height }, m_start{ 0,0 }
{
	// Initialize maze to have no walls
	m_adjacencyMatrix.resize(m_num_cells * m_num_cells, Connected);
	for (int i = 0; i < m_num_cells; ++i)
		at(i,i) = NotConnected;

	// Draw walls around the perimeter of the maze
	for (int x = 0; x < m_width; ++x)
		for (int y = 0; y < m_height; ++y) 
		{
			if (x == 0)
				API::setWall(x, y, 'w');
			if (y == 0)
				API::setWall(x, y, 's');
			if (x == m_width - 1)
				API::setWall(x, y, 'e');
			if (y == m_height - 1)
				API::setWall(x, y, 'n');
		}

	// Predefined start cell
	API::setText(m_start.x, m_start.y, "start");

	// Predefined goal cells
	m_goals.resize(4);
	m_goals[0] = { 7,7 };
	m_goals[1] = { 7,8 };
	m_goals[2] = { 8,7 };
	m_goals[3] = { 8,8 };
	for (auto goal : m_goals)
		API::setText(goal.x, goal.y, "goal");
}

void fp::Maze::setWall(const fp::Cell& c1, const fp::Cell& c2)
{
	unsigned int c1_index{ c1.index(*this) }, c2_index{ c2.index(*this) };
	at(c1_index, c2_index) = at(c2_index, c1_index) = NotConnected;
}

bool fp::Maze::isWall(const fp::Cell& c1, const fp::Cell& c2) const
{
	unsigned int c1_index{ c1.index(*this) }, c2_index{ c2.index(*this) };
	return at(c1_index, c2_index) == NotConnected && at(c2_index, c1_index) == NotConnected;
}

bool fp::Maze::containCell(const fp::Cell& c) const
{
	return c.x >= 0 && c.x < m_width && c.y >= 0 && c.y < m_height;
}

 char& fp::Maze::at(unsigned int c1_index, unsigned int c2_index) 
{
	return m_adjacencyMatrix[c2_index * m_num_cells + c1_index];
}

 char fp::Maze::at(unsigned int c1_index, unsigned int c2_index) const
 {
	 return m_adjacencyMatrix[c2_index * m_num_cells + c1_index];
 }

void fp::Maze::display_adjacencyMatrix() const
{
	std::cerr << std::endl;
	for (int i = 0; i < m_num_cells; ++i)
	{
		for (int j = 0; j < m_num_cells; ++j)
			std::cerr << +at(i,j);
		std::cerr << std::endl;
	}
}