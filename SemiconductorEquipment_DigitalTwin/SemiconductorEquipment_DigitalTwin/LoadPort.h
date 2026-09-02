#pragma once
#include "Wafer.h"

enum class LoadPortState {
	Idle,
	Loading,
	Unloading,
	Complete,
	Error
};

class LoadPort {
	private:
		LoadPortState loadportState;
		bool waferDetected;
		Wafer* currentWafer;
	public:
		LoadPort();
		bool IsWaferDetected() const;
		void Load();
		void Unload();
		void LoadComplete();
		void UnloadComplete();
		Wafer* GiveWafer();
		bool ReceiveWafer(Wafer* wafer);
};