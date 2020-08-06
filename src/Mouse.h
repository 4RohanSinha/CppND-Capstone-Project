#ifndef MOUSE_H
#define MOUSE_H

#include <vector>
#include "SDL2_headers.h"

enum class MouseButton {
	kLeft,
	kMiddle,
	kRight,
	kNone
};

class Mouse {
public:
	void Update();
	std::vector<int> GetCoordinates();
	bool HasBeenPressed();
	MouseButton GetButtonClicked();
private:
	int mouseX_ = 0;
	int mouseY_ = 0;
	MouseButton buttonClicked_{MouseButton::kNone};

	void UpdateCoordinates();
	void UpdateButtonClicked();
};

#endif
