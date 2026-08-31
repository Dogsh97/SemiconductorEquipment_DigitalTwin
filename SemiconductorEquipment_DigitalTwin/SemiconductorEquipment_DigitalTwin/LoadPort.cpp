#include "LoadPort.h"

LoadPort::LoadPort()
	:loadportState(LoadPortState::Idle),
	waferDetected(false)
{
};

bool LoadPort::IswaferDetected() const{
	return waferDetected;
}

void LoadPort::Load() {
	if (loadportState == LoadPortState::Idle) {
		loadportState = LoadPortState::Load;
	}
	else {
		loadportState = LoadPortState::Error;
	}
}

void LoadPort::Unload() {
	if (loadportState == LoadPortState::Load) {
		loadportState = LoadPortState::Unload;
	}
	else {
		loadportState = LoadPortState::Error;
	}
}

void LoadPort::Complete() {
	if (loadportState == LoadPortState::Unload) {
		loadportState = LoadPortState::Idle;
	}
	else {
		loadportState = LoadPortState::Error;
	}
}