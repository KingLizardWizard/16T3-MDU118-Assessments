#include "stdafx.h"
#include "CaveBat.h"

CaveBat::CaveBat() :
	GameObject()
{
	type = egotCaveBat;
}

CaveBat::~CaveBat()
{
}

void CaveBat::Render(Gdiplus::Graphics& canvas, const CRect& clientRect)
{
	GameFrameworkInstance.DrawText(canvas, Vector2i(location.X - 55, location.Y - 70), 16, "Arial", "Cave Bat", Gdiplus::Color::White);
	GameFrameworkInstance.DrawCircle(canvas, location, 20, true, Gdiplus::Color::GreenYellow);
}

void CaveBat::SaveAsText_Extra(std::ostream& outputStream)
{
	outputStream << "," << health;
	outputStream << "," << damage;
}

void CaveBat::LoadFromText_Extra(std::istream& inputStream)
{
	char dummyChar;
	inputStream >> dummyChar >> health;
	inputStream >> dummyChar >> damage;
}
