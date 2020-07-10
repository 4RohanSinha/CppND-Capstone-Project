#include "MoveAnimation.h"
#include <iostream>
#include <vector>

MoveAnimation::MoveAnimation(float startX, float startY, float endX, float endY): startX_(startX), startY_(startY), currentX_(startX), currentY_(startY), finalX_(endX), finalY_(endY) {
	slope_ = (startY_ - finalY_)/(startX_ - finalX_);
	intercept_ = startY_ - (slope_*startX_);
}

std::vector<float> MoveAnimation::GetNextPoint() {
	hasStarted_ = true;
	std::vector<float> finalRes;
	if (currentX_ < finalX_) {
		currentX_ += 0.5;
	}
	else if (finalX_ == currentX_)
		return std::vector<float>();

	else if (currentX_ > finalX_)
		currentX_ -= 0.5;
	currentY_ = (slope_*currentX_) + intercept_;
	finalRes.push_back(currentX_);
	finalRes.push_back(currentY_);
	return finalRes;


}

bool MoveAnimation::HasReachedDestination() {
	return ((abs(finalX_ - currentX_) < 0.05) && (abs(finalY_ - currentY_) < 0.05));
}

void MoveAnimation::SetStartCoordinates(float startX, float startY) {
	if (!hasStarted_) {
		startX_ = startX;
		startY_ = startY;
		currentX_ = startX_;
		currentY_ = startY_;
		slope_ = (currentY_ - finalY_)/(currentX_ - finalX_);
		intercept_ = startY_ - (slope_*startX_);
	}
}

std::vector<float> MoveAnimation::GetStartCoordinates() {
	std::vector<float> finalRes = {startX_, startY_};
	return finalRes;
}

std::vector<float> MoveAnimation::GetDestination() {
	std::vector<float> finalRes{finalX_, finalY_};
	return finalRes;
}

bool MoveAnimation::HasStarted() {
	return hasStarted_;
}
