#ifndef MOVEANIMATION_H
#define MOVEANIMATION_H

#include "Animation.h"
#include <vector>
#include <cmath>

namespace Animation {
	class MoveAnimation: public Animation {
	public:
		MoveAnimation(float endX, float endY);
		bool HasReachedDestination();
		void SetStartPosition(std::vector<float> position);
		std::vector<float> GetStartCoordinates();
		std::vector<float> GetDestination();

	protected:
		void GoToNextPosition();

	private:
		float slope_;
		float intercept_;
	};
};
#endif
