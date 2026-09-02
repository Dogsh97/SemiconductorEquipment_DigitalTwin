#include "Robot.h"

Robot::Robot()
	:robotState(RobotState::Idle),
	currentWafer(nullptr)
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
	if (robotState == RobotState::Picking && currentWafer != nullptr) {
		robotState = RobotState::Picked;
	}
	else {
		robotState = RobotState::Error;
	}
}

void Robot::Place() {
	if (robotState == RobotState::Picked ) {
		robotState = RobotState::Placing;
	}
	else {
		robotState = RobotState::Error;
	}
}

void Robot::PlaceComplete() {
	if (robotState == RobotState::Placing && currentWafer == nullptr) {
		robotState = RobotState::Placed;
	}
	else {
		robotState = RobotState::Error;
	}
}

void Robot::Reset() {
	robotState = RobotState::Idle;
	
}

Wafer* Robot::GiveWafer() {
	Wafer* wafer = currentWafer;
	currentWafer = nullptr;
	return wafer;
}

bool Robot::ReceiveWafer(Wafer* wafer) {
	if (currentWafer == nullptr && wafer != nullptr) {
		currentWafer = wafer;
		return true;
	}
	else {
		robotState = RobotState::Error;
		return false;
	}
}