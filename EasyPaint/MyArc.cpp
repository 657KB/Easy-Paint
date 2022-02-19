#include "stdafx.h"
#include "MyArc.h"

IMPLEMENT_SERIAL(MyArc, CObject, 1)

MyArc::MyArc()
{
}

MyArc::MyArc(CPoint startPos, CPoint endPos, int borderType, int borderSize, COLORREF borderColor)
{
	StartPos = startPos;
	EndPos = endPos;
	BorderColor = borderColor;
	BorderType = borderType;
	BorderSize = borderSize;
}

void MyArc::Draw(CDC *p)
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
	p->Arc(rct, StartPos, EndPos);

	//使用当前画笔及画刷
	p->SelectObject(pOldPen);
	p->SelectObject(pOldBrush);
}

void MyArc::Serialize(CArchive& ar)
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

MyArc::~MyArc()
{
}
