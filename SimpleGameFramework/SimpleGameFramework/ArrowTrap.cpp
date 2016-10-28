#include "stdafx.h"
#include "ArrowTrap.h"

ArrowTrap::ArrowTrap() :
	GameObject()
{
	type = egotArrowTrap;
}

ArrowTrap::~ArrowTrap()
{
}

void ArrowTrap::Render(Gdiplus::Graphics& canvas, const CRect& clientRect)
{
	GameFrameworkInstance.DrawText(canvas, Vector2i(location.X - 55,location.Y - 70), 16, "Arial", "Arrow Trap", Gdiplus::Color::White);
	GameFrameworkInstance.DrawCircle(canvas, location, 40, true, Gdiplus::Color::Yellow);
}

void ArrowTrap::SaveAsText_Extra(std::ostream& outputStream)
{
	outputStream << "," << damage;
	outputStream << "," << fireRate;
}

void ArrowTrap::LoadFromText_Extra(std::istream& inputStream)
{
	char dummyChar;
	inputStream >> dummyChar >> damage;
	inputStream >> dummyChar >> fireRate;
}
