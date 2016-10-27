#include "stdafx.h"
#include "GameManager.h"
#include "Rock.h"
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

const char* RockImage = "RockImage";


void GameManager::BeginPlay()
{
	// Load the image file Untitled.png from the Images folder. Give it the unique name of Image1
	GameFrameworkInstance.LoadImageResource(AppConfigInstance.GetResourcePath("Images/Rock.jpg"), RockImage);

	Rock* Rock_Setup = new Rock;
	Rock_Setup->type = egotWall;
	Rock_Setup->location = Vector2i(20, 20);
	Rock_Setup->name = "Rock";
	Rock_Setup->rotation = 1.0f;
	Rock_Setup->xScale = 3.0f;
	Rock_Setup->yScale = 3.0f;
	Rock_Setup->imageName = "RockImage";
	Rock_Setup->destructible = true;

	std::ofstream outputFile("objects.csv");
	outputFile << 2 << std::endl;
	outputFile << 1 << std::endl;
	Rock_Setup->SaveAsText(outputFile);
	outputFile.close();

	delete Rock_Setup;

	std::ifstream inputFile("objects.csv");
	int versionNumber = 0;
	int numObjects = 0;
	inputFile >> versionNumber;
	inputFile >> numObjects;

	objects.reserve(numObjects);
	for (int index = 0; index < numObjects; ++index)
	{
		int typeValue;
		inputFile >> typeValue;
		GameObjectType type = (GameObjectType)typeValue;

		GameObject* loadedObjectPtr = nullptr;
		switch (type)
		{
		case egotBase:
			DebugLog("Object has base type. Something is very bad!");
			break;

		case egotWall:
			loadedObjectPtr = new Rock();
			break;
		}
		loadedObjectPtr->LoadFromText(inputFile);

		objects.push_back(loadedObjectPtr);
	}

	Rock* rock1 = new Rock();

	delete rock1;
}

void GameManager::EndPlay()
{
	// iterate over all of the game objects in the list
	std::vector<GameObject*>::iterator objectIt;
	for (objectIt = objects.begin(); objectIt != objects.end(); ++objectIt)
	{
		GameObject* objectPtr = *objectIt;
		delete objectPtr;
	}

	// clear the vector (empty the elements)
	objects.clear();
}

void GameManager::Update(double deltaTime)
{

}

void GameManager::Render(Gdiplus::Graphics& canvas, const CRect& clientRect)
{
	/*
	////////////////////////////////////////////////////////////////////////////////
	// Begin example code

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

	// Restore the transformation of the scene
	canvas.SetTransform(&transform);

	// End example code
	////////////////////////////////////////////////////////////////////////////////
	*/

	// Save the current transformation of the scene
	Gdiplus::Matrix transform;
	canvas.GetTransform(&transform);

	canvas.ScaleTransform(0.5f, 0.5f);
	canvas.RotateTransform(30.0f);
	canvas.TranslateTransform(200.0f, 200.0f);

	// tell all of the game objects to render
	for (GameObject* objectPtr : objects)
	{
		objectPtr->Render(canvas, clientRect);
	}

	// Restore the transformation of the scene
	canvas.SetTransform(&transform);

	//ImageWrapper* rockImage = GameFrameworkInstance.GetLoadedImage(RockImage);
    //GameFrameworkInstance.DrawImage(canvas, Vector2i(rock.location.x, 200), rockImage);
}
