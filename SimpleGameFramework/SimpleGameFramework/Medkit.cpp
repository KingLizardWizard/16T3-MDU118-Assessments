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

void Medkit::Render(Gdiplus::Graphics& canvas, const CRect& clientRect)
{
	GameFrameworkInstance.DrawCircle(canvas, location, 30, true, Gdiplus::Color::Purple);
}

void Medkit::SaveAsText_Extra(std::ostream& outputStream)
{
	outputStream << "," << healingAmount;
	outputStream << "," << maxAmount;
}

void Medkit::LoadFromText_Extra(std::istream& inputStream)
{
	char dummyChar;
	inputStream >> dummyChar >> healingAmount;
	inputStream >> dummyChar >> maxAmount;
}