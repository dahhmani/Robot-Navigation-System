#pragma once

#include "LandBasedRobot.h"

namespace fp
{
	class LandBasedTracked : public LandBasedRobot
	{
	public:
		LandBasedTracked(std::string name);

		virtual void MoveForward() override;
		virtual void TurnLeft() override;
		virtual void TurnRight() override;

	protected:
		std::string track_type; // dummy attribute
	};
}