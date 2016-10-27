#pragma once

#include <iostream>
#include <string>

enum GameObjectType {
	egotBase,
	egotWall,

	egotNumTypes
};

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

	virtual void SaveAsText(std::ostream& outputStream);
	virtual void LoadFromText(std::istream& inputStream);

	virtual void Render(Gdiplus::Graphics& canvas, const CRect& clientRect);

	bool operator == (const GameObject& rhs)
	{
		return (type == rhs.type) &&
			(location == rhs.location);
	}

	bool operator != (const GameObject& rhs)
	{
		return !(*this == rhs);
	}

protected:
	virtual void SaveAsText_Extra(std::ostream& outputStream);
	virtual void LoadFromText_Extra(std::istream& inputStream);

public:
	// Creates all of the base variables
	GameObjectType type;
	Vector2i location;
	std::string name;
	std::string imageName;
	float rotation;
	float xScale;
	float yScale;

};

