#include "LandBasedTracked.h"

fp::LandBasedTracked::LandBasedTracked(std::string name)
	: LandBasedRobot(name), track_type{} {}

void fp::LandBasedTracked::MoveForward()
{
	std::cerr << "LandBasedTracked::MoveForward is called\n";
	fp::LandBasedRobot::MoveForward();
}

void fp::LandBasedTracked::TurnLeft()
{
	std::cerr << "LandBasedTracked::TurnLeft is called\n";
	fp::LandBasedRobot::TurnLeft();
}

void fp::LandBasedTracked::TurnRight()
{
	std::cerr << "LandBasedTracked::TurnRight is called\n";
	fp::LandBasedRobot::TurnRight();
}