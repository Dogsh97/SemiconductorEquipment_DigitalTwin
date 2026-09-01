#include "EquipmentController.h"

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
}

void EquipmentController::Stop() {
	// 웨이퍼가 모두 작업 완료 시 || 에러 발생 시
}

void EquipmentController::Reset() {
	// 에러 발생 시 장비 리셋
}