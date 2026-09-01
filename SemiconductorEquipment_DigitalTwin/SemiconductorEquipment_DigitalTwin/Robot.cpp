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

void Robot::MoveComplete() {
	if (robotState == RobotState::Moving) {
		robotState = RobotState::Moved;
	}
	else {
		robotState = RobotState::Error;
	}
}

void Robot::Pick() {
	if (robotState == RobotState::Moved) {
		robotState = RobotState::Picking;
	}
	else {
		robotState = RobotState::Error;
	}
}

void Robot::PickComplete() {
	if (robotState == RobotState::Picking) {
		robotState = RobotState::Picked;
	}
	else {
		robotState = RobotState::Error;
	}
}

void Robot::Place() {
	if (robotState == RobotState::Picked) {
		robotState = RobotState::Placing;
	}
	else {
		robotState = RobotState::Error;
	}
}

void Robot::PlaceComplete() {
	if (robotState == RobotState::Placing) {
		robotState = RobotState::Placed;
	}
	else {
		robotState = RobotState::Error;
	}
}

void Robot::Reset() {
	robotState = RobotState::Idle;
	
}
