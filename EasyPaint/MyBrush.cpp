#include "stdafx.h"
#include "MyBrush.h"

IMPLEMENT_SERIAL(MyBrush, CObject, 1)

MyBrush::MyBrush()
{
}

MyBrush::MyBrush(CPoint startPos, int borderType, int borderSize, COLORREF borderColor)
{
	StartPos = startPos;
	BorderColor = borderColor;
	BorderType = borderType;
	BorderSize = borderSize;
}

void MyBrush::setEnd(CPoint endPos)
{
	EndPos = endPos;
}

void MyBrush::Draw(CDC *p)
{
	//创建画笔,保存画笔
	CPen pen, *pOldPen;
	pen.CreatePen(BorderType, BorderSize, BorderColor);
	pOldPen = (CPen*)p->SelectObject(&pen);

	//绘制图形
	p->MoveTo(StartPos);
	p->LineTo(EndPos);

	//使用当前画笔
	p->SelectObject(pOldPen);
}

void MyBrush::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		//保存文件
		ar << StartPos << EndPos;
		ar << BorderColor << BorderType << BorderSize;
	}
	else
	{
		//读取文件
		ar >> StartPos >> EndPos;
		ar >> BorderColor >> BorderType >> BorderSize;
	}
}

MyBrush::~MyBrush()
{
}