#include "stdafx.h"
#include "Pickaxe.h"

Pickaxe::Pickaxe() :
	GameObject()
{
	type = egotPickaxe;
}

Pickaxe::~Pickaxe()
{
}

//Draws the class specific shape/name/colour
void Pickaxe::Render(Gdiplus::Graphics& canvas, const CRect& clientRect)
{
	GameFrameworkInstance.DrawText(canvas, Vector2i(location.X - 55, location.Y - 70), 16, "Arial", "Pickaxe", Gdiplus::Color::White);
	GameFrameworkInstance.DrawCircle(canvas, location, 30, true, Gdiplus::Color::LightCyan);
}

//Saving Object specific variables
void Pickaxe::SaveAsText_Extra(std::ostream& outputStream)
{
	outputStream << "," << durability;
	outputStream << "," << maxAmount;
}

//Loading Object specific variables
void Pickaxe::LoadFromText_Extra(std::istream& inputStream)
{
	char dummyChar;
	inputStream >> dummyChar >> durability;
	inputStream >> dummyChar >> maxAmount;
}
