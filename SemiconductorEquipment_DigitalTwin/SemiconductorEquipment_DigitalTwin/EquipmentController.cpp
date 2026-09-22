#include "EquipmentController.h"
#include <iostream>

EquipmentController::EquipmentController()
	:wafer(-1, -1)
{
}

void EquipmentController::Initialize() {
	// 장비 상태 점검
}

void EquipmentController::Start() {
	// 장비 구동 시작
	// 웨이퍼의 개수 만큼 계속 진행
	loadPort.Load();
	logger.Log("loadPort Loading");
	bool isSucess = loadPort.ReceiveWafer(&wafer);
	if (isSucess) {
		loadPort.LoadComplete();
		logger.Log("loadPort LoadComplete");
		robot.Move(1,1,1);
		logger.Log("robot Move");
		robot.MoveComplete();
		logger.Log("robot MoveComplete");
		robot.Pick();
		logger.Log("robot Pick");
		isSucess = robot.ReceiveWafer(loadPort.GiveWafer());
		if (isSucess) {
			robot.PickComplete();
			logger.Log("robot PickComplete");
			robot.Place();
			logger.Log("robot Place");
			chamber.Ready();
			logger.Log("chamber Ready");
			chamber.Open();
			logger.Log("chamber Open");
			isSucess = chamber.ReceiveWafer(robot.GiveWafer());
			if (isSucess) {
				robot.PlaceComplete();
				logger.Log("robot PlaceComplete");
				chamber.Close();
				logger.Log("chamber Close");
				chamber.Process();
				logger.Log("chamber Process");
				chamber.ProcessComplete();
				logger.Log("chamber ProcessComplete");
				isSucess = robot.ReceiveWafer(chamber.GiveWafer());
				if (isSucess) {
					chamber.Reset();
					logger.Log("chamber Reset");
				}
				else {
					logger.Log("Error");
				}
			}
			else {
				logger.Log("Error");
			}
			
		}
		else {
			logger.Log("Error");
		}
		
	}
	else {
		logger.Log("Error");
	}
	
	
}

void EquipmentController::Stop() {
	// 웨이퍼가 모두 작업 완료 시 || 에러 발생 시
}

void EquipmentController::Reset() {
	// 에러 발생 시 장비 리셋
}