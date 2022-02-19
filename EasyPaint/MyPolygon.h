#pragma once
#include "MyShape.h"

using namespace std;

#define pi 3.14

class MyPolygon : public MyShape
{
public:
	int Sides;				//多边形边数
	CPoint Points[20];		//顶点集

public:
	MyPolygon();
	MyPolygon(int sides, CPoint startPos, CPoint endPos, int borderType, int borderSize, COLORREF borderColor, COLORREF fillColor);
	void Draw(CDC *p);
	void Serialize(CArchive& ar);
	~MyPolygon();
	DECLARE_SERIAL(MyPolygon);	//序列化声明

private:
	void getPoints();				//得到顶点集
};

