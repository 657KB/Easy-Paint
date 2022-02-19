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
	p->Arc(rct, StartPos, EndPos);

	//ʹ�õ�ǰ���ʼ���ˢ
	p->SelectObject(pOldPen);
	p->SelectObject(pOldBrush);
}

void MyArc::Serialize(CArchive& ar)
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

MyArc::~MyArc()
{
}
