#include "Text.h"

Text::Text(std::string text): Node(0, 0), text_(text) {
	textManager_.AddSource(text_);
	textManager_.ConstructRectangle(x, y);
}

Text::Text(std::string text, Font font) : Node(0, 0), text_(text) {
	font_ = font;
	textManager_.AddSource(text_);
	textManager_.AddFont(font);
	textManager_.ConstructRectangle(x, y);
}

Text::Text(std::string text, Font font, float x, float y): Node(x, y), text_(text) {
	font_ = font;
	textManager_.AddSource(text_);
	textManager_.AddFont(font);
	textManager_.ConstructRectangle(x, y);
}

void Text::AssignRenderer(SDL_Renderer* renderer) {
	textManager_.AssignRenderer(renderer);
}

void Text::Render() {
	textManager_.Render();
}

void Text::Clear() {
	textManager_.Clear();
}

void Text::AddFont(Font font) {
	textManager_.AddFont(font);
}

void Text::SetStyle(int ind) {
	textManager_.ChangeByIndex(ind);
}

void Text::AddSource(std::string text) {
	textManager_.AddSource(text);
}

void Text::ConstructRectangle() {
	textManager_.ConstructRectangle(x, y); 
}
