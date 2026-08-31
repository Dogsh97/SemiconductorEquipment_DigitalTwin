#pragma once
#include "Wafer.h"
#include "LoadPort.h"
#include "Chamber.h"
#include "Robot.h"

class EquipmentController {
	private:
		Wafer wafer;
		LoadPort loadPort;
		Chamber chamber;
		Robot robot;

	public:
		void getWaferInfo();
		void Initialize();
		void Start();
		void Stop();
		void Reset();
};