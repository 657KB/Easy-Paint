#pragma once
#include "MyShape.h"

class MyBrush : public MyShape
{
public:
	MyBrush();
	MyBrush(CPoint startPos, int borderType, int borderSize, COLORREF borderColor);
	void setEnd(CPoint endPos);
	void Draw(CDC *p);
	void Serialize(CArchive& ar);
	~MyBrush();
	DECLARE_SERIAL(MyBrush);	//ÐòÁÐ»¯ÉùÃ÷
};

