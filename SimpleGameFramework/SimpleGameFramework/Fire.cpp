#include "stdafx.h"
#include "Fire.h"

Fire::Fire() :
	GameObject()
{
	type = egotFire;
}

Fire::~Fire()
{
}

void Fire::Render(Gdiplus::Graphics& canvas, const CRect& clientRect)
{
	GameFrameworkInstance.DrawText(canvas, Vector2i(location.X - 55, location.Y - 80), 16, "Arial", "Fire", Gdiplus::Color::White);
	GameFrameworkInstance.DrawCircle(canvas, location, 50, false, Gdiplus::Color::Red);
}

void Fire::SaveAsText_Extra(std::ostream& outputStream)
{
	outputStream << "," << damageAmount;
}

void Fire::LoadFromText_Extra(std::istream& inputStream)
{
	char dummyChar;
	inputStream >> dummyChar >> damageAmount;
}
