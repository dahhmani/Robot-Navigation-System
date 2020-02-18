#pragma once

#include "LandBasedRobot.h"

namespace fp
{
	class LandBasedWheeled : public LandBasedRobot
	{
	public:
		LandBasedWheeled(std::string name);

		virtual void MoveForward() override;
		virtual void TurnLeft() override;
		virtual void TurnRight() override;

		void SpeedUp(int stepSize); // dummy method

	protected:
		int wheel_number; // dummy attribute
	};
}