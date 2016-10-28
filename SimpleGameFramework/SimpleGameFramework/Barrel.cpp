#include "stdafx.h"
#include "Barrel.h"

Barrel::Barrel() :
	GameObject()
{
	type = egotBarrel;
}

Barrel::~Barrel()
{
}

void Barrel::Render(Gdiplus::Graphics& canvas, const CRect& clientRect)
{
	GameFrameworkInstance.DrawCircle(canvas, location, 65, true, Gdiplus::Color::Blue);
}

void Barrel::SaveAsText_Extra(std::ostream& outputStream)
{
	outputStream << "," << destructible;
}

void Barrel::LoadFromText_Extra(std::istream& inputStream)
{
	char dummyChar;
	inputStream >> dummyChar >> destructible;
}