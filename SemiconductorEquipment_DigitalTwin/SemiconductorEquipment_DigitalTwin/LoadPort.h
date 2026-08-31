#pragma once
enum class LoadPortState {
	Idle,
	Load,
	Unload,
	Error
};

class LoadPort {
	private:
		LoadPortState loadportState;
		bool waferDetected;
	public:
		LoadPort();
		bool IswaferDetected() const;
		void Load();
		void Unload();
		void Complete();
};