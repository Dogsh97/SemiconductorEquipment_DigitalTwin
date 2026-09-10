#pragma once
#include "Wafer.h"

enum class RobotState {
	Idle,
	Moving,
	Moved,
	Picking,
	Picked,
	Placing,
	Placed,
	Error
};

class Robot {
	private:
		RobotState robotState;
		Wafer* currentWafer;
		struct Position
		{
			int x;
			int y;
			int z;
		};
		Position currentPosition;
		Position targetPosition;
		Position homePosition;

	public:
		Robot();
		void Move(int x, int y, int z);
		void MoveComplete();
		void Homing();
		void Pick();
		void PickComplete();
		void Place();
		void PlaceComplete();
		void Reset();
		Wafer* GiveWafer();
		bool ReceiveWafer(Wafer* wafer);
};