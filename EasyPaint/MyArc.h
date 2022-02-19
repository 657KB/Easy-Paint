#pragma once
#include "MyShape.h"

class MyArc : public MyShape
{
public:
	MyArc();
	MyArc(CPoint startPos, CPoint endPos, int borderType, int borderSize, COLORREF borderColor);
	void Draw(CDC *p);
	void Serialize(CArchive& ar);
	~MyArc();
	DECLARE_SERIAL(MyArc);	//ÐòÁÐ»¯ÉùÃ÷
};

