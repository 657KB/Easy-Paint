#pragma once
#include "MyShape.h"

class MyEllipse : public MyShape
{
public:
	MyEllipse();
	MyEllipse(CPoint startPos, CPoint endPos, int borderType, int borderSize, COLORREF borderColor, COLORREF fillColor);
	void Draw(CDC *p);
	void Serialize(CArchive& ar);
	~MyEllipse();
	DECLARE_SERIAL(MyEllipse);	//ÐòÁÐ»¯ÉùÃ÷
};

