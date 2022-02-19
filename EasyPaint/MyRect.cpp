#include "stdafx.h"
#include "MyRect.h"

IMPLEMENT_SERIAL(MyRect, CObject, 1)

MyRect::MyRect()
{
}

MyRect::MyRect(CPoint startPos,CPoint endPos, int borderType, int borderSize, COLORREF borderColor, COLORREF fillColor)
{
	StartPos = startPos;
	EndPos = endPos;
	BorderColor = borderColor;
	BorderType = borderType;
	BorderSize = borderSize;
	FillColor = fillColor;
}

void MyRect::Draw(CDC *p)
{
	//创建画笔,保存画笔
	CPen pen, *pOldPen;
	pen.CreatePen(BorderType, BorderSize, BorderColor);
	pOldPen = (CPen*)p->SelectObject(&pen);

	//创建画刷，保存画刷
	CBrush brush, *pOldBrush;
	brush.CreateSolidBrush(FillColor);
	pOldBrush = (CBrush*)p->SelectObject(&brush);

	CRect rct(StartPos, EndPos);

	//绘制图形
	p->Rectangle(rct);

	//使用当前画笔及画刷
	p->SelectObject(pOldPen);
	p->SelectObject(pOldBrush);
}

void MyRect::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		//保存文件
		ar << StartPos << EndPos;
		ar << BorderColor << BorderType << BorderSize << FillColor;
	}
	else
	{
		//读取文件
		ar >> StartPos >> EndPos;
		ar >> BorderColor >> BorderType >> BorderSize >> FillColor;
	}
}

MyRect::~MyRect()
{
}
