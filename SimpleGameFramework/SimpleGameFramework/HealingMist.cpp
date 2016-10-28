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

void HealingMist::Render(Gdiplus::Graphics& canvas, const CRect& clientRect)
{
	GameFrameworkInstance.DrawCircle(canvas, location, 50, true, Gdiplus::Color::Green);
}

void HealingMist::SaveAsText_Extra(std::ostream& outputStream)
{
	outputStream << "," << healingAmount;
}

void HealingMist::LoadFromText_Extra(std::istream& inputStream)
{
	char dummyChar;
	inputStream >> dummyChar >> healingAmount;
}
