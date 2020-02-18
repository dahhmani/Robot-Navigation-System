#pragma once

#include "API.h" 
#include "Maze.h"

namespace fp 
{
	enum Directions { North = 0, East = 1, South = 2, West = 3 };
	static std::array<char,4> directions { 'n','e','s','w' };

	class LandBasedRobot
	{
	public:
		LandBasedRobot(std::string name); 
		virtual ~LandBasedRobot(); 

		virtual void MoveForward();
		virtual void TurnLeft();
		virtual void TurnRight();

		char GetDirection() const { return direction_; }
		Cell GetCell() const { return { x_,y_ }; }
		std::tuple<Cell, Cell, Cell> GetSurroundingCells() const; // returns [front, left, right] cells respectively

		Maze maze;

	protected:
		void ScanSurroundings();
		void UpdatePosition();

		std::string name_;
		int x_, y_;
		char direction_;
		double speed_, width_, length_, height_, capacity_; // dummy attributes
	};
}