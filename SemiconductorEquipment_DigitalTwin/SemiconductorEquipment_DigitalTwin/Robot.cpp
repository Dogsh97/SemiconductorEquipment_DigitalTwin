#include "Robot.h"

Robot::Robot()
	:robotState(RobotState::Idle)
{
}



void Robot::Move() {
	if (robotState == RobotState::Idle) {
		robotState = RobotState::Moving;
	}
	else {
		robotState = RobotState::Error;
	}
}

void Robot::Pick() {
	if (robotState == RobotState::Moving) {
		robotState = RobotState::Picking;
	}
	else {
		robotState = RobotState::Error;
	}
}

void Robot::Place() {
	if (robotState == RobotState::Picking) {
		robotState = RobotState::Placing;
	}
	else {
		robotState = RobotState::Error;
	}
}

void Robot::Reset() {
	robotState = RobotState::Idle;
	
}
