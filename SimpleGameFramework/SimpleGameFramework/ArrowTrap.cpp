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
