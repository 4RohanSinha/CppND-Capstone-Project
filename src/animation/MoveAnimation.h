#ifndef MOVEANIMATION_H
#define MOVEANIMATION_H

#include "Animation.h"
#include <vector>
#include <cmath>

namespace Animation {
	class MoveAnimation: public Animation {
	public:
		//MoveAnimation(float endX, float endY);
		//default parameters: https://en.cppreference.com/w/cpp/language/default_arguments
		MoveAnimation(float endX, float endY, float speed);
		MoveAnimation(float direction, float speed); //continue forever
		bool HasReachedDestination();
		void SetStartPosition(std::vector<float> position);
		std::vector<float> GetStartCoordinates();
		std::vector<float> GetDestination();
		float GetSpeed() { return speed_; }
		void SetSpeed(float newSpeed);
		bool HasDestination() { return hasDestination_; }
		float GetFinalX() { return finalX_; }
		float GetFinalY() { return finalY_; }

	protected:
		void GoToNextPosition();

	private:
		float slope_;
		float intercept_;
		float speed_{4.0};
		float direction_;
		bool hasDestination_{true};
	};
};
#endif
