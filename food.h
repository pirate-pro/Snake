#pragma once
#include "Unit.h"
#include "control.h"
class control;
class food :            //继承Unit类
	public unit
{
public:
	food();
	~food();
	void createPos();   //创造食物函数
	COORD coor;
};

