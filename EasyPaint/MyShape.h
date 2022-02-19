#pragma once
class MyShape : public CObject
{
public:
	CPoint StartPos;		//�������
	CPoint EndPos;			//��������
	int BorderType;			//�߿���ʽ
	int BorderSize;			//�߿�ߴ�
	int FillType;			//�����ʽ
	COLORREF BorderColor;	//�߿���ɫ
	COLORREF FillColor;		//�����ɫ

public:
	MyShape();
	virtual void Draw(CDC *p) = 0;
	virtual void Serialize(CArchive& ar) = 0;
	virtual ~MyShape();
};