#include "stdafx.h"
#include "GameManager.h"
#include <fstream>

GameManager& GameManager::Instance()
{
	static GameManager instance;

	return instance;
}

GameManager::GameManager()
{
}

GameManager::~GameManager()
{
}

//const char* Image1 = "Image1";
const char* Rock = "Rock";


void GameManager::BeginPlay()
{
	// Load the image file Untitled.png from the Images folder. Give it the unique name of Image1
	//GameFrameworkInstance.LoadImageResource(AppConfigInstance.GetResourcePath("Images/Untitled.png"), Image1);
	GameFrameworkInstance.LoadImageResource(AppConfigInstance.GetResourcePath("Images/Rock.jpg"), Rock);

	GameObject Rock_Setup;
	Rock_Setup.type = egotWall;
	Rock_Setup.location = Vector2i(30, 120);
	Rock_Setup.name = "Rock";
	Rock_Setup.rotation = 1.0f;
	Rock_Setup.xScale = 3.0f;
	Rock_Setup.yScale = 3.0f;
	Rock_Setup.imageName = "Rock";

	std::ofstream outputFile("objects.csv");
	Rock_Setup.SaveAsText(outputFile);
	outputFile.close();

	std::ifstream inputFile("objects.csv");
	GameObject Rock;
	Rock.LoadFromText(inputFile);

	DebugLog("-----");
}

void GameManager::EndPlay()
{

}

void GameManager::Update(double deltaTime)
{

}

void GameManager::Render(Gdiplus::Graphics& canvas, const CRect& clientRect)
{
	/*
	////////////////////////////////////////////////////////////////////////////////
	// Begin example code

	// Save the current transformation of the scene
	Gdiplus::Matrix transform;
	canvas.GetTransform(&transform);

	canvas.ScaleTransform(0.5f, 0.5f);
	canvas.RotateTransform(30.0f);
	canvas.TranslateTransform(200.0f, 200.0f);

	// Render method demonstration (You can remove all of this code)
	GameFrameworkInstance.DrawLine(canvas, Vector2i(200, 200), Vector2i(400, 200), Gdiplus::Color::White);

	GameFrameworkInstance.DrawRectangle(canvas, AABBi(Vector2i(10, 110), Vector2i(100, 200)), false, Gdiplus::Color::White);
	GameFrameworkInstance.DrawRectangle(canvas, AABBi(Vector2i(200, 110), Vector2i(300, 200)), true, Gdiplus::Color::White);

	canvas.SetTransform(&transform);

	GameFrameworkInstance.DrawCircle(canvas, Vector2i(200, 200), 50, false, Gdiplus::Color::White);
	GameFrameworkInstance.DrawCircle(canvas, Vector2i(400, 200), 50, true, Gdiplus::Color::White);

	GameFrameworkInstance.DrawText(canvas, Vector2i(10, 300), 12, "Arial", "Hello World!", Gdiplus::Color::White);

	// Load the image file Untitled.png from the Images folder. Give it the unique name of Image1
	ImageWrapper* image1 = GameFrameworkInstance.GetLoadedImage(Image1);
	GameFrameworkInstance.DrawImage(canvas, Vector2i(400, 400), image1);

	// Restore the transformation of the scene
	canvas.SetTransform(&transform);

	// End example code
	////////////////////////////////////////////////////////////////////////////////
	*/

	ImageWrapper* rock = GameFrameworkInstance.GetLoadedImage(Rock);
	GameFrameworkInstance.DrawImage(canvas, Vector2i(200, 200), rock);
}
