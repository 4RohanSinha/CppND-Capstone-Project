#include "Animation.h"

bool Animation::Animation::HasStarted() {
	return hasStarted_;
}

std::vector<float> Animation::Animation::GetNextPosition() {
	GoToNextPosition();
	std::vector<float> finalRes{currentX_, currentY_, currentWidth_, currentHeight_, alpha_};
	return finalRes;
}
