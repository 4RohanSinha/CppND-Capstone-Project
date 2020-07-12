#include "MoveAnimation.h"
#include <iostream>
#include <vector>

Animation::MoveAnimation::MoveAnimation(float endX, float endY): Animation() {
	startX_ = 0;
	startY_ = 0;
	currentX_ = 0;
	currentY_ = 0;
	finalX_ = endX;
	finalY_ = endY;
	slope_ = (startY_ - finalY_)/(startX_ - finalX_);
	intercept_ = startY_ - (slope_*startX_);
	types_.push_back(AnimationType::kMove);
}

void Animation::MoveAnimation::GoToNextPosition() {
	hasStarted_ = true;
	std::vector<float> finalRes;
	if (currentX_ < finalX_) {
		currentX_ += 0.5;
	}
	else if (finalX_ == currentX_)
		return;

	else if (currentX_ > finalX_)
		currentX_ -= 0.5;
	currentY_ = (slope_*currentX_) + intercept_;
}

bool Animation::MoveAnimation::HasReachedDestination() {
	return ((abs(finalX_ - currentX_) < 0.05) && (abs(finalY_ - currentY_) < 0.05));
}

void Animation::MoveAnimation::SetStartPosition(std::vector<float> position) {
	if (!hasStarted_) {
		startX_ = position[0];
		startY_ = position[1];
		currentX_ = position[0];
		currentY_ = position[1];
		slope_ = (currentY_ - finalY_)/(currentX_ - finalX_);
		intercept_ = startY_ - (slope_*startX_);
	}
}

std::vector<float> Animation::MoveAnimation::GetStartCoordinates() {
	std::vector<float> finalRes = {startX_, startY_};
	return finalRes;
}

std::vector<float> Animation::MoveAnimation::GetDestination() {
	std::vector<float> finalRes{finalX_, finalY_};
	return finalRes;
}
