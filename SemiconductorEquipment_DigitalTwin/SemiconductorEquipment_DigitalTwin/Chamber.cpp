#include "Chamber.h"

Chamber::Chamber()
	:chamberState(ChamberState::Idle),
	currentWafer(nullptr)
{
}

void Chamber::Ready() {
	if (chamberState == ChamberState::Idle && currentWafer == nullptr) {
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
	if (chamberState == ChamberState::Open && currentWafer != nullptr) {
		chamberState = ChamberState::Closed;
	}
	else {
		chamberState = ChamberState::Error;
	}
}

void Chamber::Process() {
	if (chamberState == ChamberState::Closed) {
		chamberState = ChamberState::Processing;
	}
	else {
		chamberState = ChamberState::Error;
	}
}

void Chamber::ProcessComplete() {
	if (chamberState == ChamberState::Processing) {
		chamberState = ChamberState::Complete;
	}
	else {
		chamberState = ChamberState::Error;
	}
}

void Chamber::Reset() {
	if (chamberState == ChamberState::Complete && currentWafer == nullptr) {
		chamberState = ChamberState::Idle;
	}
	else {
		chamberState = ChamberState::Error;
	}
}

Wafer* Chamber::GiveWafer() {
	Wafer* wafer = currentWafer;
	currentWafer = nullptr;
	return wafer;
}

bool Chamber::ReceiveWafer(Wafer* wafer) {
	if (currentWafer == nullptr && wafer != nullptr) {
		currentWafer = wafer;
		return true;
	}
	else {
		chamberState = ChamberState::Error;
		return false;
	}
}