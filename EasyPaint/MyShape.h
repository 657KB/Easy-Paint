#pragma once
class MyShape : public CObject
{
public:
	CPoint StartPos;		//起点坐标
	CPoint EndPos;			//结束坐标
	int BorderType;			//边框样式
	int BorderSize;			//边框尺寸
	int FillType;			//填充样式
	COLORREF BorderColor;	//边框颜色
	COLORREF FillColor;		//填充颜色

public:
	MyShape();
	virtual void Draw(CDC *p) = 0;
	virtual void Serialize(CArchive& ar) = 0;
	virtual ~MyShape();
};