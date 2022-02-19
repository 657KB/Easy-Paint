#pragma once
#include "MyShape.h"

using namespace std;

#define pi 3.14

class MyPolygon : public MyShape
{
public:
	int Sides;				//����α���
	CPoint Points[20];		//���㼯

public:
	MyPolygon();
	MyPolygon(int sides, CPoint startPos, CPoint endPos, int borderType, int borderSize, COLORREF borderColor, COLORREF fillColor);
	void Draw(CDC *p);
	void Serialize(CArchive& ar);
	~MyPolygon();
	DECLARE_SERIAL(MyPolygon);	//���л�����

private:
	void getPoints();				//�õ����㼯
};

