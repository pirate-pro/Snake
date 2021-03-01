#include "control.h"

control::control()
{
	HANDLE hOut;
	CONSOLE_SCREEN_BUFFER_INFO scr;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE); /* 获取标准输出句柄 */
	GetConsoleScreenBufferInfo(hOut, &scr);
	m_coor.X = scr.srWindow.Right+1;
	m_coor.Y = scr.srWindow.Bottom+1;
}

control::~control()
{
}
void control::HideCursor()			//隐藏光标
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void control::drawGameArea()
{
	unit::gotoxy(unit::left, unit::up);
	for (int j = 0; j < m_coor.X-7; j++)
	{
		cout << "-";
	}

	for (int i = 0; i < m_coor.Y-5; i++)
	{
		unit::gotoxy(unit::left, unit::up + 1 + i);
		cout << "|";
		unit::gotoxy(m_coor.X - 5, unit::up + 1 + i);
		cout << "|";
	}

	unit::gotoxy(unit::left,m_coor.Y - 1);
	for (int k = 0; k < m_coor.X-7; k++)
	{
		cout << "-";
	}

	unit::gotoxy(unit::left + 1, unit::up + 2);
	for (int i = 0; i < m_coor.X-9; i++)
	{
		cout << "-";
	}
}
void control::drawGameInfo()
{
	unit::gotoxy((m_coor.X-unit::left)/8 , unit::up + 1);

	cout << "游戏名称：贪吃蛇";

	unit::gotoxy((m_coor.X - unit::left) / 8*3, unit::up + 1);

	cout << "编写者：黄彦科";

	unit::gotoxy((m_coor.X - unit::left) / 8*5, unit::up + 1);

	cout << "当前得分";

	unit::gotoxy((m_coor.X - unit::left) / 8*6.5, unit::up + 1);

	cout << "当前关卡";


}
void control::startgame()
{
	food m_food ;
	csnake m_csnake ;
	control c;
	c.game_interface();
	c.HideCursor();
	c.drawGameArea();
	c.drawGameInfo();
	m_csnake.getGamedata();
	m_food.createPos();
	int key = 70;
	//s1.startgame();
	PlaySound(TEXT("bgm.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP); //加入背景音乐
	while (true)
	{
		m_csnake.changeDirection(m_food, key);
		m_csnake.getGamedata();
	}


}
void control::game_interface()	             //游戏开始界面：
{
	system("cls");
	drawGameArea();
	int c = 0;
	unit::gotoxy((m_coor.X - unit::left) / 2-6, unit::up + 1);
	cout << "欢迎来到贪吃蛇游戏！";
	unit::gotoxy(m_coor.X / 2 - 10,  m_coor.Y / 2 - 2);
	cout << "  1.立即开始游戏";
	unit::gotoxy(m_coor.X / 2 - 10, m_coor.Y / 2);
	cout << "  2.游戏说明";
	unit::gotoxy(m_coor.X / 2 - 10, m_coor.Y / 2 + 2);
	cout << "输入序号后按回车选择：";
	cin >> c;

	switch (c)
	{
	case 1:
		system("cls");
		getchar();
		break;
	case 2: system("cls");
		unit::gotoxy(m_coor.X / 2 - 20, m_coor.Y / 2 - 5); cout << "                          玩家使用方向键操控";
		unit::gotoxy(m_coor.X / 2 - 20, m_coor.Y / 2 - 4); cout << "                          蛇可以自由的吃食物。";
		unit::gotoxy(m_coor.X / 2 - 20, m_coor.Y / 2 - 3); cout << "                   同时蛇身随着吃下的食物张长，速度变快";
		unit::gotoxy(m_coor.X / 2 - 20, m_coor.Y / 2 - 2); cout << "   当蛇头撞到蛇身或墙时游戏结束,游戏结束后可选择重新游戏或退出游戏";
		unit::gotoxy(m_coor.X / 2 - 20, m_coor.Y / 2 - 1); cout << "                            最高level为5";
		unit::gotoxy(m_coor.X / 2 - 20, m_coor.Y / 2); cout << "                       ↑-上	↓-下	←-左	→-右";
		getchar();
		unit::gotoxy(m_coor.X / 2 - 20, m_coor.Y / 2 + 2); cout << "                     点击回车重新回到游戏开始界面";
		getchar();
		game_interface();
		break;
	default: 
		unit::gotoxy(m_coor.X / 2 - 10, m_coor.Y / 2 - 2); 
		cout << "输入有误请重新输入!";
		game_interface();
		break;
	}
	return;
}
