#include "LandBasedWheeled.h"

fp::LandBasedWheeled::LandBasedWheeled(std::string name)
	: LandBasedRobot(name), wheel_number{} {}

void fp::LandBasedWheeled::MoveForward()
{
	std::cerr << "LandBasedWheeled::MoveForward is called\n";
	fp::LandBasedRobot::MoveForward();
}

void fp::LandBasedWheeled::TurnLeft()
{
	std::cerr << "LandBasedWheeled::TurnLeft is called\n";
	fp::LandBasedRobot::TurnLeft();
}

void fp::LandBasedWheeled::TurnRight()
{
	std::cerr << "LandBasedWheeled::TurnRight is called\n";
	fp::LandBasedRobot::TurnRight();
}

void fp::LandBasedWheeled::SpeedUp(int stepSize)
{
	std::cout << "LandBasedWheeled::SpeedUp is called\n";
}