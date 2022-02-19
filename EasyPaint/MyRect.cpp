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
	//��������,���滭��
	CPen pen, *pOldPen;
	pen.CreatePen(BorderType, BorderSize, BorderColor);
	pOldPen = (CPen*)p->SelectObject(&pen);

	//������ˢ�����滭ˢ
	CBrush brush, *pOldBrush;
	brush.CreateSolidBrush(FillColor);
	pOldBrush = (CBrush*)p->SelectObject(&brush);

	CRect rct(StartPos, EndPos);

	//����ͼ��
	p->Rectangle(rct);

	//ʹ�õ�ǰ���ʼ���ˢ
	p->SelectObject(pOldPen);
	p->SelectObject(pOldBrush);
}

void MyRect::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		//�����ļ�
		ar << StartPos << EndPos;
		ar << BorderColor << BorderType << BorderSize << FillColor;
	}
	else
	{
		//��ȡ�ļ�
		ar >> StartPos >> EndPos;
		ar >> BorderColor >> BorderType >> BorderSize >> FillColor;
	}
}

MyRect::~MyRect()
{
}
