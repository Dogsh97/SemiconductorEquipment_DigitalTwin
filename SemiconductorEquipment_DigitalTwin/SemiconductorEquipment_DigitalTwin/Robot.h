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
	public:
		Robot();
		void Move();
		void MoveComplete();
		void Pick();
		void PickComplete();
		void Place();
		void PlaceComplete();
		void Reset();
		Wafer* GiveWafer();
		bool ReceiveWafer(Wafer* wafer);
};