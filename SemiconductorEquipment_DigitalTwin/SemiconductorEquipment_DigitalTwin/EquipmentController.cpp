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
	bool isSucess = loadPort.ReceiveWafer(&wafer);
	if (isSucess) {
		loadPort.LoadComplete();
		robot.Move(1,1,1);
		robot.MoveComplete();
		robot.Pick();
		isSucess = robot.ReceiveWafer(loadPort.GiveWafer());
		if (isSucess) {
			robot.PickComplete();
			robot.Place();
			chamber.Ready();
			chamber.Open();
			isSucess = chamber.ReceiveWafer(robot.GiveWafer());
			if (isSucess) {
				robot.PlaceComplete();
				chamber.Close();
				chamber.Process();
				chamber.ProcessComplete();
				isSucess = robot.ReceiveWafer(chamber.GiveWafer());
				if (isSucess) {
					chamber.Reset();
				}
				else {
					std::cout << "Error";
				}
			}
			else {
				std::cout << "Error";
			}
			
		}
		else {
			std::cout << "Error";
		}
		
	}
	else {
		std::cout << "Error";
	}
	
	
}

void EquipmentController::Stop() {
	// 웨이퍼가 모두 작업 완료 시 || 에러 발생 시
}

void EquipmentController::Reset() {
	// 에러 발생 시 장비 리셋
}