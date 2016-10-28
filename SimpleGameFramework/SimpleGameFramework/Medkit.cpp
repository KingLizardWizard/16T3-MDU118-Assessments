#include "stdafx.h"
#include "Medkit.h"

Medkit::Medkit() :
	GameObject()
{
	type = egotMedkit;
}

Medkit::~Medkit()
{
}

//Draws the class specific shape/name/colour
void Medkit::Render(Gdiplus::Graphics& canvas, const CRect& clientRect)
{
	GameFrameworkInstance.DrawText(canvas, Vector2i(location.X - 55, location.Y - 70), 16, "Arial", "Medkit", Gdiplus::Color::White);
	GameFrameworkInstance.DrawCircle(canvas, location, 30, true, Gdiplus::Color::Purple);
}

//Saving Object specific variables
void Medkit::SaveAsText_Extra(std::ostream& outputStream)
{
	outputStream << "," << healingAmount;
	outputStream << "," << maxAmount;
}

//Loading Object specific variables
void Medkit::LoadFromText_Extra(std::istream& inputStream)
{
	char dummyChar;
	inputStream >> dummyChar >> healingAmount;
	inputStream >> dummyChar >> maxAmount;
}
