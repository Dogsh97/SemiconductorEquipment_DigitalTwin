#pragma once

enum class RobotState {
	Idle,
	Moving,
	Picking,
	Placing,
	Error
};

class Robot {
	private:
		RobotState robotState;
	public:
		Robot();
		void Move();
		void Pick();
		void Place();
		void Reset();
};