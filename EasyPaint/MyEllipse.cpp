#include "stdafx.h"
#include "MyEllipse.h"

IMPLEMENT_SERIAL(MyEllipse, CObject, 1)

MyEllipse::MyEllipse()
{
}

MyEllipse::MyEllipse(CPoint startPos, CPoint endPos, int borderType, int borderSize, COLORREF borderColor, COLORREF fillColor)
{
	StartPos = startPos;
	EndPos = endPos;
	BorderColor = borderColor;
	BorderType = borderType;
	BorderSize = borderSize;
	FillColor = fillColor;
}

void MyEllipse::Draw(CDC *p)
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
	p->Ellipse(rct);

	//ʹ�õ�ǰ���ʼ���ˢ
	p->SelectObject(pOldPen);
	p->SelectObject(pOldBrush);
}

void MyEllipse::Serialize(CArchive& ar)
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

MyEllipse::~MyEllipse()
{
}
