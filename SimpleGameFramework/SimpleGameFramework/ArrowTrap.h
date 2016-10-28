#pragma once
#include "GameObject.h"
class ArrowTrap :
	public GameObject
{
public:
	ArrowTrap();
	virtual ~ArrowTrap();

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
	int damage;
	int fireRate;

};

