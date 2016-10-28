#include "stdafx.h"
#include "Player.h"

Player::Player() :
	GameObject()
{
	type = egotPlayer;
}

Player::~Player()
{
}

//Draws the class specific shape/name/colour
void Player::Render(Gdiplus::Graphics& canvas, const CRect& clientRect)
{
	GameFrameworkInstance.DrawText(canvas, Vector2i(location.X - 55, location.Y - 85), 16, "Arial", "Player", Gdiplus::Color::White);
	GameFrameworkInstance.DrawCircle(canvas, location, 50, true, Gdiplus::Color::DarkGreen);
}

//Saving Object specific variables
void Player::SaveAsText_Extra(std::ostream& outputStream)
{
	outputStream << "," << health;
	outputStream << "," << moveSpeed;
	outputStream << "," << fireRate;
	outputStream << "," << damage;
}

//Loading Object specific variables
void Player::LoadFromText_Extra(std::istream& inputStream)
{
	char dummyChar;
	inputStream >> dummyChar >> health;
	inputStream >> dummyChar >> moveSpeed;
	inputStream >> dummyChar >> fireRate;
	inputStream >> dummyChar >> damage;
}
