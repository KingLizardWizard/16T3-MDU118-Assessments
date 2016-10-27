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


void Rock::SaveAsText_Extra(std::ostream& outputStream)
{
	outputStream << "," << destructible;
}

void Rock::LoadFromText_Extra(std::istream& inputStream)
{
	char dummyChar;
	inputStream >> dummyChar >> destructible;
}

void Rock::Render(Gdiplus::Graphics& canvas, const CRect& clientRect)
{
	// Save the current transformation of the scene
	Gdiplus::Matrix transform;
	canvas.GetTransform(&transform);

	canvas.TranslateTransform((float)location.X, (float)location.Y);

	GameFrameworkInstance.DrawRectangle(canvas, AABBi(Vector2i(-5, -5), Vector2i(5, 5)), true, Gdiplus::Color::Bisque);

	// Restore the transformation of the scene
	canvas.SetTransform(&transform);
}

