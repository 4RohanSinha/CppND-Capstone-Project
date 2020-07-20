#include <iostream>
#include "Mouse.h"

void Mouse::Update() {
	SDL_PumpEvents();
	UpdateCoordinates();
	UpdateButtonClicked();
}

std::vector<int> Mouse::GetCoordinates() {
	Update();
	std::vector<int> res{mouseX_, mouseY_};
	return res;
}

bool Mouse::HasBeenPressed() {
	return (buttonClicked_ != MouseButton::kNone);
}

MouseButton Mouse::GetButtonClicked() {
	Update();
	return buttonClicked_;
}

void Mouse::UpdateCoordinates() {
	SDL_GetMouseState(&mouseX_, &mouseY_);
}

void Mouse::UpdateButtonClicked() {
	if (SDL_GetMouseState(NULL, NULL)) {
		if (SDL_BUTTON(SDL_BUTTON_LEFT))
			buttonClicked_ = MouseButton::kLeft;

		else if (SDL_BUTTON(SDL_BUTTON_RIGHT))
			buttonClicked_ = MouseButton::kRight;
		
		else if (SDL_BUTTON(SDL_BUTTON_MIDDLE))
			buttonClicked_ = MouseButton::kMiddle;
	
	}
	else
		buttonClicked_ = MouseButton::kNone;
	
}
