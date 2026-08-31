#pragma once

enum class ChamberState {
	Idle,
	Ready,
	Open,
	Close,
	processing,
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
		void Complete();
};