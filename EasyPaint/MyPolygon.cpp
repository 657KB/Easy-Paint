#include "stdafx.h"
#include "MyPolygon.h"

IMPLEMENT_SERIAL(MyPolygon, CObject, 1)

MyPolygon::MyPolygon()
{
}

MyPolygon::MyPolygon(int sides, CPoint startPos, CPoint endPos, int borderType, int borderSize, COLORREF borderColor, COLORREF fillColor)
{
	Sides = sides;
	StartPos = startPos;
	EndPos = endPos;
	BorderColor = borderColor;
	BorderType = borderType;
	BorderSize = borderSize;
	FillColor = fillColor;
}

void MyPolygon::Draw(CDC *p)
{

	//创建画笔,保存画笔
	CPen pen, *pOldPen;
	pen.CreatePen(BorderType, BorderSize, BorderColor);
	pOldPen = (CPen*)p->SelectObject(&pen);

	//创建画刷，保存画刷
	CBrush brush, *pOldBrush;
	brush.CreateSolidBrush(FillColor);
	pOldBrush = (CBrush*)p->SelectObject(&brush);

	//绘制图形
	getPoints();
	p->Polygon(Points, Sides);

	//使用当前画笔及画刷
	p->SelectObject(pOldPen);
	p->SelectObject(pOldBrush);
}

void MyPolygon::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		//保存文件
		ar << Sides;
		for (int i = 0; i < 20; i++)
			ar << Points[i];
		ar << StartPos << EndPos;
		ar << BorderColor << BorderType << BorderSize << FillColor;
	}
	else
	{
		//读取文件
		ar >> Sides;
		for (int i = 0; i < 20; i++)
			ar >> Points[i];
		ar >> StartPos >> EndPos;
		ar >> BorderColor >> BorderType >> BorderSize >> FillColor;
	}
}

void MyPolygon::getPoints()
{
	//以StartPos为中心求顶点
	CPoint top;
	double radian = (360 / Sides)*pi / 180;
	double x1, x2, y1, y2;
	x1 = StartPos.x;
	x2 = EndPos.x;
	y1 = StartPos.y;
	y2 = EndPos.y;
	int radius = (int)sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	for (int i = 0; i < Sides; i++)
	{
		int x = (int)(radius * sin(radian * i));
		int y = (int)(radius * cos(radian * i));
		top.x = StartPos.x + x;
		top.y = StartPos.y + y;
		Points[i] = top;
	}

}

MyPolygon::~MyPolygon()
{
}
