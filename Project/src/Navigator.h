#pragma once 

#include "API.h"
#include "LandBasedRobot.h"

namespace fp 
{ 
	enum Actions { Forward = 'f', Left = 'l', Right = 'r', Backward = 'b' };

	class Navigator 
	{
	public:
		Navigator() = delete;

		static void drive(std::shared_ptr<LandBasedRobot> robot);
		static std::vector<Cell> planPath(std::shared_ptr<LandBasedRobot> robot); // BFS
		static std::vector<char> planActions(std::shared_ptr<LandBasedRobot> robot, const std::vector<Cell>& path);

	private:
		static bool isElementOf(const Cell& c, const std::vector<Cell>& path);
		static void highlightPath(std::shared_ptr<LandBasedRobot> robot, const std::vector<Cell>& path, int currentIndex);
	};
}