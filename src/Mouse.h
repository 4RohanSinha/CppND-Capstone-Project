#ifndef MOUSE_H
#define MOUSE_H

#include <vector>
#include <SDL2/SDL.h>

enum class MouseButton {
	kLeft,
	kMiddle,
	kRight,
	kNone
};

class Mouse {
public:
	Mouse() {}
	void Update();
	std::vector<int> GetCoordinates();
	MouseButton GetButtonClicked();
private:
	int mouseX_{0};
	int mouseY_{0};
	MouseButton buttonClicked_{MouseButton::kNone};

	void UpdateCoordinates();
	void UpdateButtonClicked();
};

#endif
