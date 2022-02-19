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
	//��������,���滭��
	CPen pen, *pOldPen;
	pen.CreatePen(BorderType, BorderSize, BorderColor);
	pOldPen = (CPen*)p->SelectObject(&pen);

	//����ͼ��
	p->MoveTo(StartPos);
	p->LineTo(EndPos);

	//ʹ�õ�ǰ����
	p->SelectObject(pOldPen);
}

void MyBrush::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		//�����ļ�
		ar << StartPos << EndPos;
		ar << BorderColor << BorderType << BorderSize;
	}
	else
	{
		//��ȡ�ļ�
		ar >> StartPos >> EndPos;
		ar >> BorderColor >> BorderType >> BorderSize;
	}
}

MyBrush::~MyBrush()
{
}