#include "LoadPort.h"

LoadPort::LoadPort()
	:loadportState(LoadPortState::Idle),
	waferDetected(false)
{
}

bool LoadPort::IsWaferDetected() const{
	return waferDetected;
}

void LoadPort::Load() {
	if (loadportState == LoadPortState::Idle && !IsWaferDetected()) {
		loadportState = LoadPortState::Loading;
	}
	else {
		loadportState = LoadPortState::Error;
	}
}

void LoadPort::Unload() {
	if (loadportState == LoadPortState::Complete && IsWaferDetected()) {
		loadportState = LoadPortState::Unloading;
	}
	else {
		loadportState = LoadPortState::Error;
	}
}

void LoadPort::LoadComplete() {
	if (loadportState == LoadPortState::Loading) {
		loadportState = LoadPortState::Complete;
		waferDetected = true;
	}
	else {
		loadportState = LoadPortState::Error;
	}
}

void LoadPort::UnloadComplete() {
	if (loadportState == LoadPortState::Unloading) {
		loadportState = LoadPortState::Idle;
		waferDetected = false;
	}
	else {
		loadportState = LoadPortState::Error;
	}
}