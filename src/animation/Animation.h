#ifndef ANIMATION_H
#define ANIMATION_H

#include <vector>

namespace Animation {
	enum AnimationType {
		kMove,
		kSize,
		kAlpha
	};

	class Animation {
	public:
		Animation() {}
		virtual bool HasReachedDestination() = 0;
		virtual void SetStartPosition(std::vector<float> position) = 0;
		std::vector<float> GetNextPosition();
		virtual std::vector<float> GetDestination() = 0;
		bool HasStarted();
		std::vector<AnimationType> GetType() { return types_; }
	protected:
		virtual void GoToNextPosition() = 0;
		float startX_{0};
		float startY_{0};
		float startWidth_{0};
		float startHeight_{0};
		float currentX_{0};
		float currentY_{0};
		float currentWidth_{0};
		float currentHeight_{0};
		float alpha_{0};
		float finalX_{0};
		float finalY_{0};
		float finalWidth_{0};
		float finalHeight_{0};
		bool hasStarted_{false};
		std::vector<AnimationType> types_;
	};
};
#endif
