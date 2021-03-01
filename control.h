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
	void drawGameArea();        //绘画游戏区域
	void drawGameInfo();        //绘画游戏信息
	void HideCursor();			//隐藏光标
	void startgame();           //加载游戏
	void game_interface();          //游戏开始界面

};

