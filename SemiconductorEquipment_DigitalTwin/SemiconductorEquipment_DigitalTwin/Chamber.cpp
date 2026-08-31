#include "Chamber.h"

Chamber::Chamber() 
	:chamberState(ChamberState::Idle)
{
}

void Chamber::Ready() {
	if (chamberState == ChamberState::Idle) {
		chamberState = ChamberState::Ready;
	}
	else {
		chamberState= ChamberState::Error;
	}
}

void Chamber::Open() {
	if (chamberState == ChamberState::Ready) {
		chamberState = ChamberState::Open;
	}
	else {
		chamberState = ChamberState::Error;
	}
}

void Chamber::Close() {
	if (chamberState == ChamberState::Open) {
		chamberState = ChamberState::Close;
	}
	else {
		chamberState = ChamberState::Error;
	}
}

void Chamber::Process() {
	if (chamberState == ChamberState::Close) {
		chamberState = ChamberState::processing;
	}
	else {
		chamberState = ChamberState::Error;
	}
}

void Chamber::Complete() {
	if (chamberState == ChamberState::processing) {
		chamberState = ChamberState::Idle;
	}
	else {
		chamberState = ChamberState::Error;
	}
}