#include "Robot.h"

Robot::Robot()
	:robotState(RobotState::Idle),
	currentWafer(nullptr),
	currentPosition(0,0,0),
	targetPosition(0,0,0),
	homePosition(0,0,0)
{
}



void Robot::Move(int x,int y,int z) {
	targetPosition.x = x;
	targetPosition.y = y;
	targetPosition.z = z;

	if (robotState == RobotState::Idle) {
		robotState = RobotState::Moving;
		while (targetPosition.x != currentPosition.x) {
			if (targetPosition.x - currentPosition.x >= 0) {
				currentPosition.x += 1;
			}
			else {
				currentPosition.x -= 1;
			}
		}

		while (targetPosition.y != currentPosition.y) {
			if (targetPosition.y - currentPosition.y >= 0) {
				currentPosition.y += 1;
			}
			else {
				currentPosition.y -= 1;
			}
		}

		while (targetPosition.z != currentPosition.z) {
			if (targetPosition.z - currentPosition.z >= 0) {
				currentPosition.z += 1;
			}
			else {
				currentPosition.z -= 1;
			}
		}
	}
	else {
		robotState = RobotState::Error;
	}
}


void Robot::MoveComplete() {
	if (robotState == RobotState::Moving && (currentPosition.x == targetPosition.x)
		&& (currentPosition.y == targetPosition.y)
		&& (currentPosition.z == targetPosition.z)) {
		robotState = RobotState::Moved;
	}
	else {
		robotState = RobotState::Error;
	}
}

void Robot::Homing() {
	targetPosition.x = homePosition.x;
	targetPosition.y = homePosition.y;
	targetPosition.z = homePosition.z;

	while (targetPosition.x != currentPosition.x) {
		if (targetPosition.x - currentPosition.x >= 0) {
			currentPosition.x += 1;
		}
		else {
			currentPosition.x -= 1;
		}		
	}

	while (targetPosition.y != currentPosition.y) {
		if (targetPosition.y - currentPosition.y >= 0) {
			currentPosition.y += 1;
		}
		else {
			currentPosition.y -= 1;
		}
	}

	while (targetPosition.z != currentPosition.z) {
		if (targetPosition.z - currentPosition.z >= 0) {
			currentPosition.z += 1;
		}
		else {
			currentPosition.z -= 1;
		}
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