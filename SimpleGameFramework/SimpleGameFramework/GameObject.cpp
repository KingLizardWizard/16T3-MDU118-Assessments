#include "stdafx.h"
#include "GameObject.h"


GameObject::GameObject()
{
	type = egotBase;
}


GameObject::~GameObject()
{
}

void GameObject::Render(Gdiplus::Graphics& canvas, const CRect& clientRect)
{

}

void GameObject::SaveAsText(std::ostream& outputStream)
{
	// Stores the values for each variable in a text document
	outputStream	<< type		  << ","
					<< name		  << ","
					<< location.X << "," << location.Y << ","
					<< imageName  << ","
					<< rotation   << ","
					<< xScale	  << "," << yScale; 
	
	SaveAsText_Extra(outputStream);

	outputStream	<< std::endl;
}

void GameObject::SaveAsText_Extra(std::ostream& outputStream)
{

}

void GameObject::LoadFromText_Extra(std::istream& inputStream)
{

}

void GameObject::LoadFromText(std::istream& inputStream)
{
	//Convert Enumeration into an integer then cast it to the enum
	int typeValue;
	inputStream >> typeValue;
	type = (GameObjectType)typeValue;

	char dummyValue;
	//Ignore the comma
	inputStream >> dummyValue;

	//Store what's between both commas into name and delete trailing comma
	std::getline(inputStream, name, ',');

	//Read in the location and remove comma's with dummyValue
	inputStream >> location.X;
	inputStream >> dummyValue;
	inputStream >> location.Y;
	inputStream >> dummyValue;

	//Store what's between both commas into ImageName and delete trailing comma
	std::getline(inputStream, imageName, ',');

	//Read in the rotation
	inputStream >> rotation;
	inputStream >> dummyValue;

	//Read in the X + Y scales 
	inputStream >> xScale;
	inputStream >> dummyValue;
	inputStream >> yScale;

	LoadFromText_Extra(inputStream);
}