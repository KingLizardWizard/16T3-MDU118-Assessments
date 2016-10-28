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

void Pickaxe::Render(Gdiplus::Graphics& canvas, const CRect& clientRect)
{
	GameFrameworkInstance.DrawText(canvas, Vector2i(location.X - 55, location.Y - 70), 16, "Arial", "Pickaxe", Gdiplus::Color::White);
	GameFrameworkInstance.DrawCircle(canvas, location, 30, true, Gdiplus::Color::LightCyan);
}

void Pickaxe::SaveAsText_Extra(std::ostream& outputStream)
{
	outputStream << "," << durability;
	outputStream << "," << maxAmount;
}

void Pickaxe::LoadFromText_Extra(std::istream& inputStream)
{
	char dummyChar;
	inputStream >> dummyChar >> durability;
	inputStream >> dummyChar >> maxAmount;
}
