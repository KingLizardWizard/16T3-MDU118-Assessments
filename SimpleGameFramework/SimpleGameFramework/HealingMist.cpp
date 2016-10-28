#include "stdafx.h"
#include "HealingMist.h"

HealingMist::HealingMist() :
	GameObject()
{
	type = egotHealingMist;
}

HealingMist::~HealingMist()
{
}

//Draws the class specific shape/name/colour
void HealingMist::Render(Gdiplus::Graphics& canvas, const CRect& clientRect)
{
	GameFrameworkInstance.DrawText(canvas, Vector2i(location.X - 55, location.Y - 80), 16, "Arial", "Healing Mist", Gdiplus::Color::White);
	GameFrameworkInstance.DrawCircle(canvas, location, 50, false, Gdiplus::Color::Green);
}

//Saving Object specific variables
void HealingMist::SaveAsText_Extra(std::ostream& outputStream)
{
	outputStream << "," << healingAmount;
}

//Loading Object specific variables
void HealingMist::LoadFromText_Extra(std::istream& inputStream)
{
	char dummyChar;
	inputStream >> dummyChar >> healingAmount;
}
