#pragma once
#include "GameObject.h"
class Rock :
	public GameObject
{
public:
	Rock();
	virtual ~Rock();

	

protected:
	virtual void SaveAsText_Extra(std::ostream& outputStream);
	virtual void LoadFromText_Extra(std::istream& inputStream);

	virtual void Render(Gdiplus::Graphics& canvas, const CRect& clientRect);


public:
	bool destructible;
};

