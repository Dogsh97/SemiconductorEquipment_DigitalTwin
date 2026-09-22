#pragma once
#include "Wafer.h"
#include "LoadPort.h"
#include "Chamber.h"
#include "Robot.h"
#include "Logger.h"

class EquipmentController {
	private:
		Wafer wafer;
		LoadPort loadPort;
		Chamber chamber;
		Robot robot;
		Logger logger;

	public:
		EquipmentController();
		void Initialize();
		void Start();
		void Stop();
		void Reset();
};