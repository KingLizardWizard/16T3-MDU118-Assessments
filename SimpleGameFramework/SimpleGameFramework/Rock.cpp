#include "stdafx.h"
#include "Rock.h"

Rock::Rock() :
	GameObject()
{
	type = egotRock;
}

Rock::~Rock()
{
}

//Draws the class specific shape/name/colour
void Rock::Render(Gdiplus::Graphics& canvas, const CRect& clientRect)
{
	GameFrameworkInstance.DrawText(canvas, Vector2i(location.X - 55, location.Y - 85), 16, "Arial", "Rock", Gdiplus::Color::White);
	GameFrameworkInstance.DrawCircle(canvas, location, 50, true, Gdiplus::Color::SaddleBrown);		
}

//Saving Object specific variables
void Rock::SaveAsText_Extra(std::ostream& outputStream)
{
	outputStream << "," << destructible;
}

//Loading Object specific variables
void Rock::LoadFromText_Extra(std::istream& inputStream)
{
	char dummyChar;
	inputStream >> dummyChar >> destructible;
}