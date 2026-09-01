#pragma once

enum class ChamberState {
	Idle,
	Ready,
	Open,
	Closed,
	Processing,
	Error
};

class Chamber {
	private:
		ChamberState chamberState;
	public:
		Chamber();
		void Ready();
		void Open();
		void Close();
		void Process();
		void ProcessComplete();
};