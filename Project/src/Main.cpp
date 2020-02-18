#include "LandBasedTracked.h"
#include "LandBasedWheeled.h"
#include "Navigator.h"
#include "Maze.h"

int main(int argc, char* argv[]) 
{
	std::shared_ptr<fp::LandBasedRobot> robot = std::make_shared<fp::LandBasedWheeled>("Husky");
	fp::Navigator::drive(robot);
	
	return 0;
}