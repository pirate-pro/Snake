#pragma once
#include "Unit.h"
#include "control.h"
class control;
class food :            //�̳�Unit��
	public unit
{
public:
	food();
	~food();
	void createPos();   //����ʳ�ﺯ��
	COORD coor;
};

