#include "stdafx.h"
#include "GameObject.h"


GameObject::GameObject()
{
	type = egotBase;
}


GameObject::~GameObject()
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
					<< xScale	  << "," << yScale << std::endl;
}


