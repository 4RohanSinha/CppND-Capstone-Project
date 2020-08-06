#include <iostream>
#include "Font.h"
#include "Node.h"
#include "SDL2_headers.h"

Font::Font(std::string font) : size_(30) {
	SetDefaultColor();
	SetFont(font);
}

Font::Font(std::string font, float size) {
	SetFont(font);
	SetSize(size);
	SetDefaultColor();
}

Font::Font(std::string font, SDL_Color color) : size_(30) {
	SetColor(color);
	SetFont(font);
}

Font::Font(std::string font, float size, SDL_Color color) {
	SetFont(font);
	SetSize(size);
	SetColor(color);
}

//assign the font style to a new font only if it exists in the fonts folder
//otherwise, throw an invalid argument exception 
void Font::SetFont(std::string font) {
	if (FontExists(font))
                font_ = font;
        else
                throw std::invalid_argument("Error: Invalid font: " + font + " is not available.");
}

void Font::SetFont(Font newFont) {
	font_ = newFont.font_;
}
//Set the size of the font by checking if the size is valid or not
void Font::SetSize(float size) {
	//only assign the new size to the private member if it is valid
	if (IsValidSize(size))
		size_ = size;
	//otherwise, throw an invalid argument exception
	else
		throw std::invalid_argument("Error: invalid font size: " + std::to_string(size));
}

void Font::SetColor(SDL_Color color) {
	if (IsValidRGB(color))
		color_ = color;
	else
		throw std::invalid_argument("Error: invalid RGB value");
}

void Font::SetDefaultColor() {
	color_.r = 255;
	color_.g = 255;
	color_.b = 255;
}
//check if font exists in the fonts folder by seeing if the file can be opened
//if it can be, return true because it can be read by other functions
//otherwise return false because it either does not exist or it cannot be read by other functions
bool Font::FontExists(std::string font) {
	std::string fontFile = "../assets/fonts/" + font + ".ttf";
	std::ifstream filestream(fontFile);

	if (filestream.is_open())
		return true;

	return false;
}


//check if font size is positive - if so, return true
//else, return false
bool Font::IsValidSize(float size) {
	return (size > 0.0);
}

//check if RGB value is valid - if so, return true
//else return false

bool Font::IsValidRGB(SDL_Color color) {
	return (IsValidRGBPoint(color.r) && IsValidRGBPoint(color.g) && IsValidRGBPoint(color.b));
}

//returns a unique_ptr
//used in TextManager to generate surface, which is then used for further rendering
std::unique_ptr<TTF_Font, SDL_Deleter> Font::GetTTF() {
	if (!FontExists(font_.c_str()))
		throw std::runtime_error("Error: font " + font_ + " does not exist");
	std::string fontFile = "../assets/fonts/" + font_ + ".ttf";
	return std::unique_ptr<TTF_Font, SDL_Deleter>(TTF_OpenFont(fontFile.c_str(), size_));
	
}

//check if each part of the RGB value if valid - if so, return true
//else return false

bool Font::IsValidRGBPoint(int val) {
	return (val >= 0 && val <= 255);
}
