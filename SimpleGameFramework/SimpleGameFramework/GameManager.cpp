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
	//Load all of the images from the Images Directory and set names to them
	GameFrameworkInstance.LoadImageResource(AppConfigInstance.GetResourcePath("Images/Rock.jpg"), RockImage);

	//Input for the Rock Object
	Rock* rock1 = new Rock;
	rock1->type = egotWall;
	rock1->location = Vector2i(600, 300);
	rock1->name = "Rock";
	rock1->rotation = 1.0f;
	rock1->xScale = 3.0f;
	rock1->yScale = 3.0f;
	rock1->imageName = "RockImage";
	rock1->destructible = true;

	std::ofstream outputFile("objects.csv");

	//Version Number
	outputFile << 2 << std::endl;

	//Number of Objects
	outputFile << 1 << std::endl;

	rock1->SaveAsText(outputFile);
	outputFile.close();

	delete rock1;

	std::ifstream inputFile("objects.csv");
	int versionNumber = 0;
	int numObjects = 1;
	inputFile >> versionNumber;
	inputFile >> numObjects;

	objects.reserve(numObjects);
	for (int index = 0; index < numObjects; ++index)
	{
		Rock* rock2 = new Rock();
		rock2->LoadFromText(inputFile);

		objects.push_back(rock2);
	}
}

void GameManager::EndPlay()
{
	//Iterate over all of the game objects in the Vector
	std::vector<GameObject*>::iterator objectIt;
	for (objectIt = objects.begin(); objectIt != objects.end(); ++objectIt)
	{
		GameObject* objectPtr = *objectIt;
		delete objectPtr;
	}

	//Empty all of the elements out of the Vector
	objects.clear();
}

void GameManager::Update(double deltaTime)
{

}

void GameManager::Render(Gdiplus::Graphics& canvas, const CRect& clientRect)
{
	//Save the current transformation properties of the scene
	Gdiplus::Matrix transform;
	canvas.GetTransform(&transform);

	canvas.ScaleTransform(0.5f, 0.5f);
	canvas.RotateTransform(0.0f);
	//canvas.TranslateTransform(100.0f, 200.0f);

	//Tell all of the GameObjects to render (includes children)
	for (GameObject* objectPtr : objects)
	{
		objectPtr->Render(canvas, clientRect);
	}

	//Restore transformation of scene
	canvas.SetTransform(&transform);

	//ImageWrapper* rockImage = GameFrameworkInstance.GetLoadedImage(RockImage);
    //GameFrameworkInstance.DrawImage(canvas, Vector2i(rock.location.x, 200), rockImage);
}
