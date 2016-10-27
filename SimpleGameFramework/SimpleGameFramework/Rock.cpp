#include "stdafx.h"
#include "Rock.h"


Rock::Rock() :
	GameObject()
{
	type = egotWall;
}

Rock::~Rock()
{
}

void Rock::Render(Gdiplus::Graphics& canvas, const CRect& clientRect)
{
	GameFrameworkInstance.DrawCircle(canvas, location, 50, true, Gdiplus::Color::SaddleBrown);		
}

void Rock::SaveAsText_Extra(std::ostream& outputStream)
{
	outputStream << "," << destructible;
}

void Rock::LoadFromText_Extra(std::istream& inputStream)
{
	char dummyChar;
	inputStream >> dummyChar >> destructible;
}