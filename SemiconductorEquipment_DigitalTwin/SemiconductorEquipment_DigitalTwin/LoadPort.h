#pragma once
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
	public:
		LoadPort();
		bool IsWaferDetected() const;
		void Load();
		void Unload();
		void LoadComplete();
		void UnloadComplete();
};