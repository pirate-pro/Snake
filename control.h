#pragma once
#include <Windows.h>
#include "unit.h"
#include "csnake.h"
#include "food.h"
class food;
class csnake;
class control
{
public:
	COORD m_coor;
public:
	control();
	~control();
	void drawGameArea();        //�滭��Ϸ����
	void drawGameInfo();        //�滭��Ϸ��Ϣ
	void HideCursor();			//���ع��
	void startgame();           //������Ϸ
	void game_interface();          //��Ϸ��ʼ����

};

