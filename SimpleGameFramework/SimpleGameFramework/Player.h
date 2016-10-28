#pragma once
#include "GameObject.h"
class Player :
	public GameObject
{
public:
	Player();
	virtual ~Player();

	void Render(Gdiplus::Graphics& canvas, const CRect& clientRect);

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

	//Object specific variables
public:
	int health;
	int moveSpeed;
	int fireRate;
	int damage;
};

