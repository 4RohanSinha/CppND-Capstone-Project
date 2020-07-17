#include "MoveAnimation.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <cerrno>

//TODO: figure out why the node slows down after repeated calls to Node::Move
//see if the problem involves this class or not
//also fix the direction and speed constructor - it does not work properly.
Animation::MoveAnimation::MoveAnimation(float endX, float endY, float speed): Animation(), speed_(speed) {
	startX_ = 0;
	startY_ = 0;
	currentX_ = 0;
	currentY_ = 0;
	finalX_ = endX;
	finalY_ = endY;
	slope_ = (startY_ - finalY_)/(startX_ - finalX_);

	direction_ = std::atan2((finalY_ - startY_), (finalX_ - startX_)); //within open interval (-pi/2, pi/2)
	intercept_ = startY_ - (slope_*startX_);
	types_.push_back(AnimationType::kMove);
}

//manually divide sin/cos instead of tan to avoid error and instead treat the value as infinity/-infinity
Animation::MoveAnimation::MoveAnimation(float direction, float speed): direction_(direction), speed_(speed), hasDestination_{false} {
	startX_ = 0;
	startY_ = 0;
	slope_ = std::sin(direction_)/std::cos(direction_);
	intercept_ = startY_ - (slope_*startX_);
	types_.push_back(AnimationType::kMove);
}

void Animation::MoveAnimation::GoToNextPosition() {
	hasStarted_ = true;
	if (std::isinf(slope_)) {
		if (std::sin(direction_) < 0)
			currentY_ -= 0.5*speed_;
		else if (std::sin(direction_) > 0)
			currentY_ += 0.5*speed_;
		return;		
	}

	else {
		if (std::cos(direction_) < 0)
			currentX_ -= 0.5*speed_;
		else if (std::cos(direction_) > 0)
			currentX_ += 0.5*speed_;
		else
			return;
		currentY_ = (slope_*currentX_) + intercept_;
	}
}

bool Animation::MoveAnimation::HasReachedDestination() {
	if (!hasDestination_) return false;
	return ((abs(finalX_ - currentX_) < 0.05) && (abs(finalY_ - currentY_) < 0.05));
}

void Animation::MoveAnimation::SetStartPosition(std::vector<float> position) {
	if (!hasStarted_) {
		startX_ = position[0];
		startY_ = position[1];
		currentX_ = position[0];
		currentY_ = position[1];
		if (hasDestination_) { 
			slope_ = (currentY_ - finalY_)/(currentX_ - finalX_);
		
			direction_ = std::atan2((finalY_ - startY_), (finalX_ - startX_)); //within open interval (-pi/2, pi/2)
		}
			
		intercept_ = startY_ - (slope_*startX_);
	}
}

std::vector<float> Animation::MoveAnimation::GetStartCoordinates() {
	std::vector<float> finalRes = {startX_, startY_};
	return finalRes;
}

std::vector<float> Animation::MoveAnimation::GetDestination() {
	if (!hasDestination_) return std::vector<float>();
	std::vector<float> finalRes{finalX_, finalY_};
	return finalRes;
}

void Animation::MoveAnimation::SetSpeed(float newSpeed) {
	speed_ = newSpeed;
}
