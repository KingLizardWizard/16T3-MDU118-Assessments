#include "stdafx.h"
#include "GameInput.h"
#include "GameManager.h"

GameInput& GameInput::Instance()
{
	static GameInput instance;

	return instance;
}

GameInput::GameInput()
{
}

GameInput::~GameInput()
{
}

void GameInput::BeginPlay()
{

}

void GameInput::EndPlay()
{

}

//Use for smooth movement (not tile based)
int smoothAxisH = 0;
int smoothAxisV = 0;
int tileAxisH = 0;
int tileAxisV = 0;
void GameInput::Update(double deltaTime)
{
	// The code below polls individual keys to determine if they are currently down.
	if (GetKeyState('W') & 0x8000)
	{
		--smoothAxisV;
	}
	if (GetKeyState('A') & 0x8000)
	{
		--smoothAxisH;
	}
	if (GetKeyState('S') & 0x8000)
	{
		++smoothAxisV;
	}
	if (GetKeyState('D') & 0x8000)
	{
		++smoothAxisH;
	}

	GameManagerInstance.PlayerInputSmooth(smoothAxisH, smoothAxisV);
}

void GameInput::OnKeyDown(UINT keyCode, UINT repeatCount)
{
	// NOTE: This method will not detect multiple simultaneous key presses.
	// To detect simultaneous presses you must use GetKeyState and check
	// each key of interest.
	switch (keyCode)
	{
	case 'W':
		break;
	case 'A':
		break;
	case 'S':
		break;
	case 'D':
		break;
	case 'Q':
		break;
	case 'E':
		break;
	case 'Y':
		tileAxisV -= 30;
		break;
	case 'G':
		tileAxisH -= 30;
		break;
	case 'H':
		tileAxisV += 30;
		break;
	case 'J':
		tileAxisH += 30;
		break;
	case 'F':
		if (GameManagerInstance.editMode == false)
		{
			GameManagerInstance.editMode = true;
		}
		else 
		{
			GameManagerInstance.editMode = false;
		}
		break;
	case 'C':
		break;

	case VK_LEFT:
		break;
	case VK_RIGHT:
		break;
	case VK_UP:
		break;
	case VK_DOWN:
		break;

	case VK_CONTROL:
		break;
	case VK_SPACE:
		break;
	case VK_SHIFT:
		break;

	case VK_F1:
		break;
	case VK_F2:
		break;
	case VK_F3:
		break;
	case VK_F4:
		break;
	case VK_F5:
		break;
	case VK_F6:
		break;
	case VK_F7:
		break;
	case VK_F8:
		break;
	case VK_F9:
		break;
	case VK_F10:
		break;
	case VK_F11:
		break;
	case VK_F12:
		break;

		GameManagerInstance.PlayerInputTile(tileAxisH, tileAxisV);
	}
}

void GameInput::OnKeyUp(UINT keyCode, UINT repeatCount)
{
	// NOTE: This method will not detect multiple simultaneous key presses.
	// To detect simultaneous presses you must use GetKeyState and check
	// each key of interest.

	switch (keyCode)
	{
	case 'W':
		break;
	case 'A':
		break;
	case 'S':
		break;
	case 'D':
		break;
	case 'Q':
		break;
	case 'E':
		break;
	case 'F':
		break;
	case 'C':
		break;

	case VK_LEFT:
		break;
	case VK_RIGHT:
		break;
	case VK_UP:
		break;
	case VK_DOWN:
		break;

	case VK_CONTROL:
		break;
	case VK_SPACE:
		break;
	case VK_SHIFT:
		break;

	case VK_F1:
		break;
	case VK_F2:
		break;
	case VK_F3:
		break;
	case VK_F4:
		break;
	case VK_F5:
		break;
	case VK_F6:
		break;
	case VK_F7:
		break;
	case VK_F8:
		break;
	case VK_F9:
		break;
	case VK_F10:
		break;
	case VK_F11:
		break;
	case VK_F12:
		break;
	}
}

void GameInput::OnLButtonDown(const Vector2i& point)
{
	DebugLog("OnLButtonDown at " << point.X << "," << point.Y);
}

void GameInput::OnLButtonUp(const Vector2i& point)
{
	DebugLog("OnLButtonUp at " << point.X << "," << point.Y);
}

void GameInput::OnLButtonDblClk(const Vector2i& point)
{
	DebugLog("OnLButtonDblClk at " << point.X << "," << point.Y);
}

void GameInput::OnRButtonDown(const Vector2i& point)
{
	DebugLog("OnRButtonDown at " << point.X << "," << point.Y);
}

void GameInput::OnRButtonUp(const Vector2i& point)
{
	DebugLog("OnRButtonUp at " << point.X << "," << point.Y);
}

void GameInput::OnRButtonDblClk(const Vector2i& point)
{
	DebugLog("OnRButtonDblClk at " << point.X << "," << point.Y);
}

void GameInput::OnMouseMove(const Vector2i& point)
{
}
