#ifndef MOVEANIMATION_H
#define MOVEANIMATION_H

#include <vector>

class MoveAnimation {
public:
	MoveAnimation(float startX, float startY, float endX, float endY);
	bool HasReachedDestination();
	void SetStartCoordinates(float startX, float startY);
	std::vector<float> GetStartCoordinates();
	std::vector<float> GetNextPoint();
	std::vector<float> GetDestination();
	bool HasStarted();
private:
	float startX_;
	float startY_;
	float currentX_;
	float currentY_;
	float finalX_;
	float finalY_;
	float slope_;
	float intercept_;
	bool hasStarted_{false};
};

#endif
