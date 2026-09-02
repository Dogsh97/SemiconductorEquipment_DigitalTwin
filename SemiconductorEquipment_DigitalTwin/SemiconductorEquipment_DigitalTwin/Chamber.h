#pragma once
#include "Wafer.h"

enum class ChamberState {
	Idle,
	Ready,
	Open,
	Closed,
	Processing,
	Complete,
	Error
};

class Chamber {
	private:
		ChamberState chamberState;
		Wafer* currentWafer;
	public:
		Chamber();
		void Ready();
		void Open();
		void Close();
		void Process();
		void ProcessComplete();
		void Reset();
		Wafer* GiveWafer();
		bool ReceiveWafer(Wafer* wafer);
};