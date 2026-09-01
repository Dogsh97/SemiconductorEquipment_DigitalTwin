#pragma once

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
	public:
		Robot();
		void Move();
		void MoveComplete();
		void Pick();
		void PickComplete();
		void Place();
		void PlaceComplete();
		void Reset();
};