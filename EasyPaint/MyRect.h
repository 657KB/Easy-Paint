#pragma once
#include "MyShape.h"
class MyRect : public MyShape
{
public:
	MyRect();
	MyRect(CPoint startPos,CPoint endPos, int borderType, int borderSize, COLORREF borderColor, COLORREF fillColor);
	void Draw(CDC *p);
	void Serialize(CArchive& ar);
	~MyRect();
	DECLARE_SERIAL(MyRect);	//ÐòÁÐ»¯ÉùÃ÷
};

